/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: position_control_motor_sm_types.h
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

#ifndef RTW_HEADER_position_control_motor_sm_types_h_
#define RTW_HEADER_position_control_motor_sm_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<S5>/IN2A' */
#include "MW_SVD.h"
#ifndef struct_tag_KxFW01GBdhqk5JOEHU3GlD
#define struct_tag_KxFW01GBdhqk5JOEHU3GlD

struct tag_KxFW01GBdhqk5JOEHU3GlD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_KxFW01GBdhqk5JOEHU3GlD */

#ifndef typedef_mbed_DigitalWrite_position_co_T
#define typedef_mbed_DigitalWrite_position_co_T

typedef struct tag_KxFW01GBdhqk5JOEHU3GlD mbed_DigitalWrite_position_co_T;

#endif                             /* typedef_mbed_DigitalWrite_position_co_T */

#ifndef struct_tag_p5Oj7yF0nd6COoUgI0GAlG
#define struct_tag_p5Oj7yF0nd6COoUgI0GAlG

struct tag_p5Oj7yF0nd6COoUgI0GAlG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_p5Oj7yF0nd6COoUgI0GAlG */

#ifndef typedef_mbed_AnalogInput_position_con_T
#define typedef_mbed_AnalogInput_position_con_T

typedef struct tag_p5Oj7yF0nd6COoUgI0GAlG mbed_AnalogInput_position_con_T;

#endif                             /* typedef_mbed_AnalogInput_position_con_T */

#ifndef struct_tag_UndvUYqhBVOhRRpUse3fWF
#define struct_tag_UndvUYqhBVOhRRpUse3fWF

struct tag_UndvUYqhBVOhRRpUse3fWF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_UndvUYqhBVOhRRpUse3fWF */

#ifndef typedef_mbed_PWMOutput_position_contr_T
#define typedef_mbed_PWMOutput_position_contr_T

typedef struct tag_UndvUYqhBVOhRRpUse3fWF mbed_PWMOutput_position_contr_T;

#endif                             /* typedef_mbed_PWMOutput_position_contr_T */

#ifndef struct_tag_sGWFgQTjADKFs5f99dqloH
#define struct_tag_sGWFgQTjADKFs5f99dqloH

struct tag_sGWFgQTjADKFs5f99dqloH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 /* struct_tag_sGWFgQTjADKFs5f99dqloH */

#ifndef typedef_soc_stm_QEP_position_control__T
#define typedef_soc_stm_QEP_position_control__T

typedef struct tag_sGWFgQTjADKFs5f99dqloH soc_stm_QEP_position_control__T;

#endif                             /* typedef_soc_stm_QEP_position_control__T */

/* Parameters (default storage) */
typedef struct P_position_control_motor_sm_T_ P_position_control_motor_sm_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_position_control_moto_T RT_MODEL_position_control_mot_T;

#endif                       /* RTW_HEADER_position_control_motor_sm_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
