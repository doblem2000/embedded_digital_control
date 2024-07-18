/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: open_loop_types.h
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

#ifndef RTW_HEADER_open_loop_types_h_
#define RTW_HEADER_open_loop_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<S5>/Analog Input1' */
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

#ifndef typedef_mbed_DigitalWrite_open_loop_T
#define typedef_mbed_DigitalWrite_open_loop_T

typedef struct tag_KxFW01GBdhqk5JOEHU3GlD mbed_DigitalWrite_open_loop_T;

#endif                               /* typedef_mbed_DigitalWrite_open_loop_T */

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

#ifndef typedef_mbed_PWMOutput_open_loop_T
#define typedef_mbed_PWMOutput_open_loop_T

typedef struct tag_UndvUYqhBVOhRRpUse3fWF mbed_PWMOutput_open_loop_T;

#endif                                 /* typedef_mbed_PWMOutput_open_loop_T */

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

#ifndef typedef_soc_stm_QEP_open_loop_T
#define typedef_soc_stm_QEP_open_loop_T

typedef struct tag_sGWFgQTjADKFs5f99dqloH soc_stm_QEP_open_loop_T;

#endif                                 /* typedef_soc_stm_QEP_open_loop_T */

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

#ifndef typedef_mbed_AnalogInput_open_loop_T
#define typedef_mbed_AnalogInput_open_loop_T

typedef struct tag_p5Oj7yF0nd6COoUgI0GAlG mbed_AnalogInput_open_loop_T;

#endif                                /* typedef_mbed_AnalogInput_open_loop_T */

/* Parameters (default storage) */
typedef struct P_open_loop_T_ P_open_loop_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_open_loop_T RT_MODEL_open_loop_T;

#endif                                 /* RTW_HEADER_open_loop_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
