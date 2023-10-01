/*
 * Dynamic_steering_control_obs_ctrl.cpp
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

#include "Dynamic_steering_control_obs_ctrl.h"
#include "Dynamic_steering_control_obs_ctrl_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void Dynamic_steering_control_obs_ctrlModelClass::
  rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3]{
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3]{
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE3_IntgData *id { static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T hB[3];
  int_T i;
  int_T nXc { 4 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Dynamic_steering_control_obs_ctrl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Dynamic_steering_control_obs_ctrl_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  Dynamic_steering_control_obs_ctrl_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Dynamic_steering_control_obs_ctrlModelClass::step()
{
  real_T rtb_deltavyw;
  if (rtmIsMajorTimeStep((&Dynamic_steering_control_obs_M))) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&(&Dynamic_steering_control_obs_M)->solverInfo,
                          (((&Dynamic_steering_control_obs_M)->Timing.clockTick0
      +1)*(&Dynamic_steering_control_obs_M)->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Dynamic_steering_control_obs_M))) {
    (&Dynamic_steering_control_obs_M)->Timing.t[0] = rtsiGetT
      (&(&Dynamic_steering_control_obs_M)->solverInfo);
  }

  /* Sum: '<S2>/Add1' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain3'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S1>/Integrator3'
   */
  rtb_deltavyw = 0.11392798801616365 *
    Dynamic_steering_control_obs__X.Integrator1_CSTATE + -0.14790270450610446 *
    Dynamic_steering_control_obs__X.Integrator3_CSTATE;

  /* Sum: '<S1>/Add' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain4'
   *  Gain: '<S1>/Gain7'
   *  Integrator: '<Root>/Integrator3'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S1>/Integrator3'
   */
  Dynamic_steering_control_obs__B.vy_dot = ((54.506437768240346 * rtb_deltavyw -
    10.152360515021458 * Dynamic_steering_control_obs__X.Integrator1_CSTATE) -
    244.83260030508492 * Dynamic_steering_control_obs__X.Integrator3_CSTATE) -
    -232.31185638519938 * Dynamic_steering_control_obs__X.Integrator3_CSTATE_f;

  /* Sum: '<S1>/Add1' incorporates:
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain5'
   *  Gain: '<S1>/Gain6'
   *  Gain: '<S1>/Gain8'
   *  Integrator: '<Root>/Integrator3'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S1>/Integrator3'
   */
  Dynamic_steering_control_obs__B.w_dot = ((41.98576902025178 * rtb_deltavyw -
    -20.073268232591243 * Dynamic_steering_control_obs__X.Integrator3_CSTATE_f)
    + 2.1149425287356318 * Dynamic_steering_control_obs__X.Integrator1_CSTATE) -
    29.994175950161029 * Dynamic_steering_control_obs__X.Integrator3_CSTATE;

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain4'
   *  Integrator: '<Root>/Integrator1'
   *  Integrator: '<Root>/Integrator3'
   */
  Dynamic_steering_control_obs__B.vy_dot_k = (54.506437768240346 * rtb_deltavyw
    - 10.152360515021458 * Dynamic_steering_control_obs__X.Integrator1_CSTATE_o)
    - 12.520743919885552 * Dynamic_steering_control_obs__X.Integrator3_CSTATE_f;

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/Gain6'
   *  Integrator: '<Root>/Integrator1'
   *  Integrator: '<Root>/Integrator3'
   */
  Dynamic_steering_control_obs__B.w_dot_c = (41.98576902025178 * rtb_deltavyw +
    2.1149425287356318 * Dynamic_steering_control_obs__X.Integrator1_CSTATE_o) -
    9.9209077175697864 * Dynamic_steering_control_obs__X.Integrator3_CSTATE_f;
  if (rtmIsMajorTimeStep((&Dynamic_steering_control_obs_M))) {
    rt_ertODEUpdateContinuousStates(&(&Dynamic_steering_control_obs_M)
      ->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++(&Dynamic_steering_control_obs_M)->Timing.clockTick0;
    (&Dynamic_steering_control_obs_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&Dynamic_steering_control_obs_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      (&Dynamic_steering_control_obs_M)->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Dynamic_steering_control_obs_ctrlModelClass::
  Dynamic_steering_control_obs_ctrl_derivatives()
{
  XDot_Dynamic_steering_control_T *_rtXdot;
  _rtXdot = ((XDot_Dynamic_steering_control_T *)
             (&Dynamic_steering_control_obs_M)->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Dynamic_steering_control_obs__B.vy_dot;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = Dynamic_steering_control_obs__B.w_dot;

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE_f = Dynamic_steering_control_obs__B.w_dot_c;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_o = Dynamic_steering_control_obs__B.vy_dot_k;
}

/* Model initialize function */
void Dynamic_steering_control_obs_ctrlModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Dynamic_steering_control_obs_M)->solverInfo,
                          &(&Dynamic_steering_control_obs_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&Dynamic_steering_control_obs_M)->solverInfo, &rtmGetTPtr
                ((&Dynamic_steering_control_obs_M)));
    rtsiSetStepSizePtr(&(&Dynamic_steering_control_obs_M)->solverInfo,
                       &(&Dynamic_steering_control_obs_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Dynamic_steering_control_obs_M)->solverInfo,
                 &(&Dynamic_steering_control_obs_M)->derivs);
    rtsiSetContStatesPtr(&(&Dynamic_steering_control_obs_M)->solverInfo, (real_T
      **) &(&Dynamic_steering_control_obs_M)->contStates);
    rtsiSetNumContStatesPtr(&(&Dynamic_steering_control_obs_M)->solverInfo,
      &(&Dynamic_steering_control_obs_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Dynamic_steering_control_obs_M)
      ->solverInfo, &(&Dynamic_steering_control_obs_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Dynamic_steering_control_obs_M)
      ->solverInfo, &(&Dynamic_steering_control_obs_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Dynamic_steering_control_obs_M)
      ->solverInfo, &(&Dynamic_steering_control_obs_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Dynamic_steering_control_obs_M)->solverInfo,
                          (&rtmGetErrorStatus((&Dynamic_steering_control_obs_M))));
    rtsiSetRTModelPtr(&(&Dynamic_steering_control_obs_M)->solverInfo,
                      (&Dynamic_steering_control_obs_M));
  }

  rtsiSetSimTimeStep(&(&Dynamic_steering_control_obs_M)->solverInfo,
                     MAJOR_TIME_STEP);
  (&Dynamic_steering_control_obs_M)->intgData.y =
    (&Dynamic_steering_control_obs_M)->odeY;
  (&Dynamic_steering_control_obs_M)->intgData.f[0] =
    (&Dynamic_steering_control_obs_M)->odeF[0];
  (&Dynamic_steering_control_obs_M)->intgData.f[1] =
    (&Dynamic_steering_control_obs_M)->odeF[1];
  (&Dynamic_steering_control_obs_M)->intgData.f[2] =
    (&Dynamic_steering_control_obs_M)->odeF[2];
  (&Dynamic_steering_control_obs_M)->contStates =
    ((X_Dynamic_steering_control_ob_T *) &Dynamic_steering_control_obs__X);
  rtsiSetSolverData(&(&Dynamic_steering_control_obs_M)->solverInfo, static_cast<
                    void *>(&(&Dynamic_steering_control_obs_M)->intgData));
  rtsiSetSolverName(&(&Dynamic_steering_control_obs_M)->solverInfo,"ode3");
  rtmSetTPtr((&Dynamic_steering_control_obs_M),
             &(&Dynamic_steering_control_obs_M)->Timing.tArray[0]);
  (&Dynamic_steering_control_obs_M)->Timing.stepSize0 = 0.0001;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  Dynamic_steering_control_obs__X.Integrator1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  Dynamic_steering_control_obs__X.Integrator3_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  Dynamic_steering_control_obs__X.Integrator3_CSTATE_f = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  Dynamic_steering_control_obs__X.Integrator1_CSTATE_o = 2.0;
}

/* Model terminate function */
void Dynamic_steering_control_obs_ctrlModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Dynamic_steering_control_obs_ctrlModelClass::
  Dynamic_steering_control_obs_ctrlModelClass() :
  Dynamic_steering_control_obs__B(),
  Dynamic_steering_control_obs__X(),
  Dynamic_steering_control_obs_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
Dynamic_steering_control_obs_ctrlModelClass::
  ~Dynamic_steering_control_obs_ctrlModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Dynamic_steering_con_T * Dynamic_steering_control_obs_ctrlModelClass::
  getRTM()
{
  return (&Dynamic_steering_control_obs_M);
}
