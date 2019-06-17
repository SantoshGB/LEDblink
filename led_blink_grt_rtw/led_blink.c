/*
 * led_blink.c
 *
 * Code generation for model "led_blink".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Jun 17 11:39:32 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "led_blink.h"
#include "led_blink_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define led_blink_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define led_blink_IN_OFF               ((uint8_T)1U)
#define led_blink_IN_ON                ((uint8_T)2U)

/* Block states (auto storage) */
DW_led_blink_T led_blink_DW;

/* Real-time model */
RT_MODEL_led_blink_T led_blink_M_;
RT_MODEL_led_blink_T *const led_blink_M = &led_blink_M_;

/* Model step function */
void led_blink_step(void)
{
  /* Chart: '<Root>/Chart' */
  /* Gateway: Chart */
  /* During: Chart */
  //if (led_blink_DW.is_active_c3_led_blink == 0U) 
    if(!(digitalRead(led_blink_DW.is_active_c3_led_blink)))
  {
    /* Entry: Chart */
    led_blink_DW.is_active_c3_led_blink = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:12' */
    //led_blink_DW.is_c3_led_blink = led_blink_IN_ON;
    digitalWrite (led_blink_DW.is_c3_led_blink , 1);

    /* Entry 'ON': '<S1>:6' */
  } 
    //else if (led_blink_DW.is_c3_led_blink != led_blink_IN_OFF) 
     else if(digitalRead(led_blink_DW.is_active_c3_led_blink))
    {
    /* During 'ON': '<S1>:6' */
    /* Transition: '<S1>:10' */
    /* LED_off */
    //led_blink_DW.is_c3_led_blink = led_blink_IN_OFF;
      digitalWrite (led_blink_DW.is_c3_led_blink , 0);

    /* Entry 'OFF': '<S1>:8' */
  } else {
    /* During 'OFF': '<S1>:8' */
  }

  /* End of Chart: '<Root>/Chart' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(led_blink_M->rtwLogInfo, (&led_blink_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(led_blink_M)!=-1) &&
        !((rtmGetTFinal(led_blink_M)-led_blink_M->Timing.taskTime0) >
          led_blink_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(led_blink_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++led_blink_M->Timing.clockTick0)) {
    ++led_blink_M->Timing.clockTickH0;
  }

  led_blink_M->Timing.taskTime0 = led_blink_M->Timing.clockTick0 *
    led_blink_M->Timing.stepSize0 + led_blink_M->Timing.clockTickH0 *
    led_blink_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void led_blink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)led_blink_M, 0,
                sizeof(RT_MODEL_led_blink_T));
  rtmSetTFinal(led_blink_M, 10.0);
  led_blink_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    led_blink_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(led_blink_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(led_blink_M->rtwLogInfo, (NULL));
    rtliSetLogT(led_blink_M->rtwLogInfo, "tout");
    rtliSetLogX(led_blink_M->rtwLogInfo, "");
    rtliSetLogXFinal(led_blink_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(led_blink_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(led_blink_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(led_blink_M->rtwLogInfo, 0);
    rtliSetLogDecimation(led_blink_M->rtwLogInfo, 1);
    rtliSetLogY(led_blink_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(led_blink_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(led_blink_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&led_blink_DW, 0,
                sizeof(DW_led_blink_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(led_blink_M->rtwLogInfo, 0.0, rtmGetTFinal
    (led_blink_M), led_blink_M->Timing.stepSize0, (&rtmGetErrorStatus
    (led_blink_M)));

  /* user code (Initialize function Body) */
  pinMode(0,OUTPUT);
  pinMode(1,INPUT);
  pullUpDnControl(PUD_UP);

  /* SystemInitialize for Chart: '<Root>/Chart' */
  led_blink_DW.is_active_c3_led_blink = 0U;
  led_blink_DW.is_c3_led_blink = led_blink_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void led_blink_terminate(void)
{
  /* (no terminate code required) */
}
