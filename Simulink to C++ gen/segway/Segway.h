/*
 * Segway.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Segway".
 *
 * Model version              : 1.261
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sun Oct  1 14:46:30 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Segway_h_
#define RTW_HEADER_Segway_h_
#include <cmath>
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Segway_types.h"

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

/* Block signals (default storage) */
struct B_Segway_T {
  real_T z_1d[2];                      /* '<S2>/Integrator' */
  real_T VectorConcatenate[9];         /* '<S8>/Vector Concatenate' */
  real_T Submatrix[4];                 /* '<S5>/Submatrix' */
  real_T z_2d[2];                      /* '<S2>/Matrix Multiply' */
  real_T Add;                          /* '<S7>/Add' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_Segway_T {
  int_T Integrator_IWORK;              /* '<S7>/Integrator' */
};

/* Continuous states (default storage) */
struct X_Segway_T {
  real_T Integrator1_CSTATE[2];        /* '<S2>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S7>/Integrator' */
  real_T TransferFcn1_CSTATE;          /* '<S3>/Transfer Fcn1' */
};

/* State derivatives (default storage) */
struct XDot_Segway_T {
  real_T Integrator1_CSTATE[2];        /* '<S2>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S7>/Integrator' */
  real_T TransferFcn1_CSTATE;          /* '<S3>/Transfer Fcn1' */
};

/* State disabled  */
struct XDis_Segway_T {
  boolean_T Integrator1_CSTATE[2];     /* '<S2>/Integrator1' */
  boolean_T Integrator_CSTATE[2];      /* '<S2>/Integrator' */
  boolean_T Integrator_CSTATE_m;       /* '<S7>/Integrator' */
  boolean_T TransferFcn1_CSTATE;       /* '<S3>/Transfer Fcn1' */
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
struct tag_RTM_Segway_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Segway_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
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
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Class declaration for model Segway */
class SegwayModelClass
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  SegwayModelClass(SegwayModelClass const&) =delete;

  /* Assignment Operator */
  SegwayModelClass& operator= (SegwayModelClass const&) & = delete;

  /* Real-Time Model get method */
  RT_MODEL_Segway_T * getRTM();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  SegwayModelClass();

  /* Destructor */
  ~SegwayModelClass();

  /* private data and function members */
 private:
  /* Block signals */
  B_Segway_T Segway_B;

  /* Block states */
  DW_Segway_T Segway_DW;

  /* Block continuous states */
  X_Segway_T Segway_X;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void Segway_derivatives();

  /* Real-Time Model */
  RT_MODEL_Segway_T Segway_M;
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Clock' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S2>/Gain' : Unused code path elimination
 * Block '<S2>/To Workspace' : Unused code path elimination
 * Block '<S2>/ax' : Unused code path elimination
 * Block '<S2>/vx_exp' : Unused code path elimination
 * Block '<S2>/x [m]' : Unused code path elimination
 * Block '<Root>/[Phi,Phi_r]' : Unused code path elimination
 * Block '<Root>/[vx,Phi]' : Unused code path elimination
 * Block '<Root>/control' : Unused code path elimination
 * Block '<Root>/reference' : Unused code path elimination
 * Block '<Root>/state tracking [yr,y]' : Unused code path elimination
 * Block '<Root>/vx [km//h]' : Unused code path elimination
 * Block '<Root>/w' : Unused code path elimination
 * Block '<S1>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain12' : Eliminated nontunable gain of 1
 * Block '<S8>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S7>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S3>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/Constant2' : Unused code path elimination
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
 * '<Root>' : 'Segway'
 * '<S1>'   : 'Segway/F.L. Controller'
 * '<S2>'   : 'Segway/Segway nonlinear model'
 * '<S3>'   : 'Segway/references'
 * '<S4>'   : 'Segway/F.L. Controller/u_FF+u_FB'
 * '<S5>'   : 'Segway/Segway nonlinear model/M(q)^-1'
 * '<S6>'   : 'Segway/Segway nonlinear model/[-y+u]_dynamics'
 * '<S7>'   : 'Segway/Segway nonlinear model/x_residual'
 * '<S8>'   : 'Segway/Segway nonlinear model/M(q)^-1/Create 3x3 Matrix'
 * '<S9>'   : 'Segway/Segway nonlinear model/M(q)^-1/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Segway_h_ */
