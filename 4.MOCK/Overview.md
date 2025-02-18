### **Internal Behavior Design for Adaptive Headlight Control System**  
---

## **1. Runnables & Their Functions**  

| **ECU**                  | **SWC**                     | **Runnable**               | **Description** |
|--------------------------|---------------------------|----------------------------|-----------------|
| **Powertrain ECU (PCM)** | **Sensor Processing SWC** | `ReadSpeedAndSteering()`   | Reads vehicle speed and steering angle from ADC. |
| **Powertrain ECU (PCM)** |                           | `SendSensorData()`         | Sends speed and steering data to Headlight Controller SWC via Sender-Receiver (S/R) port. |
| **Body Control ECU (BCM)** | **Headlight Controller SWC (Left & Right)** | `ReceiveSensorData()`      | Receives speed & steering angle data from PCM ECU. |
| **Body Control ECU (BCM)** |                                             | `ReadAmbientLight()`       | Reads ambient light sensor via ADC. |
| **Body Control ECU (BCM)** |                                             | `ReadCameraData()`        | Reads object detection data from Camera ADAS. |
| **Body Control ECU (BCM)** |                                             | `ComputeHeadlightLogic()`  | Determines headlight state based on speed, steering, ambient light and traffic detection conditions. |
| **Body Control ECU (BCM)** |                                             | `SendHeadlightCommand()` | Sends computed headlight control command to Actuator SWC. |
| **Body Control ECU (BCM)** | **Actuator SWC (Left & Right)** | `ReceiveHeadlightCommand()` | Receives headlight control command from Headlight Controller SWC. |
| **Body Control ECU (BCM)** |                                 | `ControlHeadlights()` | Switches ON/OFF headlights and adjusts beam angle using PWM & DIO. |
| **Body Control ECU (BCM)** |                                 | `SendHeadlightState()` | Sends back the current headlight state to the Headlight Controller SWC. |

---

## **2. Events Triggering the Runnables**  

### **Event Table for Adaptive Headlight Control System**  
The following table maps the **runnables** in the system to their respective **ECUs, event types, and trigger conditions**.

---

### **Event Table**
| **Runnable**                | **ECU**                    | **Event Type**                         | **Trigger Condition** |
|-----------------------------|---------------------------|----------------------------------------|-----------------------|
| `ReadSpeedAndSteering()`    | **VehicleStateSensor SWC**    | **Timing Event**                      | Every **100ms**, read speed & steering angle from sensors. |
| `SendSensorData()`          | **VehicleStateSensor SWC**    | **Data Send Complete Event**          | After `ReadSpeedAndSteering()` fetches data, send it to Headlight Controller SWC. |
| `ReceiveSensorData()`       | **Headlight Controller SWC** | **Data Receive Event**              | Triggered when new speed & steering data is received from VehicleStateSensor SWC. |
| `ReadAmbientLight()`        | **Headlight Controller SWC** | **Timing Event** / **Internal Trigger Event** | Every **100ms** or when there is a significant change in ambient light. |
| `ReadCameraData()`          | **Headlight Controller SWC** | **Data Receive Event**              | Triggered when Camera ADAS detects an object or vehicle. |
| `ComputeHeadlightLogic()`   | **Headlight Controller SWC** | **Data Received Event** / **Mode Switch Event** | Runs when sensor data updates or when a mode switch occurs. |
| `SendHeadlightCommand()`    | **Headlight Controller SWC** | **Data Write Complete Event**       | Activated when `ComputeHeadlightLogic()` determines a headlight change is needed. |
| `ReceiveHeadlightCommand()` | **Actuator SWC**          | **Data Receive Event**               | Triggered when a new headlight command is received from the Headlight Controller SWC. |
| `ControlHeadlights()`       | **Actuator SWC**          | **Data Received Event** / **Mode Switch Event** | Runs when a new control command is received or when switching modes (DRL, Low Beam, High Beam, Adaptive). |
| `SendHeadlightState()`      | **Actuator SWC**          | **Timing Event**                     | Every **500ms**, sends the latest headlight status back to the Headlight Controller SWC. |
| `FailSafeTrigger()`         | **Headlight Controller SWC** | **Mode Manager Error Event** / **Data Receive Error Event** | Activated when a sensor fails or data cannot be received from input sources. |
| `ModeSwitchEvent()`         | **Headlight Controller SWC** | **Mode Switch Event**               | Triggered when switching between headlight modes (DRL ↔ Low Beam ↔ High Beam ↔ Adaptive). |
| `ModeSwitchAck()`           | **Headlight Controller SWC** | **Mode Switch Ack Event**           | Triggered when the system successfully changes the headlight mode. |

---

### **Explanation of Event Types**
- **Timing Event**: Used for tasks that execute at fixed intervals (e.g., reading sensor data every 100ms).
- **Data Events**: Used for communication between SWCs, including sending and receiving sensor data or control commands.
- **Mode Events**: Handle mode transitions, including switching headlight modes, detecting mode errors, and acknowledging mode changes.
- **Fail-Safe Mechanism**: Triggered when there is a sensor failure or when the system cannot execute a control action.

---

### **Summary of Event Flow**
1. **VehicleStateSensor SWC** reads speed & steering sensor data (**Timing Event**).
2. The data is sent to **Headlight Controller SWC** (**Data Send Complete Event**).
3. **Headlight Controller SWC** receives the data (**Data Receive Event**) and updates inputs from **Ambient Light Sensor** and **Camera Sensor**.
4. **ComputeHeadlightLogic()** processes the data and determines the headlight state (**Mode Switch Event** if needed).
5. The computed headlight command is sent to **Actuator SWC** (**Data Write Complete Event**).
6. **Actuator SWC** receives the command, adjusts headlights, and sends back the current state (**Data Receive Event** + **Timing Event**).
7. If a sensor or communication failure occurs, **FailSafeTrigger()** is activated to ensure system safety (**Mode Manager Error Event**).

---


---



## **Final Execution Flow**
```
[Powertrain ECU]
  - (Every 100ms) ReadSpeedAndSteering() -> Fetch ADC data
  - SendSensorData() -> Sends speed & steering data via CAN

[Body Control ECU]
  - ReceiveSensorData() -> Gets speed & steering angle
  - ReadAmbientLight() -> Reads ambient light level (ADC)
  - ReadCameraData() -> Detects vehicles
  - ComputeHeadlightLogic() -> Decides beam level
  - SendHeadlightCommand() -> Sends control signal to Actuator SWC
  - ControlHeadlights() -> Adjusts lights (PWM, DIO)
  - SendHeadlightState() -> Updates headlight state
```

---
