// /**
//  * @file OsekIntro_Example2.c
//  * @author Sarea Alhariri
//  * @brief  Periodic and Aperiodic tasks using OSEK alarms
//  * @version 0.1
//  * @date 2020-08-12
//  *
//  * @copyright Sarea Alhariri - All rights reserved
//  */

//  #include <stdint.h>
//  #include <stdbool.h>
//  #include "os.h"
 
//  static uint8_t inputHL = 0U ; 
//  static uint8_t sentHL = 0U ;
//  static uint8_t controlHL = 0U ;
//  static uint8_t feedbackHL = 0U ;
 
 
 
//  DeclareTask(AppTask_HeadlightControl);
//  DeclareTask(AppTask_InitHW);
//  DeclareTask(AppTask_HeadlightFeedback);
//  DeclareTask(AppTask_HeadlightLogic );
//  DeclareTask(AppTask_HeadlightInput);
 
 
//  void SystemInit(void) {}
 
//  int main(void) {
//      StartOS();
//      while(1); /* Không bao gi? th?c thi du?c */
//  }
 
//  // Task X? lý c?m bi?n v?i s? ki?n
//  TASK(AppTask_HeadlightInput) {
//      while(1){
//      WaitEvent(Ev_HeadlightInputCollect);
//      ClearEvent(Ev_HeadlightInputCollect);
         
//      inputHL ^= 0x1U;  
//          SetEvent(AppTask_HeadlightLogic,Ev_HeadlightInputUpdate);
//      }
//  }
//  TASK(AppTask_HeadlightControl) {
//      while(1){
//      WaitEvent(Ev_HeadlightCommandSent);
//      ClearEvent(Ev_HeadlightCommandSent);
         
//      controlHL ^= 0x1U;  
//          SetEvent(AppTask_HeadlightFeedback,Ev_HeadlightStateUpdate);
//      }
//  }
//  TASK(AppTask_HeadlightLogic) {
//      while(1){
//      WaitEvent(Ev_HeadlightInputUpdate);
//      ClearEvent(Ev_HeadlightInputUpdate);
         
//      sentHL ^= 0x1U;  
//          SetEvent(AppTask_HeadlightControl,Ev_HeadlightCommandSent);
//      }
//  }
//  TASK(AppTask_HeadlightFeedback) {
//      while(1){
//      WaitEvent(Ev_HeadlightStateUpdate);
//      ClearEvent(Ev_HeadlightStateUpdate);
         
//      feedbackHL ^= 0x1U;  
//      }
//  }
//  TASK(AppTask_InitHW)
//  {
 
//      TerminateTask(); 
//  }
 