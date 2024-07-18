/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: open_loop.h
 *
 * Code generated for Simulink model 'open_loop'.
 *
 * Model version                  : 1.66
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jul 17 14:46:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_open_loop_h_
#define RTW_HEADER_open_loop_h_
#ifndef open_loop_COMMON_INCLUDES_
#define open_loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "soc_stm_encoder.h"
#include "MW_AnalogIn.h"
#endif                                 /* open_loop_COMMON_INCLUDES_ */

#include "open_loop_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T u;                            /* '<Root>/u' */
  real_T RateTransition;               /* '<Root>/Rate Transition' */
  real_T torqueGain;                   /* '<S4>/torqueGain' */
  real_T Gain1;                        /* '<S4>/Gain1' */
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T y;                            /* '<Root>/sign' */
  real_T ref;                          /* '<S5>/readRef' */
  real_T AnalogInput1;                 /* '<S5>/Analog Input1' */
  real_T y_h;                          /* '<S4>/readCurrent' */
  real_T y_hat_g;                      /* '<S4>/firstOrderLagFilter' */
  real_T AnalogInput2;                 /* '<S4>/Analog Input2' */
  real_T speed;                        /* '<Root>/getSpeedDelta' */
  real_T position;                     /* '<Root>/getPosition' */
  uint16_T QudratureEncoder_o1;        /* '<Root>/Qudrature Encoder' */
} B_open_loop_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  soc_stm_QEP_open_loop_T obj;         /* '<Root>/Qudrature Encoder' */
  mbed_AnalogInput_open_loop_T obj_l;  /* '<S5>/Analog Input1' */
  mbed_AnalogInput_open_loop_T obj_b;  /* '<S4>/Analog Input2' */
  mbed_DigitalWrite_open_loop_T obj_p; /* '<Root>/EN_A' */
  mbed_PWMOutput_open_loop_T obj_g;    /* '<Root>/IN2A' */
  mbed_PWMOutput_open_loop_T obj_j;    /* '<Root>/IN1A' */
  real_T Delay6_DSTATE;                /* '<S4>/Delay6' */
  real_T Delay5_DSTATE;                /* '<S4>/Delay5' */
  real_T Delay6_DSTATE_d;              /* '<S5>/Delay6' */
  real_T Delay5_DSTATE_i;              /* '<S5>/Delay5' */
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  uint16_T Delay_DSTATE;               /* '<Root>/Delay' */
  uint8_T is_active_c2_open_loop;      /* '<Root>/sign' */
  uint8_T is_active_c10_open_loop;     /* '<S5>/readRef' */
  uint8_T is_active_c9_open_loop;      /* '<S5>/firstOrderLagFilter' */
  uint8_T is_active_c8_open_loop;      /* '<S4>/readCurrent' */
  uint8_T is_active_c7_open_loop;      /* '<S4>/firstOrderLagFilter' */
  uint8_T is_active_c1_open_loop;      /* '<Root>/getTicksDelta' */
  uint8_T is_active_c3_open_loop;      /* '<Root>/getSpeedDelta' */
  uint8_T is_active_c5_open_loop;      /* '<Root>/getPosition' */
} DW_open_loop_T;

/* Parameters (default storage) */
struct P_open_loop_T_ {
  real_T readCurrentSensor_alpha;     /* Mask Parameter: readCurrentSensor_alpha
                                       * Referenced by: '<S4>/Constant2'
                                       */
  real_T readPotentiometer_alpha;     /* Mask Parameter: readPotentiometer_alpha
                                       * Referenced by: '<S5>/Constant2'
                                       */
  real_T QudratureEncoder_SampleTime;  /* Expression: 0.005
                                        * Referenced by: '<Root>/Qudrature Encoder'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: 0.005/20
                                        * Referenced by: '<S4>/Analog Input2'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 0.005/20
                                        * Referenced by: '<S5>/Analog Input1'
                                        */
  real_T u_Value;                      /* Expression: 100
                                        * Referenced by: '<Root>/u'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Delay6_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S4>/Delay6'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S4>/Delay5'
                                        */
  real_T torqueGain_Gain;              /* Expression: 1.32
                                        * Referenced by: '<S4>/torqueGain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 3.3
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Delay6_InitialCondition_o;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay6'
                                        */
  real_T Delay5_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay5'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 0.2
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T controlvariableu1_Value;      /* Expression: 0.005
                                        * Referenced by: '<Root>/control variable u1'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  uint16_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_open_loop_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_open_loop_T open_loop_P;

/* Block signals (default storage) */
extern B_open_loop_T open_loop_B;

/* Block states (default storage) */
extern DW_open_loop_T open_loop_DW;

/* External function called from main */
extern void open_loop_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void open_loop_initialize(void);
extern void open_loop_step0(void);
extern void open_loop_step1(void);
extern void open_loop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_open_loop_T *const open_loop_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'open_loop'
 * '<S1>'   : 'open_loop/getPosition'
 * '<S2>'   : 'open_loop/getSpeedDelta'
 * '<S3>'   : 'open_loop/getTicksDelta'
 * '<S4>'   : 'open_loop/readCurrentSensor'
 * '<S5>'   : 'open_loop/readPotentiometer'
 * '<S6>'   : 'open_loop/sign'
 * '<S7>'   : 'open_loop/readCurrentSensor/firstOrderLagFilter'
 * '<S8>'   : 'open_loop/readCurrentSensor/readCurrent'
 * '<S9>'   : 'open_loop/readPotentiometer/firstOrderLagFilter'
 * '<S10>'  : 'open_loop/readPotentiometer/readRef'
 */
#endif                                 /* RTW_HEADER_open_loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
