/**
 * @file OsekIntro_Example2.c
 * @author Sarea Alhariri
 * @brief  Periodic and Aperiodic tasks using OSEK alarms
 * @version 0.1
 * @date 2020-08-12
 *
 * @copyright Sarea Alhariri - All rights reserved
 */

 #include <stdint.h>
 #include <stdbool.h>
 #include "os.h"
 #include "Rte_HeadlightActuator.h"
 #include "../RTE/Rte_HeadlightController.h"
 
 static uint8_t inputHL = 0U ; 
 static uint8_t sentHL = 0U ;
 static uint8_t controlHL = 0U ;
 static uint8_t feedbackHL = 0U ;
 
 static uint16 ambient_check = 0U;
 static uint8 speed_check = 0U;
 static sint16 angle_check = 0U;
 
 DeclareTask(AppTask_HeadlightControl);
 DeclareTask(AppTask_InitHW);
 DeclareTask(AppTask_HeadlightFeedback);
 DeclareTask(AppTask_HeadlightLogic );
 DeclareTask(AppTask_HeadlightInput);
 
 
 void SystemInit(void) {}
 
 int main(void) {
     StartOS();
     while(1); /* Không bao gi? th?c thi du?c */
 }
 
 // Task X? lý c?m bi?n v?i s? ki?n
 TASK(AppTask_HeadlightInput) { //1
     while(1){
     WaitEvent(Ev_HeadlightInputCollect);
     ClearEvent(Ev_HeadlightInputCollect);
    RTE_Ev_ReadAmbientSensor(&ambient_check);
    RTE_Ev_ReadSpeedData(&speed_check);
    RTE_Ev_ReadSteeringAngleData(&angle_check);
    inputHL ^= 0x1U;  
         SetEvent(AppTask_HeadlightLogic,Ev_HeadlightInputUpdate);
     }
 }
 TASK(AppTask_HeadlightControl) { //3
     while(1){
     WaitEvent(Ev_HeadlightCommandSent);
     ClearEvent(Ev_HeadlightCommandSent);
    RTE_Ev_ControlHeadlight();        
     controlHL ^= 0x1U;  
         SetEvent(AppTask_HeadlightFeedback,Ev_HeadlightStateUpdate);
     }
 }
 TASK(AppTask_HeadlightLogic) { //2
     while(1){
     WaitEvent(Ev_HeadlightInputUpdate);
     ClearEvent(Ev_HeadlightInputUpdate);
    RTE_Ev_ComputeHeadlightLogic();        
     sentHL ^= 0x1U;  
         SetEvent(AppTask_HeadlightControl,Ev_HeadlightCommandSent);
     }
 }
 TASK(AppTask_HeadlightFeedback) { //khong dung
     while(1){
     WaitEvent(Ev_HeadlightStateUpdate);
     ClearEvent(Ev_HeadlightStateUpdate);
    RTE_Ev_SendHeadlightState();  
     feedbackHL ^= 0x1U;  
     }
 }
 TASK(AppTask_InitHW)
 {
 
     TerminateTask(); 
 }
 