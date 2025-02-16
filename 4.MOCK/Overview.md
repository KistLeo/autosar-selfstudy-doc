### **Internal Behavior Design for Adaptive Headlight Control System**  
This design will define:  
✅ **Runnables and their functions**  
✅ **Events triggering the runnables**  
✅ **Ports for communication**  
✅ **Runnable-Event Mapping**  

---

## **1. Runnables & Their Functions**  

| **ECU**                  | **SWC**                     | **Runnable**               | **Description** |
|--------------------------|---------------------------|----------------------------|-----------------|
| **Powertrain ECU (PCM)** | **Sensor Processing SWC** | `ReadSpeedAndSteering()`   | Reads vehicle speed and steering angle from ADC. |
| **Powertrain ECU (PCM)** | **Sensor Processing SWC** | `SendSensorData()`         | Sends speed and steering data to Headlight Controller SWC via Sender-Receiver (S/R) port. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC** | `ReceiveSensorData()`      | Receives speed & steering angle data from PCM ECU. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC** | `ReadAmbientLight()`       | Reads ambient light sensor via ADC. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC** | `ComputeHeadlightLogic()`  | Determines headlight state based on speed, steering, and ambient light conditions. |
| **Body Control ECU (BCM)** | **Actuator SWC** | `ControlHeadlights()` | Switches ON/OFF headlights and adjusts beam angle using PWM & DIO. |

---

## **2. Events Triggering the Runnables**  

| **Runnable**             | **Event Type**       | **Trigger Condition** |
|--------------------------|---------------------|-----------------------|
| `ReadSpeedAndSteering()`  | **Timing Event**    | Every **100ms**, fetches data from ADC. |
| `SendSensorData()`        | **Data Received Event** | After `ReadSpeedAndSteering()` fetches data, it sends data via RTE. |
| `ReceiveSensorData()`     | **Data Received Event** | Triggered when `SendSensorData()` sends new values. |
| `ReadAmbientLight()`      | **Timing Event**    | Every **100ms**, reads ambient light sensor. |
| `ComputeHeadlightLogic()` | **Data Received Event** | Runs when **sensor data (speed, steering, ambient light) updates**. |
| `ControlHeadlights()`     | **Data Received Event** | Runs when new headlight control commands are available from `ComputeHeadlightLogic()`. |

---

## **3. Port Design for Communication**  

### **Sender-Receiver (S/R) Ports**  
| **Sending SWC**            | **Receiving SWC**       | **Port Name** | **Data Type** |
|----------------------------|------------------------|--------------|--------------|
| Sensor Processing SWC (PCM) | Headlight Controller SWC (BCM) | `SpeedAndSteeringData` | Struct `{float speed, float steering_angle}` |
| Headlight Controller SWC (BCM) | Actuator SWC (BCM) | `HeadlightCommand` | Enum `{LOW_BEAM, HIGH_BEAM, OFF, ADAPTIVE}` |

### **Client-Server (C/S) Ports (for Direct Requests)**  
| **Client SWC** | **Server SWC** | **Port Name** | **Service Provided** |
|--------------|--------------|-------------|------------------|
| Headlight Controller SWC (BCM) | Sensor Processing SWC (PCM) | `GetVehicleSpeed()` | Fetches latest vehicle speed data. |
| Actuator SWC (BCM) | Headlight Controller SWC (BCM) | `GetHeadlightState()` | Gets current headlight logic result. |

---

## **4. Runnable Allocation to Ports**  

| **Runnable**              | **Uses Port(s)** |
|---------------------------|-----------------|
| `ReadSpeedAndSteering()`  | Reads from **ADC** |
| `SendSensorData()`        | Writes to **S/R Port: SpeedAndSteeringData** |
| `ReceiveSensorData()`     | Reads from **S/R Port: SpeedAndSteeringData** |
| `ReadAmbientLight()`      | Reads from **ADC** |
| `ComputeHeadlightLogic()` | Reads from **S/R Port: SpeedAndSteeringData**, **ADC (ambient light)** |
| `ControlHeadlights()`     | Reads from **S/R Port: HeadlightCommand**, **Controls DIO & PWM** |

---

## **Final Execution Flow**
```
[Powertrain ECU]
  - (Every 100ms) ReadSpeedAndSteering() -> Fetch ADC data
  - SendSensorData() -> Sends speed & steering data via RTE

[Body Control ECU]
  - ReceiveSensorData() -> Gets speed & steering angle
  - ReadAmbientLight() -> Reads ambient light level (ADC)
  - ComputeHeadlightLogic() -> Decides beam level
  - ControlHeadlights() -> Adjusts lights (PWM, DIO)
```

---

### **Next Steps**
✅ Define **ARXML configurations** for ports, events, and runnables.  
✅ Implement **MCAL code for ADC, DIO, and PWM**.  
