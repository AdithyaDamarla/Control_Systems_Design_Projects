/*
 * Active_suspension_with_control_sim2.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Active_suspension_with_control_sim2".
 *
 * Model version              : 1.136
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sun Oct  1 12:48:33 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Active_suspension_with_control_sim2_h_
#define RTW_HEADER_Active_suspension_with_control_sim2_h_
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Active_suspension_with_control_sim2_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define Active_suspension_with_control_sim2_M (Active_suspension_with_contr_M)

/* Block signals (default storage) */
struct B_Active_suspension_with_cont_T {
  real_T y_dot;                        /* '<S1>/Integrator' */
  real_T x_dot;                        /* '<S2>/Integrator' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T y_2dot;                       /* '<S1>/Gain2' */
  real_T x_2dot;                       /* '<S2>/Gain2' */
};

/* Continuous states (default storage) */
struct X_Active_suspension_with_cont_T {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator1_CSTATE_i;         /* '<S2>/Integrator1' */
  real_T PIEngineeringDerivative_CSTATE[2];/* '<S5>/P.I.+Engineering Derivative' */
  real_T Integrator_CSTATE_c;          /* '<S7>/Integrator' */
};

/* State derivatives (default storage) */
struct XDot_Active_suspension_with_c_T {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator1_CSTATE_i;         /* '<S2>/Integrator1' */
  real_T PIEngineeringDerivative_CSTATE[2];/* '<S5>/P.I.+Engineering Derivative' */
  real_T Integrator_CSTATE_c;          /* '<S7>/Integrator' */
};

/* State disabled  */
struct XDis_Active_suspension_with_c_T {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator_CSTATE_a;       /* '<S1>/Integrator' */
  boolean_T Integrator_CSTATE_o;       /* '<S2>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator1_CSTATE_i;      /* '<S2>/Integrator1' */
  boolean_T PIEngineeringDerivative_CSTATE[2];/* '<S5>/P.I.+Engineering Derivative' */
  boolean_T Integrator_CSTATE_c;       /* '<S7>/Integrator' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Real-time Model Data Structure */
struct tag_RTM_Active_suspension_wit_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Active_suspension_with_cont_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Class declaration for model Active_suspension_with_control_sim2 */
class Active_suspension_with_control_sim2ModelClass
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  Active_suspension_with_control_sim2ModelClass
    (Active_suspension_with_control_sim2ModelClass const&) =delete;

  /* Assignment Operator */
  Active_suspension_with_control_sim2ModelClass& operator=
    (Active_suspension_with_control_sim2ModelClass const&) & = delete;

  /* Real-Time Model get method */
  RT_MODEL_Active_suspension_wi_T * getRTM();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  Active_suspension_with_control_sim2ModelClass();

  /* Destructor */
  ~Active_suspension_with_control_sim2ModelClass();

  /* private data and function members */
 private:
  /* Block signals */
  B_Active_suspension_with_cont_T Active_suspension_with_contro_B;

  /* Block continuous states */
  X_Active_suspension_with_cont_T Active_suspension_with_contro_X;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void Active_suspension_with_control_sim2_derivatives();

  /* Real-Time Model */
  RT_MODEL_Active_suspension_wi_T Active_suspension_with_contr_M;
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Gain1' : Unused code path elimination
 * Block '<S6>/Add' : Unused code path elimination
 * Block '<S6>/Derivative' : Unused code path elimination
 * Block '<S6>/Gain1' : Unused code path elimination
 * Block '<S6>/Gain2' : Unused code path elimination
 * Block '<S7>/Add' : Unused code path elimination
 * Block '<S7>/Gain2' : Unused code path elimination
 * Block '<S1>/control' : Unused code path elimination
 * Block '<S1>/dist' : Unused code path elimination
 * Block '<S1>/ref' : Unused code path elimination
 * Block '<S1>/y_*,y' : Unused code path elimination
 * Block '<S1>/y_out' : Unused code path elimination
 * Block '<S2>/x_out' : Unused code path elimination
 * Block '<Root>/z_dot,z' : Unused code path elimination
 * Block '<Root>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S1>/Manual Switch' : Eliminated due to constant selection input
 * Block '<Root>/Road Profile' : Unused code path elimination
 */

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
 * '<Root>' : 'Active_suspension_with_control_sim2'
 * '<S1>'   : 'Active_suspension_with_control_sim2/Mass-Spring-Damp'
 * '<S2>'   : 'Active_suspension_with_control_sim2/Tyre Model'
 * '<S3>'   : 'Active_suspension_with_control_sim2/Mass-Spring-Damp/Compensator C(s)'
 * '<S4>'   : 'Active_suspension_with_control_sim2/Mass-Spring-Damp/Disturbance'
 * '<S5>'   : 'Active_suspension_with_control_sim2/Mass-Spring-Damp/Compensator C(s)/P.I.D. Controller'
 * '<S6>'   : 'Active_suspension_with_control_sim2/Mass-Spring-Damp/Compensator C(s)/P.I.D. Controller/Proportional+Derivative'
 * '<S7>'   : 'Active_suspension_with_control_sim2/Mass-Spring-Damp/Compensator C(s)/P.I.D. Controller/Proportional+Derivative+Integral'
 */
#endif                   /* RTW_HEADER_Active_suspension_with_control_sim2_h_ */
