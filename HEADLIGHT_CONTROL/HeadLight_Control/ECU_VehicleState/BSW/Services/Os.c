// /**
//  * @file OsekIntro_Example2.c
//  * @author Sarea Alhariri (Sarea.h95@outlook.com)
//  * @brief  Extended task and periodic event setting. 
//  * @version 0.1
//  * @date 2020-08-19
//  *
//  * @copyright Sarea Alhariri - All rights reserved
//  *
//  */

// #include "Rte_VehicleStateSensor.h"
// #include <stdint.h>
// #include <stdbool.h>


//  static uint8_t AppTask_PeriodicExtended_Toggle = 0U ; 
 
//  bool hwinitFlag = false;
//  DeclareTask(AppTask_SensorProcessing);
//  DeclareTask(AppTask_InitHW);
 
 
//  void SystemInit(void)
//  {
//  }
//  int main(void)
//  {
//    StartOS();
//    while(1); /* Should not be executed */
//    return 0;
//  }
 
//  TASK(AppTask_SensorProcessing)
//  { 
//              while(true){
//                      WaitEvent(Ev_SensorUpdate);
//                      ClearEvent(Ev_SensorUpdate);
//                      AppTask_PeriodicExtended_Toggle ^= 1; 
//                    Rte_Ev_ReadSpeedAndSteering();  
//                     Rte_Ev_SendSensorData();  
//              }
//  }
 
//  TASK(AppTask_InitHW)
//  {
//          if (hwinitFlag == false){
//              hwinitFlag = true;
//          }
     
//      TerminateTask(); 
//  }
 