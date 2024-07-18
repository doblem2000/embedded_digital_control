/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: position_control_motor_sm.c
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

#include "position_control_motor_sm.h"
#include <math.h>
#include "rtwtypes.h"
#include "position_control_motor_sm_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_position_control_motor_sm_T position_control_motor_sm_B;

/* Block states (default storage) */
DW_position_control_motor_sm_T position_control_motor_sm_DW;

/* Real-time model */
static RT_MODEL_position_control_mot_T position_control_motor_sm_M_;
RT_MODEL_position_control_mot_T *const position_control_motor_sm_M =
  &position_control_motor_sm_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void position_control_motor_sm_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(position_control_motor_sm_M, 1));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  position_control_motor_sm_M->Timing.RateInteraction.TID0_1 =
    (position_control_motor_sm_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (position_control_motor_sm_M->Timing.TaskCounters.TID[1])++;
  if ((position_control_motor_sm_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.005s, 0.0s] */
    position_control_motor_sm_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void position_control_motor_sm_step0(void) /* Sample time: [0.00025s, 0.0s] */
{
  {                                    /* Sample time: [0.00025s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLAB Function: '<S4>/firstOrderLagFilter' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Delay: '<S4>/Delay5'
   *  Delay: '<S4>/Delay6'
   */
  position_control_motor_sm_DW.Delay5_DSTATE = (1.0 -
    position_control_motor_sm_P.readPotentiometer_alpha) *
    position_control_motor_sm_DW.Delay6_DSTATE +
    position_control_motor_sm_P.readPotentiometer_alpha *
    position_control_motor_sm_DW.Delay5_DSTATE;

  /* RateTransition: '<Root>/Rate Transition1' */
  if (position_control_motor_sm_M->Timing.RateInteraction.TID0_1) {
    position_control_motor_sm_DW.RateTransition1_Buffer =
      position_control_motor_sm_DW.Delay5_DSTATE;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* MATLABSystem: '<S4>/Analog Input1' */
  if (position_control_motor_sm_DW.obj.SampleTime !=
      position_control_motor_sm_P.AnalogInput1_SampleTime) {
    position_control_motor_sm_DW.obj.SampleTime =
      position_control_motor_sm_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(position_control_motor_sm_DW.obj.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S4>/Analog Input1' */
  MW_AnalogInSingle_ReadResult
    (position_control_motor_sm_DW.obj.MW_ANALOGIN_HANDLE,
     &position_control_motor_sm_B.AnalogInput1, 7);

  /* MATLAB Function: '<S4>/readRef' */
  position_control_motor_sm_DW.Delay6_DSTATE =
    position_control_motor_sm_B.AnalogInput1 * 2.0 * 3.1415926535897931;

  /* Saturate: '<S4>/Saturation2' */
  if (position_control_motor_sm_DW.Delay6_DSTATE >
      position_control_motor_sm_P.Saturation2_UpperSat) {
    /* MATLAB Function: '<S4>/readRef' */
    position_control_motor_sm_DW.Delay6_DSTATE =
      position_control_motor_sm_P.Saturation2_UpperSat;
  } else if (position_control_motor_sm_DW.Delay6_DSTATE <
             position_control_motor_sm_P.Saturation2_LowerSat) {
    /* MATLAB Function: '<S4>/readRef' */
    position_control_motor_sm_DW.Delay6_DSTATE =
      position_control_motor_sm_P.Saturation2_LowerSat;
  }

  /* End of Saturate: '<S4>/Saturation2' */

  /* MATLABSystem: '<S5>/EN_A' incorporates:
   *  Constant: '<S5>/Constant'
   */
  MW_digitalIO_write(position_control_motor_sm_DW.obj_p.MW_DIGITALIO_HANDLE,
                     position_control_motor_sm_P.Constant_Value != 0.0);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  position_control_motor_sm_M->Timing.taskTime0 =
    ((time_T)(++position_control_motor_sm_M->Timing.clockTick0)) *
    position_control_motor_sm_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void position_control_motor_sm_step1(void) /* Sample time: [0.005s, 0.0s] */
{
  real_T rtb_Abs;
  int32_T delta;
  uint16_T b_varargout_2;

  /* Delay: '<Root>/Delay' */
  position_control_motor_sm_B.Delay[0] =
    position_control_motor_sm_DW.Delay_DSTATE[0];
  position_control_motor_sm_B.Delay[1] =
    position_control_motor_sm_DW.Delay_DSTATE[1];

  /* MATLABSystem: '<S5>/Qudrature Encoder' */
  if (position_control_motor_sm_DW.obj_g.SampleTime !=
      position_control_motor_sm_P.Ts) {
    position_control_motor_sm_DW.obj_g.SampleTime =
      position_control_motor_sm_P.Ts;
  }

  /* MATLABSystem: '<S5>/Qudrature Encoder' */
  /* 		%% Define output properties */
  /*  Call C-function implementing device output */
  position_control_motor_sm_B.QudratureEncoder_o1 = getEncoderCount();

  /* MATLABSystem: '<S5>/Qudrature Encoder' */
  getIndexCount(&b_varargout_2);

  /* MATLAB Function: '<S5>/getTicksDelta' incorporates:
   *  Constant: '<S5>/Ts'
   *  Delay: '<S5>/Delay'
   */
  delta = position_control_motor_sm_B.QudratureEncoder_o1 -
    position_control_motor_sm_DW.Delay_DSTATE_k;
  if (!(fabs((real_T)delta) <= ceil(12600.0 * position_control_motor_sm_P.Ts)))
  {
    if (position_control_motor_sm_DW.Delay_DSTATE_k >
        position_control_motor_sm_B.QudratureEncoder_o1) {
      delta += 65535;
    } else {
      delta -= 65535;
    }
  }

  /* End of MATLAB Function: '<S5>/getTicksDelta' */

  /* MATLAB Function: '<S5>/getPosition' incorporates:
   *  Delay: '<S5>/Delay1'
   */
  position_control_motor_sm_DW.Delay1_DSTATE += (real_T)delta;
  position_control_motor_sm_B.position = 6.2831853071795862 *
    position_control_motor_sm_DW.Delay1_DSTATE / 8400.0;

  /* MATLAB Function: '<S5>/getSpeedDelta' incorporates:
   *  Constant: '<S5>/Ts'
   */
  position_control_motor_sm_B.speed = (real_T)delta * 60.0 / (8400.0 *
    position_control_motor_sm_P.Ts);

  /* Gain: '<Root>/RPMtoRad//s1' */
  position_control_motor_sm_B.RPMtoRads1 =
    position_control_motor_sm_P.RPMtoRads1_Gain *
    position_control_motor_sm_B.speed;

  /* MATLAB Function: '<Root>/createVector' */
  position_control_motor_sm_B.x[0] = position_control_motor_sm_B.RPMtoRads1;
  position_control_motor_sm_B.x[1] = position_control_motor_sm_B.position;

  /* Delay: '<Root>/Delay1' */
  position_control_motor_sm_B.Delay1 =
    position_control_motor_sm_DW.Delay1_DSTATE_j;

  /* MATLAB Function: '<Root>/calculateDeltau' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  position_control_motor_sm_B.delta_u = ((position_control_motor_sm_B.x[0] -
    position_control_motor_sm_B.Delay[0]) * -position_control_motor_sm_P.K[0] +
    (position_control_motor_sm_B.x[1] - position_control_motor_sm_B.Delay[1]) *
    -position_control_motor_sm_P.K[1]) +
    (position_control_motor_sm_DW.DiscreteTimeIntegrator_DSTATE -
     position_control_motor_sm_B.Delay1) * -position_control_motor_sm_P.K[2];

  /* Delay: '<Root>/Delay2' */
  position_control_motor_sm_B.Delay2 =
    position_control_motor_sm_DW.Delay2_DSTATE;

  /* MATLAB Function: '<Root>/uFromDeltau' */
  position_control_motor_sm_B.u = position_control_motor_sm_B.Delay2 +
    position_control_motor_sm_B.delta_u;
  if (position_control_motor_sm_B.u < -12.0) {
    position_control_motor_sm_B.u = -12.0;
  }

  if (position_control_motor_sm_B.u > 12.0) {
    position_control_motor_sm_B.u = 12.0;
  }

  /* End of MATLAB Function: '<Root>/uFromDeltau' */
  /* Gain: '<Root>/Gain' */
  position_control_motor_sm_B.Gain = position_control_motor_sm_P.Gain_Gain *
    position_control_motor_sm_B.u;

  /* MATLAB Function: '<S5>/sign' */
  position_control_motor_sm_B.y = (position_control_motor_sm_B.Gain > 0.0);

  /* Saturate: '<S5>/Saturation1' */
  if (position_control_motor_sm_B.Gain >
      position_control_motor_sm_P.Saturation1_UpperSat) {
    rtb_Abs = position_control_motor_sm_P.Saturation1_UpperSat;
  } else if (position_control_motor_sm_B.Gain <
             position_control_motor_sm_P.Saturation1_LowerSat) {
    rtb_Abs = position_control_motor_sm_P.Saturation1_LowerSat;
  } else {
    rtb_Abs = position_control_motor_sm_B.Gain;
  }

  /* Abs: '<S5>/Abs' incorporates:
   *  Saturate: '<S5>/Saturation1'
   */
  rtb_Abs = fabs(rtb_Abs);

  /* MATLABSystem: '<S5>/IN2A' incorporates:
   *  Logic: '<S5>/Logical Operator'
   *  Product: '<S5>/Product'
   */
  MW_PWM_SetDutyCycle(position_control_motor_sm_DW.obj_e.MW_PWM_HANDLE, rtb_Abs *
                      (real_T)!(position_control_motor_sm_B.y != 0.0));

  /* MATLABSystem: '<S5>/IN1A' incorporates:
   *  Product: '<S5>/Product1'
   */
  MW_PWM_SetDutyCycle(position_control_motor_sm_DW.obj_b.MW_PWM_HANDLE,
                      position_control_motor_sm_B.y * rtb_Abs);

  /* RateTransition: '<Root>/Rate Transition1' */
  position_control_motor_sm_B.RateTransition1 =
    position_control_motor_sm_DW.RateTransition1_Buffer;

  /* ManualSwitch: '<Root>/inputReferences' */
  if (position_control_motor_sm_P.inputReferences_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/inputReferences' incorporates:
     *  Constant: '<Root>/control variable u'
     */
    position_control_motor_sm_B.inputReferences =
      position_control_motor_sm_P.controlvariableu_Value;
  } else {
    /* ManualSwitch: '<Root>/inputReferences' */
    position_control_motor_sm_B.inputReferences =
      position_control_motor_sm_B.RateTransition1;
  }

  /* End of ManualSwitch: '<Root>/inputReferences' */

  /* Sum: '<Root>/error' */
  position_control_motor_sm_B.error =
    position_control_motor_sm_B.inputReferences -
    position_control_motor_sm_B.position;

  /* MATLABSystem: '<Root>/Digital Write' incorporates:
   *  MATLAB Function: '<Root>/ getLedStatus'
   */
  MW_digitalIO_write(position_control_motor_sm_DW.obj_pz.MW_DIGITALIO_HANDLE,
                     fabs(position_control_motor_sm_B.error) < 0.1);

  /* Update for Delay: '<Root>/Delay' */
  position_control_motor_sm_DW.Delay_DSTATE[0] = position_control_motor_sm_B.x[0];
  position_control_motor_sm_DW.Delay_DSTATE[1] = position_control_motor_sm_B.x[1];

  /* Update for Delay: '<S5>/Delay' */
  position_control_motor_sm_DW.Delay_DSTATE_k =
    position_control_motor_sm_B.QudratureEncoder_o1;

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  position_control_motor_sm_DW.Delay1_DSTATE_j =
    position_control_motor_sm_DW.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  position_control_motor_sm_DW.DiscreteTimeIntegrator_DSTATE +=
    position_control_motor_sm_P.DiscreteTimeIntegrator_gainval *
    position_control_motor_sm_B.error;

  /* Update for Delay: '<Root>/Delay2' */
  position_control_motor_sm_DW.Delay2_DSTATE = position_control_motor_sm_B.u;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  position_control_motor_sm_M->Timing.clockTick1++;
}

/* Model initialize function */
void position_control_motor_sm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(position_control_motor_sm_M, -1);
  position_control_motor_sm_M->Timing.stepSize0 = 0.00025;

  /* External mode info */
  position_control_motor_sm_M->Sizes.checksums[0] = (981352415U);
  position_control_motor_sm_M->Sizes.checksums[1] = (4032403884U);
  position_control_motor_sm_M->Sizes.checksums[2] = (438790145U);
  position_control_motor_sm_M->Sizes.checksums[3] = (2862662973U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    position_control_motor_sm_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(position_control_motor_sm_M->extModeInfo,
      &position_control_motor_sm_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(position_control_motor_sm_M->extModeInfo,
                        position_control_motor_sm_M->Sizes.checksums);
    rteiSetTPtr(position_control_motor_sm_M->extModeInfo, rtmGetTPtr
                (position_control_motor_sm_M));
  }

  /* InitializeConditions for MATLAB Function: '<S4>/readRef' incorporates:
   *  Delay: '<S4>/Delay6'
   */
  position_control_motor_sm_DW.Delay6_DSTATE =
    position_control_motor_sm_P.Delay6_InitialCondition;

  /* InitializeConditions for Delay: '<S4>/Delay5' */
  position_control_motor_sm_DW.Delay5_DSTATE =
    position_control_motor_sm_P.Delay5_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  position_control_motor_sm_DW.Delay_DSTATE[0] =
    position_control_motor_sm_P.Delay_InitialCondition;
  position_control_motor_sm_DW.Delay_DSTATE[1] =
    position_control_motor_sm_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay1' */
  position_control_motor_sm_DW.Delay1_DSTATE =
    position_control_motor_sm_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay' */
  position_control_motor_sm_DW.Delay_DSTATE_k =
    position_control_motor_sm_P.Delay_InitialCondition_c;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  position_control_motor_sm_DW.Delay1_DSTATE_j =
    position_control_motor_sm_P.Delay1_InitialCondition_c;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  position_control_motor_sm_DW.DiscreteTimeIntegrator_DSTATE =
    position_control_motor_sm_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<Root>/Delay2' */
  position_control_motor_sm_DW.Delay2_DSTATE =
    position_control_motor_sm_P.Delay2_InitialCondition;

  /* Start for MATLABSystem: '<S4>/Analog Input1' */
  position_control_motor_sm_DW.obj.matlabCodegenIsDeleted = false;
  position_control_motor_sm_DW.obj.SampleTime =
    position_control_motor_sm_P.AnalogInput1_SampleTime;
  position_control_motor_sm_DW.obj.isInitialized = 1;
  position_control_motor_sm_DW.obj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (A4);
  MW_AnalogIn_SetTriggerSource
    (position_control_motor_sm_DW.obj.MW_ANALOGIN_HANDLE,
     MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  position_control_motor_sm_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/EN_A' */
  position_control_motor_sm_DW.obj_p.matlabCodegenIsDeleted = false;
  position_control_motor_sm_DW.obj_p.isInitialized = 1;
  position_control_motor_sm_DW.obj_p.MW_DIGITALIO_HANDLE = MW_digitalIO_open(2,
    1);
  position_control_motor_sm_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Qudrature Encoder' */
  /*  Constructor */
  position_control_motor_sm_DW.obj_g.matlabCodegenIsDeleted = false;
  position_control_motor_sm_DW.obj_g.SampleTime = position_control_motor_sm_P.Ts;
  position_control_motor_sm_DW.obj_g.isInitialized = 1;

  /* 		%% Define output properties */
  /*  Call C-function implementing device initialization */
  initEncoder();
  position_control_motor_sm_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/IN2A' */
  position_control_motor_sm_DW.obj_e.matlabCodegenIsDeleted = false;
  position_control_motor_sm_DW.obj_e.isInitialized = 1;
  position_control_motor_sm_DW.obj_e.MW_PWM_HANDLE = MW_PWM_Open(4, 2000.0, 50.0);
  MW_PWM_Start(position_control_motor_sm_DW.obj_e.MW_PWM_HANDLE);
  position_control_motor_sm_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/IN1A' */
  position_control_motor_sm_DW.obj_b.matlabCodegenIsDeleted = false;
  position_control_motor_sm_DW.obj_b.isInitialized = 1;
  position_control_motor_sm_DW.obj_b.MW_PWM_HANDLE = MW_PWM_Open(5, 2000.0, 50.0);
  MW_PWM_Start(position_control_motor_sm_DW.obj_b.MW_PWM_HANDLE);
  position_control_motor_sm_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  position_control_motor_sm_DW.obj_pz.matlabCodegenIsDeleted = false;
  position_control_motor_sm_DW.obj_pz.isInitialized = 1;
  position_control_motor_sm_DW.obj_pz.MW_DIGITALIO_HANDLE = MW_digitalIO_open(A3,
    1);
  position_control_motor_sm_DW.obj_pz.isSetupComplete = true;
}

/* Model terminate function */
void position_control_motor_sm_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Analog Input1' */
  if (!position_control_motor_sm_DW.obj.matlabCodegenIsDeleted) {
    position_control_motor_sm_DW.obj.matlabCodegenIsDeleted = true;
    if ((position_control_motor_sm_DW.obj.isInitialized == 1) &&
        position_control_motor_sm_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(position_control_motor_sm_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(position_control_motor_sm_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input1' */
  /* Terminate for MATLABSystem: '<S5>/EN_A' */
  if (!position_control_motor_sm_DW.obj_p.matlabCodegenIsDeleted) {
    position_control_motor_sm_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((position_control_motor_sm_DW.obj_p.isInitialized == 1) &&
        position_control_motor_sm_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(position_control_motor_sm_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/EN_A' */
  /* Terminate for MATLABSystem: '<S5>/Qudrature Encoder' */
  if (!position_control_motor_sm_DW.obj_g.matlabCodegenIsDeleted) {
    position_control_motor_sm_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((position_control_motor_sm_DW.obj_g.isInitialized == 1) &&
        position_control_motor_sm_DW.obj_g.isSetupComplete) {
      /*  Call C-function implementing device termination */
      releaseEncoder();
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Qudrature Encoder' */
  /* Terminate for MATLABSystem: '<S5>/IN2A' */
  if (!position_control_motor_sm_DW.obj_e.matlabCodegenIsDeleted) {
    position_control_motor_sm_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((position_control_motor_sm_DW.obj_e.isInitialized == 1) &&
        position_control_motor_sm_DW.obj_e.isSetupComplete) {
      MW_PWM_Stop(position_control_motor_sm_DW.obj_e.MW_PWM_HANDLE);
      MW_PWM_Close(position_control_motor_sm_DW.obj_e.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/IN2A' */

  /* Terminate for MATLABSystem: '<S5>/IN1A' */
  if (!position_control_motor_sm_DW.obj_b.matlabCodegenIsDeleted) {
    position_control_motor_sm_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((position_control_motor_sm_DW.obj_b.isInitialized == 1) &&
        position_control_motor_sm_DW.obj_b.isSetupComplete) {
      MW_PWM_Stop(position_control_motor_sm_DW.obj_b.MW_PWM_HANDLE);
      MW_PWM_Close(position_control_motor_sm_DW.obj_b.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/IN1A' */
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!position_control_motor_sm_DW.obj_pz.matlabCodegenIsDeleted) {
    position_control_motor_sm_DW.obj_pz.matlabCodegenIsDeleted = true;
    if ((position_control_motor_sm_DW.obj_pz.isInitialized == 1) &&
        position_control_motor_sm_DW.obj_pz.isSetupComplete) {
      MW_digitalIO_close(position_control_motor_sm_DW.obj_pz.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
