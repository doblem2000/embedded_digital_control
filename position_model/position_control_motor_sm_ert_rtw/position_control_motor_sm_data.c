/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: position_control_motor_sm_data.c
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

/* Block parameters (default storage) */
P_position_control_motor_sm_T position_control_motor_sm_P = {
  /* Variable: K
   * Referenced by: '<Root>/Constant'
   */
  { 4.21942316089487, 55.651756689213713, -187.08286933869698 },

  /* Variable: Ts
   * Referenced by:
   *   '<S5>/Ts'
   *   '<S5>/Qudrature Encoder'
   */
  0.005,

  /* Mask Parameter: readPotentiometer_alpha
   * Referenced by: '<S4>/Constant2'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/control variable u'
   */
  0.0,

  /* Expression: 0.005/20
   * Referenced by: '<S4>/Analog Input1'
   */
  0.00025,

  /* Expression: 0
   * Referenced by: '<S4>/Delay6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Delay5'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Saturation2'
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<S4>/Saturation2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Delay1'
   */
  0.0,

  /* Expression: 1/9.54929
   * Referenced by: '<Root>/RPMtoRad//s1'
   */
  0.1047198273379487,

  /* Expression: 0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay2'
   */
  0.0,

  /* Expression: 100/12
   * Referenced by: '<Root>/Gain'
   */
  8.3333333333333339,

  /* Expression: 100
   * Referenced by: '<S5>/Saturation1'
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<S5>/Saturation1'
   */
  -100.0,

  /* Computed Parameter: Delay_InitialCondition_c
   * Referenced by: '<S5>/Delay'
   */
  0U,

  /* Computed Parameter: inputReferences_CurrentSetting
   * Referenced by: '<Root>/inputReferences'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
