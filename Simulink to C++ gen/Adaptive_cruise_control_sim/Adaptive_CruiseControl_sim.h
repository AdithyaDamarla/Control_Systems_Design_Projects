/*
 * Adaptive_CruiseControl_sim.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Adaptive_CruiseControl_sim".
 *
 * Model version              : 1.115
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sun Oct  1 14:07:22 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Adaptive_CruiseControl_sim_h_
#define RTW_HEADER_Adaptive_CruiseControl_sim_h_
#include <cmath>
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Adaptive_CruiseControl_sim_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

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

/* Block signals (default storage) */
struct B_Adaptive_CruiseControl_sim_T {
  real_T v;                            /* '<S1>/Integrator' */
  real_T v2;                           /* '<S4>/Integrator' */
  real_T Sum[2];                       /* '<Root>/Sum' */
  real_T Saturation;                   /* '<S5>/Saturation' */
  real_T IndexVector;                  /* '<S5>/Index Vector' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Sum3;                         /* '<S5>/Sum3' */
  real_T uur;                          /* '<S11>/Add' */
  real_T Add;                          /* '<S4>/Add' */
  real_T a2;                           /* '<S4>/Gain1' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_Adaptive_CruiseControl_sim_T {
  real_T Memory_PreviousInput;         /* '<S5>/Memory' */
};

/* Continuous states (default storage) */
struct X_Adaptive_CruiseControl_sim_T {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE_n;          /* '<S4>/Integrator' */
  real_T Integrator1_CSTATE_f;         /* '<S1>/Integrator1' */
  real_T Integrator_CSTATE_ed;         /* '<S11>/Integrator' */
  real_T Integrator_CSTATE_np;         /* '<S2>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S4>/Transfer Fcn' */
};

/* State derivatives (default storage) */
struct XDot_Adaptive_CruiseControl_s_T {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE_n;          /* '<S4>/Integrator' */
  real_T Integrator1_CSTATE_f;         /* '<S1>/Integrator1' */
  real_T Integrator_CSTATE_ed;         /* '<S11>/Integrator' */
  real_T Integrator_CSTATE_np;         /* '<S2>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S4>/Transfer Fcn' */
};

/* State disabled  */
struct XDis_Adaptive_CruiseControl_s_T {
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S6>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S4>/Integrator1' */
  boolean_T Integrator_CSTATE_n;       /* '<S4>/Integrator' */
  boolean_T Integrator1_CSTATE_f;      /* '<S1>/Integrator1' */
  boolean_T Integrator_CSTATE_ed;      /* '<S11>/Integrator' */
  boolean_T Integrator_CSTATE_np;      /* '<S2>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<S4>/Transfer Fcn' */
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
struct tag_RTM_Adaptive_CruiseContro_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Adaptive_CruiseControl_sim_T *contStates;
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

/* Class declaration for model Adaptive_CruiseControl_sim */
class Adaptive_CruiseControl_simModelClass
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  Adaptive_CruiseControl_simModelClass(Adaptive_CruiseControl_simModelClass
    const&) =delete;

  /* Assignment Operator */
  Adaptive_CruiseControl_simModelClass& operator=
    (Adaptive_CruiseControl_simModelClass const&) & = delete;

  /* Real-Time Model get method */
  RT_MODEL_Adaptive_CruiseContr_T * getRTM();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  Adaptive_CruiseControl_simModelClass();

  /* Destructor */
  ~Adaptive_CruiseControl_simModelClass();

  /* private data and function members */
 private:
  /* Block signals */
  B_Adaptive_CruiseControl_sim_T Adaptive_CruiseControl_sim_B;

  /* Block states */
  DW_Adaptive_CruiseControl_sim_T Adaptive_CruiseControl_sim_DW;

  /* Block continuous states */
  X_Adaptive_CruiseControl_sim_T Adaptive_CruiseControl_sim_X;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void Adaptive_CruiseControl_sim_derivatives();

  /* Real-Time Model */
  RT_MODEL_Adaptive_CruiseContr_T Adaptive_CruiseControl_sim_M;
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Add' : Unused code path elimination
 * Block '<Root>/Add1' : Unused code path elimination
 * Block '<Root>/Clock' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<S11>/Anti Windup' : Unused code path elimination
 * Block '<S2>/Gears' : Unused code path elimination
 * Block '<S7>/motor' : Unused code path elimination
 * Block '<S2>/motor control' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S3>/Step' : Unused code path elimination
 * Block '<Root>/Forces' : Unused code path elimination
 * Block '<Root>/Gain1' : Unused code path elimination
 * Block '<Root>/Gain2' : Unused code path elimination
 * Block '<Root>/Gain3' : Unused code path elimination
 * Block '<Root>/Gain4' : Unused code path elimination
 * Block '<Root>/Speed' : Unused code path elimination
 * Block '<Root>/distance' : Unused code path elimination
 * Block '<Root>/throttle&brake' : Unused code path elimination
 * Block '<Root>/x1' : Unused code path elimination
 * Block '<S5>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S6>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S2>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S2>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S8>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S4>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S5>/Constant6' : Unused code path elimination
 * Block '<S2>/Saturation1' : Unused code path elimination
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
 * '<Root>' : 'Adaptive_CruiseControl_sim'
 * '<S1>'   : 'Adaptive_CruiseControl_sim/Body'
 * '<S2>'   : 'Adaptive_CruiseControl_sim/Controller+Actuator'
 * '<S3>'   : 'Adaptive_CruiseControl_sim/Disturbance forces'
 * '<S4>'   : 'Adaptive_CruiseControl_sim/vehicle 2'
 * '<S5>'   : 'Adaptive_CruiseControl_sim/Controller+Actuator/Automatic Gear Selector'
 * '<S6>'   : 'Adaptive_CruiseControl_sim/Controller+Actuator/Controller+Anti Windup'
 * '<S7>'   : 'Adaptive_CruiseControl_sim/Controller+Actuator/Motor'
 * '<S8>'   : 'Adaptive_CruiseControl_sim/Controller+Actuator/brakes'
 * '<S9>'   : 'Adaptive_CruiseControl_sim/Controller+Actuator/Automatic Gear Selector/Compare To Constant'
 * '<S10>'  : 'Adaptive_CruiseControl_sim/Controller+Actuator/Automatic Gear Selector/Compare To Constant1'
 * '<S11>'  : 'Adaptive_CruiseControl_sim/Controller+Actuator/Controller+Anti Windup/Anti wind-up'
 */
#endif                            /* RTW_HEADER_Adaptive_CruiseControl_sim_h_ */
