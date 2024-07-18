/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: position_control_motor_sm.h
 *
 * Code generated for Simulink model 'position_control_motor_sm'.
 *
 * Model version                  : 1.225
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jul 17 14:57:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_position_control_motor_sm_h_
#define RTW_HEADER_position_control_motor_sm_h_
#ifndef position_control_motor_sm_COMMON_INCLUDES_
#define position_control_motor_sm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "soc_stm_encoder.h"
#endif                          /* position_control_motor_sm_COMMON_INCLUDES_ */

#include "position_control_motor_sm_types.h"
#include "rt_nonfinite.h"
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
  real_T Delay[2];                     /* '<Root>/Delay' */
  real_T RPMtoRads1;                   /* '<Root>/RPMtoRad//s1' */
  real_T Delay1;                       /* '<Root>/Delay1' */
  real_T Delay2;                       /* '<Root>/Delay2' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T inputReferences;              /* '<Root>/inputReferences' */
  real_T error;                        /* '<Root>/error' */
  real_T u;                            /* '<Root>/uFromDeltau' */
  real_T y;                            /* '<S5>/sign' */
  real_T speed;                        /* '<S5>/getSpeedDelta' */
  real_T position;                     /* '<S5>/getPosition' */
  real_T AnalogInput1;                 /* '<S4>/Analog Input1' */
  real_T x[2];                         /* '<Root>/createVector' */
  real_T delta_u;                      /* '<Root>/calculateDeltau' */
  uint16_T QudratureEncoder_o1;        /* '<S5>/Qudrature Encoder' */
} B_position_control_motor_sm_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_AnalogInput_position_con_T obj; /* '<S4>/Analog Input1' */
  soc_stm_QEP_position_control__T obj_g;/* '<S5>/Qudrature Encoder' */
  mbed_DigitalWrite_position_co_T obj_p;/* '<S5>/EN_A' */
  mbed_DigitalWrite_position_co_T obj_pz;/* '<Root>/Digital Write' */
  mbed_PWMOutput_position_contr_T obj_e;/* '<S5>/IN2A' */
  mbed_PWMOutput_position_contr_T obj_b;/* '<S5>/IN1A' */
  real_T Delay6_DSTATE;                /* '<S4>/Delay6' */
  real_T Delay5_DSTATE;                /* '<S4>/Delay5' */
  real_T Delay_DSTATE[2];              /* '<Root>/Delay' */
  real_T Delay1_DSTATE;                /* '<S5>/Delay1' */
  real_T Delay1_DSTATE_j;              /* '<Root>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T RateTransition1_Buffer;       /* '<Root>/Rate Transition1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S5>/Scope' */

  uint16_T Delay_DSTATE_k;             /* '<S5>/Delay' */
  uint8_T is_active_c10_position_control_;/* '<Root>/uFromDeltau' */
  uint8_T is_active_c2_position_control_m;/* '<S5>/sign' */
  uint8_T is_active_c1_position_control_m;/* '<S5>/getTicksDelta' */
  uint8_T is_active_c3_position_control_m;/* '<S5>/getSpeedDelta' */
  uint8_T is_active_c5_position_control_m;/* '<S5>/getPosition' */
  uint8_T is_active_c4_position_control_m;/* '<S4>/readRef' */
  uint8_T is_active_c7_position_control_m;/* '<S4>/firstOrderLagFilter' */
  uint8_T is_active_c12_position_control_;/* '<Root>/createVector' */
  uint8_T is_active_c9_position_control_m;/* '<Root>/calculateDeltau' */
  uint8_T is_active_c6_position_control_m;/* '<Root>/ getLedStatus' */
} DW_position_control_motor_sm_T;

/* Parameters (default storage) */
struct P_position_control_motor_sm_T_ {
  real_T K[3];                         /* Variable: K
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<S5>/Ts'
                                        *   '<S5>/Qudrature Encoder'
                                        */
  real_T readPotentiometer_alpha;     /* Mask Parameter: readPotentiometer_alpha
                                       * Referenced by: '<S4>/Constant2'
                                       */
  real_T controlvariableu_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/control variable u'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 0.005/20
                                        * Referenced by: '<S4>/Analog Input1'
                                        */
  real_T Delay6_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S4>/Delay6'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S4>/Delay5'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 2*pi
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S5>/Delay1'
                                        */
  real_T RPMtoRads1_Gain;              /* Expression: 1/9.54929
                                        * Referenced by: '<Root>/RPMtoRad//s1'
                                        */
  real_T Delay1_InitialCondition_c;    /* Expression: 0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real_T Gain_Gain;                    /* Expression: 100/12
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 100
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -100
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  uint16_T Delay_InitialCondition_c;
                                 /* Computed Parameter: Delay_InitialCondition_c
                                  * Referenced by: '<S5>/Delay'
                                  */
  uint8_T inputReferences_CurrentSetting;
                           /* Computed Parameter: inputReferences_CurrentSetting
                            * Referenced by: '<Root>/inputReferences'
                            */
};

/* Real-time Model Data Structure */
struct tag_RTM_position_control_moto_T {
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

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_position_control_motor_sm_T position_control_motor_sm_P;

/* Block signals (default storage) */
extern B_position_control_motor_sm_T position_control_motor_sm_B;

/* Block states (default storage) */
extern DW_position_control_motor_sm_T position_control_motor_sm_DW;

/* External function called from main */
extern void position_control_motor_sm_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void position_control_motor_sm_initialize(void);
extern void position_control_motor_sm_step0(void);
extern void position_control_motor_sm_step1(void);
extern void position_control_motor_sm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_position_control_mot_T *const position_control_motor_sm_M;
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
 * '<Root>' : 'position_control_motor_sm'
 * '<S1>'   : 'position_control_motor_sm/ getLedStatus'
 * '<S2>'   : 'position_control_motor_sm/calculateDeltau'
 * '<S3>'   : 'position_control_motor_sm/createVector'
 * '<S4>'   : 'position_control_motor_sm/readPotentiometer'
 * '<S5>'   : 'position_control_motor_sm/realMotor'
 * '<S6>'   : 'position_control_motor_sm/uFromDeltau'
 * '<S7>'   : 'position_control_motor_sm/readPotentiometer/firstOrderLagFilter'
 * '<S8>'   : 'position_control_motor_sm/readPotentiometer/readRef'
 * '<S9>'   : 'position_control_motor_sm/realMotor/getPosition'
 * '<S10>'  : 'position_control_motor_sm/realMotor/getSpeedDelta'
 * '<S11>'  : 'position_control_motor_sm/realMotor/getTicksDelta'
 * '<S12>'  : 'position_control_motor_sm/realMotor/sign'
 */
#endif                             /* RTW_HEADER_position_control_motor_sm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
