/*
 * Active_suspension_with_control_sim2.cpp
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

#include "Active_suspension_with_control_sim2.h"
#include "Active_suspension_with_control_sim2_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void Active_suspension_with_control_sim2ModelClass::
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
  int_T nXc { 8 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Active_suspension_with_control_sim2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Active_suspension_with_control_sim2_derivatives();

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
  Active_suspension_with_control_sim2_derivatives();

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
void Active_suspension_with_control_sim2ModelClass::step()
{
  real_T rtb_PIEngineeringDerivative;
  real_T y_2dot_tmp;
  real_T y_2dot_tmp_0;
  int32_T tmp;
  int32_T tmp_0;
  if (rtmIsMajorTimeStep((&Active_suspension_with_contr_M))) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&(&Active_suspension_with_contr_M)->solverInfo,
                          (((&Active_suspension_with_contr_M)->Timing.clockTick0
      +1)*(&Active_suspension_with_contr_M)->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Active_suspension_with_contr_M))) {
    (&Active_suspension_with_contr_M)->Timing.t[0] = rtsiGetT
      (&(&Active_suspension_with_contr_M)->solverInfo);
  }

  /* Integrator: '<S1>/Integrator' */
  Active_suspension_with_contro_B.y_dot =
    Active_suspension_with_contro_X.Integrator_CSTATE_a;

  /* Integrator: '<S2>/Integrator' */
  Active_suspension_with_contro_B.x_dot =
    Active_suspension_with_contro_X.Integrator_CSTATE_o;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  Integrator: '<S1>/Integrator1'
   */
  Active_suspension_with_contro_B.Sum =
    Active_suspension_with_contro_X.Integrator1_CSTATE - -0.025;

  /* TransferFcn: '<S5>/P.I.+Engineering Derivative' */
  rtb_PIEngineeringDerivative = (-10937.267263752379 *
    Active_suspension_with_contro_X.PIEngineeringDerivative_CSTATE[0] +
    -159154.94309189534 *
    Active_suspension_with_contro_X.PIEngineeringDerivative_CSTATE[1]) +
    14487.500000000002 * Active_suspension_with_contro_B.Sum;

  /* Step: '<S4>/disturbance' incorporates:
   *  Step: '<S4>/disturbance1'
   */
  y_2dot_tmp = (&Active_suspension_with_contr_M)->Timing.t[0];
  if (y_2dot_tmp < 5.0) {
    tmp = 0;
  } else {
    tmp = 140;
  }

  /* End of Step: '<S4>/disturbance' */

  /* Step: '<S4>/disturbance1' */
  if (y_2dot_tmp < 6.0) {
    tmp_0 = 0;
  } else {
    tmp_0 = -140;
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S2>/Integrator1'
   *  Sum: '<S1>/Sum3'
   */
  y_2dot_tmp = (Active_suspension_with_contro_X.Integrator1_CSTATE -
                Active_suspension_with_contro_X.Integrator1_CSTATE_i) * 20000.0;

  /* Gain: '<S1>/Gain' incorporates:
   *  Gain: '<S2>/Gain4'
   *  Sum: '<S1>/Sum4'
   */
  y_2dot_tmp_0 = (Active_suspension_with_contro_B.y_dot -
                  Active_suspension_with_contro_B.x_dot) * 1171.0;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S4>/Add'
   */
  Active_suspension_with_contro_B.y_2dot = (((rtb_PIEngineeringDerivative -
    y_2dot_tmp_0) - y_2dot_tmp) + (-1373.4 - static_cast<real_T>(tmp + tmp_0))) *
    0.0071428571428571426;

  /* Gain: '<S2>/Gain2' incorporates:
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain3'
   *  Integrator: '<Root>/Integrator'
   *  Integrator: '<S2>/Integrator1'
   *  Sum: '<S2>/Add'
   *  Sum: '<S2>/Sum1'
   *  Sum: '<S2>/Sum4'
   */
  Active_suspension_with_contro_B.x_2dot = ((((y_2dot_tmp - 100.0 *
    Active_suspension_with_contro_B.x_dot) + y_2dot_tmp_0) -
    (Active_suspension_with_contro_X.Integrator1_CSTATE_i -
     Active_suspension_with_contro_X.Integrator_CSTATE) * 130000.0) -
    rtb_PIEngineeringDerivative) * 0.02;
  if (rtmIsMajorTimeStep((&Active_suspension_with_contr_M))) {
    rt_ertODEUpdateContinuousStates(&(&Active_suspension_with_contr_M)
      ->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++(&Active_suspension_with_contr_M)->Timing.clockTick0;
    (&Active_suspension_with_contr_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&Active_suspension_with_contr_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      (&Active_suspension_with_contr_M)->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Active_suspension_with_control_sim2ModelClass::
  Active_suspension_with_control_sim2_derivatives()
{
  XDot_Active_suspension_with_c_T *_rtXdot;
  _rtXdot = ((XDot_Active_suspension_with_c_T *)
             (&Active_suspension_with_contr_M)->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = 0.0;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = Active_suspension_with_contro_B.y_2dot;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_o = Active_suspension_with_contro_B.x_2dot;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Active_suspension_with_contro_B.y_dot;

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_i = Active_suspension_with_contro_B.x_dot;

  /* Derivatives for TransferFcn: '<S5>/P.I.+Engineering Derivative' */
  _rtXdot->PIEngineeringDerivative_CSTATE[0] = 0.0;
  _rtXdot->PIEngineeringDerivative_CSTATE[0] += -15.915494309189533 *
    Active_suspension_with_contro_X.PIEngineeringDerivative_CSTATE[0];
  _rtXdot->PIEngineeringDerivative_CSTATE[1] = 0.0;
  _rtXdot->PIEngineeringDerivative_CSTATE[0] += -0.0 *
    Active_suspension_with_contro_X.PIEngineeringDerivative_CSTATE[1];
  _rtXdot->PIEngineeringDerivative_CSTATE[1] +=
    Active_suspension_with_contro_X.PIEngineeringDerivative_CSTATE[0];
  _rtXdot->PIEngineeringDerivative_CSTATE[0] +=
    Active_suspension_with_contro_B.Sum;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = Active_suspension_with_contro_B.Sum;
}

/* Model initialize function */
void Active_suspension_with_control_sim2ModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Active_suspension_with_contr_M)->solverInfo,
                          &(&Active_suspension_with_contr_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&Active_suspension_with_contr_M)->solverInfo, &rtmGetTPtr
                ((&Active_suspension_with_contr_M)));
    rtsiSetStepSizePtr(&(&Active_suspension_with_contr_M)->solverInfo,
                       &(&Active_suspension_with_contr_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Active_suspension_with_contr_M)->solverInfo,
                 &(&Active_suspension_with_contr_M)->derivs);
    rtsiSetContStatesPtr(&(&Active_suspension_with_contr_M)->solverInfo, (real_T
      **) &(&Active_suspension_with_contr_M)->contStates);
    rtsiSetNumContStatesPtr(&(&Active_suspension_with_contr_M)->solverInfo,
      &(&Active_suspension_with_contr_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Active_suspension_with_contr_M)
      ->solverInfo, &(&Active_suspension_with_contr_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Active_suspension_with_contr_M)
      ->solverInfo, &(&Active_suspension_with_contr_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Active_suspension_with_contr_M)
      ->solverInfo, &(&Active_suspension_with_contr_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Active_suspension_with_contr_M)->solverInfo,
                          (&rtmGetErrorStatus((&Active_suspension_with_contr_M))));
    rtsiSetRTModelPtr(&(&Active_suspension_with_contr_M)->solverInfo,
                      (&Active_suspension_with_contr_M));
  }

  rtsiSetSimTimeStep(&(&Active_suspension_with_contr_M)->solverInfo,
                     MAJOR_TIME_STEP);
  (&Active_suspension_with_contr_M)->intgData.y =
    (&Active_suspension_with_contr_M)->odeY;
  (&Active_suspension_with_contr_M)->intgData.f[0] =
    (&Active_suspension_with_contr_M)->odeF[0];
  (&Active_suspension_with_contr_M)->intgData.f[1] =
    (&Active_suspension_with_contr_M)->odeF[1];
  (&Active_suspension_with_contr_M)->intgData.f[2] =
    (&Active_suspension_with_contr_M)->odeF[2];
  (&Active_suspension_with_contr_M)->contStates =
    ((X_Active_suspension_with_cont_T *) &Active_suspension_with_contro_X);
  rtsiSetSolverData(&(&Active_suspension_with_contr_M)->solverInfo, static_cast<
                    void *>(&(&Active_suspension_with_contr_M)->intgData));
  rtsiSetSolverName(&(&Active_suspension_with_contr_M)->solverInfo,"ode3");
  rtmSetTPtr((&Active_suspension_with_contr_M),
             &(&Active_suspension_with_contr_M)->Timing.tArray[0]);
  (&Active_suspension_with_contr_M)->Timing.stepSize0 = 0.0001;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Active_suspension_with_contro_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Active_suspension_with_contro_X.Integrator_CSTATE_a = 0.0;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Active_suspension_with_contro_X.Integrator_CSTATE_o = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  Active_suspension_with_contro_X.Integrator1_CSTATE = -0.05;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  Active_suspension_with_contro_X.Integrator1_CSTATE_i = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/P.I.+Engineering Derivative' */
  Active_suspension_with_contro_X.PIEngineeringDerivative_CSTATE[0] = 0.0;
  Active_suspension_with_contro_X.PIEngineeringDerivative_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  Active_suspension_with_contro_X.Integrator_CSTATE_c = 0.0;
}

/* Model terminate function */
void Active_suspension_with_control_sim2ModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Active_suspension_with_control_sim2ModelClass::
  Active_suspension_with_control_sim2ModelClass() :
  Active_suspension_with_contro_B(),
  Active_suspension_with_contro_X(),
  Active_suspension_with_contr_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
Active_suspension_with_control_sim2ModelClass::
  ~Active_suspension_with_control_sim2ModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Active_suspension_wi_T * Active_suspension_with_control_sim2ModelClass::
  getRTM()
{
  return (&Active_suspension_with_contr_M);
}
