/*
 * Dynamic_steering_control_obs_ctrl.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Dynamic_steering_control_obs_ctrl".
 *
 * Model version              : 1.88
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sun Oct  1 13:20:43 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Dynamic_steering_control_obs_ctrl_h_
#define RTW_HEADER_Dynamic_steering_control_obs_ctrl_h_
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Dynamic_steering_control_obs_ctrl_types.h"

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

#define Dynamic_steering_control_obs_ctrl_M (Dynamic_steering_control_obs_M)

/* Block signals (default storage) */
struct B_Dynamic_steering_control_ob_T {
  real_T vy_dot;                       /* '<S1>/Add' */
  real_T w_dot;                        /* '<S1>/Add1' */
  real_T vy_dot_k;                     /* '<Root>/Add' */
  real_T w_dot_c;                      /* '<Root>/Add1' */
};

/* Continuous states (default storage) */
struct X_Dynamic_steering_control_ob_T {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator3_CSTATE_f;         /* '<Root>/Integrator3' */
  real_T Integrator1_CSTATE_o;         /* '<Root>/Integrator1' */
};

/* State derivatives (default storage) */
struct XDot_Dynamic_steering_control_T {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator3_CSTATE_f;         /* '<Root>/Integrator3' */
  real_T Integrator1_CSTATE_o;         /* '<Root>/Integrator1' */
};

/* State disabled  */
struct XDis_Dynamic_steering_control_T {
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator3_CSTATE;        /* '<S1>/Integrator3' */
  boolean_T Integrator3_CSTATE_f;      /* '<Root>/Integrator3' */
  boolean_T Integrator1_CSTATE_o;      /* '<Root>/Integrator1' */
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
struct tag_RTM_Dynamic_steering_cont_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Dynamic_steering_control_ob_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
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

/* Class declaration for model Dynamic_steering_control_obs_ctrl */
class Dynamic_steering_control_obs_ctrlModelClass
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  Dynamic_steering_control_obs_ctrlModelClass
    (Dynamic_steering_control_obs_ctrlModelClass const&) =delete;

  /* Assignment Operator */
  Dynamic_steering_control_obs_ctrlModelClass& operator=
    (Dynamic_steering_control_obs_ctrlModelClass const&) & = delete;

  /* Real-Time Model get method */
  RT_MODEL_Dynamic_steering_con_T * getRTM();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  Dynamic_steering_control_obs_ctrlModelClass();

  /* Destructor */
  ~Dynamic_steering_control_obs_ctrlModelClass();

  /* private data and function members */
 private:
  /* Block signals */
  B_Dynamic_steering_control_ob_T Dynamic_steering_control_obs__B;

  /* Block continuous states */
  X_Dynamic_steering_control_ob_T Dynamic_steering_control_obs__X;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void Dynamic_steering_control_obs_ctrl_derivatives();

  /* Real-Time Model */
  RT_MODEL_Dynamic_steering_con_T Dynamic_steering_control_obs_M;
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/input' : Unused code path elimination
 * Block '<Root>/vy' : Unused code path elimination
 * Block '<Root>/w' : Unused code path elimination
 * Block '<S2>/Manual Switch' : Eliminated due to constant selection input
 * Block '<Root>/ref' : Eliminated due to constant selection input
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<Root>/meas. dist.' : Unused code path elimination
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
 * '<Root>' : 'Dynamic_steering_control_obs_ctrl'
 * '<S1>'   : 'Dynamic_steering_control_obs_ctrl/(vy^,w^) Observer'
 * '<S2>'   : 'Dynamic_steering_control_obs_ctrl/Controller'
 */
#endif                     /* RTW_HEADER_Dynamic_steering_control_obs_ctrl_h_ */
