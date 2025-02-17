### **Internal Behavior Design for Adaptive Headlight Control System**  
---

## **1. Runnables & Their Functions**  

| **ECU**                  | **SWC**                     | **Runnable**               | **Description** |
|--------------------------|---------------------------|----------------------------|-----------------|
| **Powertrain ECU (PCM)** | **Sensor Processing SWC** | `ReadSpeedAndSteering()`   | Reads vehicle speed and steering angle from ADC. |
| **Powertrain ECU (PCM)** | **Sensor Processing SWC** | `SendSensorData()`         | Sends speed and steering data to Headlight Controller SWC via Sender-Receiver (S/R) port. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC (Left & Right)** | `ReceiveSensorData()`      | Receives speed & steering angle data from PCM ECU. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC (Left & Right)** | `ReadAmbientLight()`       | Reads ambient light sensor via ADC. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC (Left & Right)** | `ReadCameraData()`        | Reads object detection data from Camera ADAS. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC (Left & Right)** | `ComputeHeadlightLogic()`  | Determines headlight state based on speed, steering, ambient light, rain, and traffic detection conditions. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC (Left & Right)** | `SendHeadlightCommand()` | Sends computed headlight control command to Actuator SWC. |
| **Body Control ECU (BCM)** | **Actuator SWC (Left & Right)** | `ReceiveHeadlightCommand()` | Receives headlight control command from Headlight Controller SWC. |
| **Body Control ECU (BCM)** | **Actuator SWC (Left & Right)** | `ControlHeadlights()` | Switches ON/OFF headlights and adjusts beam angle using PWM & DIO. |
| **Body Control ECU (BCM)** | **Actuator SWC (Left & Right)** | `SendHeadlightState()` | Sends back the current headlight state to the Headlight Controller SWC. |

---

## **2. Events Triggering the Runnables**  

| **Runnable**             | **Event Type**       | **Trigger Condition** |
|--------------------------|---------------------|-----------------------|
| `ReadSpeedAndSteering()`  | **Timing Event**    | Every **100ms**, fetches data from ADC. |
| `SendSensorData()`        | **Data Received Event** | After `ReadSpeedAndSteering()` fetches data, it sends data via RTE. |
| `ReceiveSensorData()`     | **Data Received Event** | Triggered when `SendSensorData()` sends new values. |
| `ReadAmbientLight()`      | **Timing Event**    | Every **100ms**, reads ambient light sensor. |
| `ReadCameraData()`        | **Data Received Event** | Triggered when new camera detection data is available. |
| `ComputeHeadlightLogic()` | **Data Received Event** | Runs when **sensor data (speed, steering, ambient light, rain, traffic detection) updates**. |
| `SendHeadlightCommand()`  | **Data Received Event** | Runs when `ComputeHeadlightLogic()` determines a headlight change is needed. |
| `ReceiveHeadlightCommand()` | **Data Received Event** | Runs when a new headlight command is received. |
| `ControlHeadlights()`     | **Data Received Event** | Runs when new headlight control commands are available from `ComputeHeadlightLogic()`. |
| `SendHeadlightState()`    | **Timing Event**    | Every **500ms**, sends the latest headlight state to Headlight Controller SWC. |

---

## **3. Port Design for Communication**  

### **Sender-Receiver (S/R) Ports**  
| **Sending SWC**            | **Receiving SWC**       | **Port Name** | **Data Type** |
|----------------------------|------------------------|--------------|--------------|
| Sensor Processing SWC (PCM) | Headlight Controller SWC (BCM) | `SpeedAndSteeringData` | Struct `{float speed, float steering_angle}` |
| Camera ADAS (MCAL) | Headlight Controller SWC (BCM) | `TrafficDetection` | Struct `{bool vehicleDetected, float distance}` |
| Headlight Controller SWC (BCM) | Actuator SWC (BCM) | `HeadlightCommand_Left` | Enum `{LOW_BEAM, HIGH_BEAM, OFF, ADAPTIVE}` |
| Headlight Controller SWC (BCM) | Actuator SWC (BCM) | `HeadlightCommand_Right` | Enum `{LOW_BEAM, HIGH_BEAM, OFF, ADAPTIVE}` |

### **Client-Server (C/S) Ports (for Direct Requests)**  
| **Client SWC** | **Server SWC** | **Port Name** | **Service Provided** |
|--------------|--------------|-------------|------------------|
| Headlight Controller SWC (BCM) | MCAL ADC Driver (Ambient Light Sensor) | `GetAmbientLight()` | Fetches the latest ambient light data. |
| Actuator SWC (BCM) | Headlight Controller SWC (BCM) | `GetHeadlightState()` | Gets current headlight logic result. |
| Actuator SWC (BCM) | MCAL DIO Driver | `SetHeadlightState()` | Controls ON/OFF state of headlights. |
| Actuator SWC (BCM) | MCAL PWM Driver | `SetBeamAngle()` | Adjusts beam angle of headlights. |

---

## **4. Runnable Allocation to Ports**  

| **Runnable**              | **Uses Port(s)** |
|---------------------------|-----------------|
| `ReadSpeedAndSteering()`  | Reads from **ADC** |
| `SendSensorData()`        | Writes to **S/R Port: SpeedAndSteeringData** |
| `ReceiveSensorData()`     | Reads from **S/R Port: SpeedAndSteeringData** |
| `ReadAmbientLight()`      | Reads from **C/S Port: GetAmbientLight()** |
| `ReadCameraData()`        | Reads from **S/R Port: TrafficDetection** |
| `ComputeHeadlightLogic()` | Reads from **S/R Ports: SpeedAndSteeringData, RainData, TrafficDetection**, **C/S Port: GetAmbientLight()** |
| `SendHeadlightCommand()`  | Writes to **S/R Ports: HeadlightCommand_Left, HeadlightCommand_Right** |
| `ReceiveHeadlightCommand()` | Reads from **S/R Ports: HeadlightCommand_Left, HeadlightCommand_Right** |
| `ControlHeadlights()`     | Reads from **S/R Port: HeadlightCommand**, **Uses C/S Ports: SetHeadlightState(), SetBeamAngle()** |
| `SendHeadlightState()`    | Writes to **C/S Port: GetHeadlightState()** |

---

## **Final Execution Flow**
```
[Powertrain ECU]
  - (Every 100ms) ReadSpeedAndSteering() -> Fetch ADC data
  - SendSensorData() -> Sends speed & steering data via RTE

[Body Control ECU]
  - ReceiveSensorData() -> Gets speed & steering angle
  - ReadAmbientLight() -> Reads ambient light level (ADC)
  - ReadRainSensor() -> Reads rain data
  - ReadCameraData() -> Detects vehicles
  - ComputeHeadlightLogic() -> Decides beam level
  - SendHeadlightCommand() -> Sends control signal to Actuator SWC
  - ControlHeadlights() -> Adjusts lights (PWM, DIO)
  - SendHeadlightState() -> Updates headlight state
```

---
