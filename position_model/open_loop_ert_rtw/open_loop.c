/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: open_loop.c
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

#include "open_loop.h"
#include <math.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "open_loop_private.h"

/* Block signals (default storage) */
B_open_loop_T open_loop_B;

/* Block states (default storage) */
DW_open_loop_T open_loop_DW;

/* Real-time model */
static RT_MODEL_open_loop_T open_loop_M_;
RT_MODEL_open_loop_T *const open_loop_M = &open_loop_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void open_loop_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(open_loop_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (open_loop_M->Timing.TaskCounters.TID[1])++;
  if ((open_loop_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.005s, 0.0s] */
    open_loop_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void open_loop_step0(void)             /* Sample time: [0.00025s, 0.0s] */
{
  real_T rtb_Abs;

  {                                    /* Sample time: [0.00025s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Constant: '<Root>/u' */
  open_loop_B.u = open_loop_P.u_Value;

  /* MATLAB Function: '<Root>/sign' */
  open_loop_B.y = (open_loop_B.u > 0.0);

  /* Saturate: '<Root>/Saturation' */
  if (open_loop_B.u > open_loop_P.Saturation_UpperSat) {
    rtb_Abs = open_loop_P.Saturation_UpperSat;
  } else if (open_loop_B.u < open_loop_P.Saturation_LowerSat) {
    rtb_Abs = open_loop_P.Saturation_LowerSat;
  } else {
    rtb_Abs = open_loop_B.u;
  }

  /* Abs: '<Root>/Abs' incorporates:
   *  Saturate: '<Root>/Saturation'
   */
  rtb_Abs = fabs(rtb_Abs);

  /* MATLABSystem: '<Root>/IN2A' incorporates:
   *  Logic: '<Root>/Logical Operator'
   *  Product: '<Root>/Product'
   */
  MW_PWM_SetDutyCycle(open_loop_DW.obj_g.MW_PWM_HANDLE, rtb_Abs * (real_T)
                      !(open_loop_B.y != 0.0));

  /* MATLABSystem: '<Root>/IN1A' incorporates:
   *  Product: '<Root>/Product1'
   */
  MW_PWM_SetDutyCycle(open_loop_DW.obj_j.MW_PWM_HANDLE, open_loop_B.y * rtb_Abs);

  /* MATLABSystem: '<Root>/EN_A' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_digitalIO_write(open_loop_DW.obj_p.MW_DIGITALIO_HANDLE,
                     open_loop_P.Constant_Value != 0.0);

  /* MATLAB Function: '<S4>/firstOrderLagFilter' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Delay: '<S4>/Delay5'
   *  Delay: '<S4>/Delay6'
   */
  open_loop_B.y_hat_g = (1.0 - open_loop_P.readCurrentSensor_alpha) *
    open_loop_DW.Delay6_DSTATE + open_loop_P.readCurrentSensor_alpha *
    open_loop_DW.Delay5_DSTATE;

  /* RateTransition: '<Root>/Rate Transition' */
  open_loop_B.RateTransition = open_loop_B.y_hat_g;

  /* Gain: '<S4>/torqueGain' */
  open_loop_B.torqueGain = open_loop_P.torqueGain_Gain * open_loop_B.y_hat_g;

  /* MATLABSystem: '<S4>/Analog Input2' */
  if (open_loop_DW.obj_b.SampleTime != open_loop_P.AnalogInput2_SampleTime) {
    open_loop_DW.obj_b.SampleTime = open_loop_P.AnalogInput2_SampleTime;
  }

  MW_AnalogIn_Start(open_loop_DW.obj_b.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S4>/Analog Input2' */
  MW_AnalogInSingle_ReadResult(open_loop_DW.obj_b.MW_ANALOGIN_HANDLE,
    &open_loop_B.AnalogInput2, 7);

  /* Gain: '<S4>/Gain1' */
  open_loop_B.Gain1 = open_loop_P.Gain1_Gain * open_loop_B.AnalogInput2;

  /* MATLAB Function: '<S4>/readCurrent' */
  open_loop_B.y_h = ((open_loop_B.Gain1 - 2.5) - 0.105) / 0.185;

  /* MATLAB Function: '<S5>/firstOrderLagFilter' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Delay: '<S5>/Delay5'
   *  Delay: '<S5>/Delay6'
   */
  open_loop_DW.Delay5_DSTATE_i = (1.0 - open_loop_P.readPotentiometer_alpha) *
    open_loop_DW.Delay6_DSTATE_d + open_loop_P.readPotentiometer_alpha *
    open_loop_DW.Delay5_DSTATE_i;

  /* RateTransition: '<Root>/Rate Transition1' */
  open_loop_B.RateTransition1 = open_loop_DW.Delay5_DSTATE_i;

  /* MATLABSystem: '<S5>/Analog Input1' */
  if (open_loop_DW.obj_l.SampleTime != open_loop_P.AnalogInput1_SampleTime) {
    open_loop_DW.obj_l.SampleTime = open_loop_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(open_loop_DW.obj_l.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S5>/Analog Input1' */
  MW_AnalogInSingle_ReadResult(open_loop_DW.obj_l.MW_ANALOGIN_HANDLE,
    &open_loop_B.AnalogInput1, 7);

  /* MATLAB Function: '<S5>/readRef' */
  open_loop_B.ref = open_loop_B.AnalogInput1 * 0.2;

  /* Saturate: '<S5>/Saturation2' */
  if (open_loop_B.ref > open_loop_P.Saturation2_UpperSat) {
    open_loop_DW.Delay6_DSTATE_d = open_loop_P.Saturation2_UpperSat;
  } else if (open_loop_B.ref < open_loop_P.Saturation2_LowerSat) {
    open_loop_DW.Delay6_DSTATE_d = open_loop_P.Saturation2_LowerSat;
  } else {
    open_loop_DW.Delay6_DSTATE_d = open_loop_B.ref;
  }

  /* End of Saturate: '<S5>/Saturation2' */

  /* Update for Delay: '<S4>/Delay6' */
  open_loop_DW.Delay6_DSTATE = open_loop_B.y_h;

  /* Update for Delay: '<S4>/Delay5' */
  open_loop_DW.Delay5_DSTATE = open_loop_B.y_hat_g;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  open_loop_M->Timing.taskTime0 =
    ((time_T)(++open_loop_M->Timing.clockTick0)) * open_loop_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void open_loop_step1(void)             /* Sample time: [0.005s, 0.0s] */
{
  real_T completeTheta;
  real_T q;
  real_T r;
  int32_T delta;
  uint16_T b_varargout_2;
  boolean_T rEQ0;

  /* MATLABSystem: '<Root>/Qudrature Encoder' */
  if (open_loop_DW.obj.SampleTime != open_loop_P.QudratureEncoder_SampleTime) {
    open_loop_DW.obj.SampleTime = open_loop_P.QudratureEncoder_SampleTime;
  }

  /* MATLABSystem: '<Root>/Qudrature Encoder' */
  /* 		%% Define output properties */
  /*  Call C-function implementing device output */
  open_loop_B.QudratureEncoder_o1 = getEncoderCount();

  /* MATLABSystem: '<Root>/Qudrature Encoder' */
  getIndexCount(&b_varargout_2);

  /* MATLAB Function: '<Root>/getTicksDelta' incorporates:
   *  Constant: '<Root>/control variable u1'
   *  Delay: '<Root>/Delay'
   */
  delta = open_loop_B.QudratureEncoder_o1 - open_loop_DW.Delay_DSTATE;
  if (!(fabs((real_T)delta) <= ceil(12600.0 *
        open_loop_P.controlvariableu1_Value))) {
    if (open_loop_DW.Delay_DSTATE > open_loop_B.QudratureEncoder_o1) {
      delta += 65535;
    } else {
      delta -= 65535;
    }
  }

  /* End of MATLAB Function: '<Root>/getTicksDelta' */

  /* MATLAB Function: '<Root>/getSpeedDelta' incorporates:
   *  Constant: '<Root>/control variable u1'
   */
  open_loop_B.speed = (real_T)delta * 60.0 / (8400.0 *
    open_loop_P.controlvariableu1_Value);

  /* MATLAB Function: '<Root>/getPosition' incorporates:
   *  Delay: '<Root>/Delay1'
   */
  open_loop_DW.Delay1_DSTATE += (real_T)delta;
  completeTheta = 6.2831853071795862 * open_loop_DW.Delay1_DSTATE / 8400.0;
  q = fabs(completeTheta);
  if (rtIsNaN(q)) {
    r = (rtNaN);
  } else if (rtIsInf(q)) {
    r = (rtNaN);
  } else if (q == 0.0) {
    r = 0.0;
  } else {
    r = fmod(q, 6.2831853071795862);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      q /= 6.2831853071795862;
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = 0.0;
    }
  }

  if (rtIsNaN(completeTheta)) {
    completeTheta = (rtNaN);
  } else if (completeTheta < 0.0) {
    completeTheta = -1.0;
  } else {
    completeTheta = (completeTheta > 0.0);
  }

  open_loop_B.position = completeTheta * r;

  /* End of MATLAB Function: '<Root>/getPosition' */
  /* Update for Delay: '<Root>/Delay' */
  open_loop_DW.Delay_DSTATE = open_loop_B.QudratureEncoder_o1;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  open_loop_M->Timing.clockTick1++;
}

/* Model initialize function */
void open_loop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(open_loop_M, -1);
  open_loop_M->Timing.stepSize0 = 0.00025;

  /* External mode info */
  open_loop_M->Sizes.checksums[0] = (3189101500U);
  open_loop_M->Sizes.checksums[1] = (4123893509U);
  open_loop_M->Sizes.checksums[2] = (3695158473U);
  open_loop_M->Sizes.checksums[3] = (1135620146U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    open_loop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(open_loop_M->extModeInfo,
      &open_loop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(open_loop_M->extModeInfo, open_loop_M->Sizes.checksums);
    rteiSetTPtr(open_loop_M->extModeInfo, rtmGetTPtr(open_loop_M));
  }

  /* Start for Constant: '<Root>/u' */
  open_loop_B.u = open_loop_P.u_Value;

  /* InitializeConditions for Delay: '<S4>/Delay6' */
  open_loop_DW.Delay6_DSTATE = open_loop_P.Delay6_InitialCondition;

  /* InitializeConditions for Delay: '<S4>/Delay5' */
  open_loop_DW.Delay5_DSTATE = open_loop_P.Delay5_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay6' */
  open_loop_DW.Delay6_DSTATE_d = open_loop_P.Delay6_InitialCondition_o;

  /* InitializeConditions for Delay: '<S5>/Delay5' */
  open_loop_DW.Delay5_DSTATE_i = open_loop_P.Delay5_InitialCondition_a;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  open_loop_DW.Delay_DSTATE = open_loop_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  open_loop_DW.Delay1_DSTATE = open_loop_P.Delay1_InitialCondition;

  /* Start for MATLABSystem: '<Root>/IN2A' */
  open_loop_DW.obj_g.matlabCodegenIsDeleted = false;
  open_loop_DW.obj_g.isInitialized = 1;
  open_loop_DW.obj_g.MW_PWM_HANDLE = MW_PWM_Open(4, 2000.0, 50.0);
  MW_PWM_Start(open_loop_DW.obj_g.MW_PWM_HANDLE);
  open_loop_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/IN1A' */
  open_loop_DW.obj_j.matlabCodegenIsDeleted = false;
  open_loop_DW.obj_j.isInitialized = 1;
  open_loop_DW.obj_j.MW_PWM_HANDLE = MW_PWM_Open(5, 2000.0, 50.0);
  MW_PWM_Start(open_loop_DW.obj_j.MW_PWM_HANDLE);
  open_loop_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/EN_A' */
  open_loop_DW.obj_p.matlabCodegenIsDeleted = false;
  open_loop_DW.obj_p.isInitialized = 1;
  open_loop_DW.obj_p.MW_DIGITALIO_HANDLE = MW_digitalIO_open(2, 1);
  open_loop_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Analog Input2' */
  open_loop_DW.obj_b.matlabCodegenIsDeleted = false;
  open_loop_DW.obj_b.SampleTime = open_loop_P.AnalogInput2_SampleTime;
  open_loop_DW.obj_b.isInitialized = 1;
  open_loop_DW.obj_b.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(A5);
  MW_AnalogIn_SetTriggerSource(open_loop_DW.obj_b.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  open_loop_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Analog Input1' */
  open_loop_DW.obj_l.matlabCodegenIsDeleted = false;
  open_loop_DW.obj_l.SampleTime = open_loop_P.AnalogInput1_SampleTime;
  open_loop_DW.obj_l.isInitialized = 1;
  open_loop_DW.obj_l.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(A4);
  MW_AnalogIn_SetTriggerSource(open_loop_DW.obj_l.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  open_loop_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Qudrature Encoder' */
  /*  Constructor */
  open_loop_DW.obj.matlabCodegenIsDeleted = false;
  open_loop_DW.obj.SampleTime = open_loop_P.QudratureEncoder_SampleTime;
  open_loop_DW.obj.isInitialized = 1;

  /* 		%% Define output properties */
  /*  Call C-function implementing device initialization */
  initEncoder();
  open_loop_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void open_loop_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/IN2A' */
  if (!open_loop_DW.obj_g.matlabCodegenIsDeleted) {
    open_loop_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((open_loop_DW.obj_g.isInitialized == 1) &&
        open_loop_DW.obj_g.isSetupComplete) {
      MW_PWM_Stop(open_loop_DW.obj_g.MW_PWM_HANDLE);
      MW_PWM_Close(open_loop_DW.obj_g.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN2A' */

  /* Terminate for MATLABSystem: '<Root>/IN1A' */
  if (!open_loop_DW.obj_j.matlabCodegenIsDeleted) {
    open_loop_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((open_loop_DW.obj_j.isInitialized == 1) &&
        open_loop_DW.obj_j.isSetupComplete) {
      MW_PWM_Stop(open_loop_DW.obj_j.MW_PWM_HANDLE);
      MW_PWM_Close(open_loop_DW.obj_j.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN1A' */
  /* Terminate for MATLABSystem: '<Root>/EN_A' */
  if (!open_loop_DW.obj_p.matlabCodegenIsDeleted) {
    open_loop_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((open_loop_DW.obj_p.isInitialized == 1) &&
        open_loop_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(open_loop_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/EN_A' */
  /* Terminate for MATLABSystem: '<S4>/Analog Input2' */
  if (!open_loop_DW.obj_b.matlabCodegenIsDeleted) {
    open_loop_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((open_loop_DW.obj_b.isInitialized == 1) &&
        open_loop_DW.obj_b.isSetupComplete) {
      MW_AnalogIn_Stop(open_loop_DW.obj_b.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(open_loop_DW.obj_b.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input2' */
  /* Terminate for MATLABSystem: '<S5>/Analog Input1' */
  if (!open_loop_DW.obj_l.matlabCodegenIsDeleted) {
    open_loop_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((open_loop_DW.obj_l.isInitialized == 1) &&
        open_loop_DW.obj_l.isSetupComplete) {
      MW_AnalogIn_Stop(open_loop_DW.obj_l.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(open_loop_DW.obj_l.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Analog Input1' */
  /* Terminate for MATLABSystem: '<Root>/Qudrature Encoder' */
  if (!open_loop_DW.obj.matlabCodegenIsDeleted) {
    open_loop_DW.obj.matlabCodegenIsDeleted = true;
    if ((open_loop_DW.obj.isInitialized == 1) &&
        open_loop_DW.obj.isSetupComplete) {
      /*  Call C-function implementing device termination */
      releaseEncoder();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Qudrature Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
