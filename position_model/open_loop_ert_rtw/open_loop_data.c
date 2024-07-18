/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: open_loop_data.c
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

/* Block parameters (default storage) */
P_open_loop_T open_loop_P = {
  /* Mask Parameter: readCurrentSensor_alpha
   * Referenced by: '<S4>/Constant2'
   */
  0.9,

  /* Mask Parameter: readPotentiometer_alpha
   * Referenced by: '<S5>/Constant2'
   */
  0.9,

  /* Expression: 0.005
   * Referenced by: '<Root>/Qudrature Encoder'
   */
  0.005,

  /* Expression: 0.005/20
   * Referenced by: '<S4>/Analog Input2'
   */
  0.00025,

  /* Expression: 0.005/20
   * Referenced by: '<S5>/Analog Input1'
   */
  0.00025,

  /* Expression: 100
   * Referenced by: '<Root>/u'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<Root>/Saturation'
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<Root>/Saturation'
   */
  -100.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Delay6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Delay5'
   */
  0.0,

  /* Expression: 1.32
   * Referenced by: '<S4>/torqueGain'
   */
  1.32,

  /* Expression: 3.3
   * Referenced by: '<S4>/Gain1'
   */
  3.3,

  /* Expression: 0
   * Referenced by: '<S5>/Delay6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Delay5'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S5>/Saturation2'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation2'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<Root>/control variable u1'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
