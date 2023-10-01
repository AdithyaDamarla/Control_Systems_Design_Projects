/*
 * Cart_pendulum_sim.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Cart_pendulum_sim".
 *
 * Model version              : 1.276
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sun Oct  1 14:40:07 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Cart_pendulum_sim.h"
#include "Cart_pendulum_sim_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void Cart_pendulum_simModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *
  si )
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
  Cart_pendulum_sim_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Cart_pendulum_sim_derivatives();

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
  Cart_pendulum_sim_derivatives();

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
void Cart_pendulum_simModelClass::step()
{
  real_T rtb_Add;
  if (rtmIsMajorTimeStep((&Cart_pendulum_sim_M))) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&(&Cart_pendulum_sim_M)->solverInfo,
                          (((&Cart_pendulum_sim_M)->Timing.clockTick0+1)*
      (&Cart_pendulum_sim_M)->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Cart_pendulum_sim_M))) {
    (&Cart_pendulum_sim_M)->Timing.t[0] = rtsiGetT(&(&Cart_pendulum_sim_M)
      ->solverInfo);
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain2'
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S1>/Integrator2'
   *  Integrator: '<S1>/Integrator3'
   */
  rtb_Add = (((0.0 * Cart_pendulum_sim_X.Integrator_CSTATE + 0.0 *
               Cart_pendulum_sim_X.Integrator1_CSTATE) + 0.0 *
              Cart_pendulum_sim_X.Integrator2_CSTATE) + 0.0 *
             Cart_pendulum_sim_X.Integrator3_CSTATE) + (((0.10000000000007495 *
    Cart_pendulum_sim_X.Integrator_CSTATE + -1796.15833256202 *
    Cart_pendulum_sim_X.Integrator1_CSTATE) + 4.5346693790279611 *
    Cart_pendulum_sim_X.Integrator2_CSTATE) + -673.31122169671482 *
    Cart_pendulum_sim_X.Integrator3_CSTATE);
  for (int32_T i{0}; i < 4; i++) {
    /* Sum: '<S1>/Add' incorporates:
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Gain1'
     *  Integrator: '<S1>/Integrator'
     *  Integrator: '<S1>/Integrator1'
     *  Integrator: '<S1>/Integrator2'
     *  Integrator: '<S1>/Integrator3'
     */
    Cart_pendulum_sim_B.Add[i] = (((Cart_pendulum_sim_ConstP.Gain_Gain[i + 4] *
      Cart_pendulum_sim_X.Integrator1_CSTATE +
      Cart_pendulum_sim_ConstP.Gain_Gain[i] *
      Cart_pendulum_sim_X.Integrator_CSTATE) +
      Cart_pendulum_sim_ConstP.Gain_Gain[i + 8] *
      Cart_pendulum_sim_X.Integrator2_CSTATE) +
      Cart_pendulum_sim_ConstP.Gain_Gain[i + 12] *
      Cart_pendulum_sim_X.Integrator3_CSTATE) +
      Cart_pendulum_sim_ConstP.Gain1_Gain_h[i] * rtb_Add;
  }

  if (rtmIsMajorTimeStep((&Cart_pendulum_sim_M))) {
    rt_ertODEUpdateContinuousStates(&(&Cart_pendulum_sim_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++(&Cart_pendulum_sim_M)->Timing.clockTick0;
    (&Cart_pendulum_sim_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&Cart_pendulum_sim_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      (&Cart_pendulum_sim_M)->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Cart_pendulum_simModelClass::Cart_pendulum_sim_derivatives()
{
  XDot_Cart_pendulum_sim_T *_rtXdot;
  _rtXdot = ((XDot_Cart_pendulum_sim_T *) (&Cart_pendulum_sim_M)->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = Cart_pendulum_sim_B.Add[0];

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Cart_pendulum_sim_B.Add[1];

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Cart_pendulum_sim_B.Add[2];

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = Cart_pendulum_sim_B.Add[3];
}

/* Model initialize function */
void Cart_pendulum_simModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Cart_pendulum_sim_M)->solverInfo,
                          &(&Cart_pendulum_sim_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&Cart_pendulum_sim_M)->solverInfo, &rtmGetTPtr
                ((&Cart_pendulum_sim_M)));
    rtsiSetStepSizePtr(&(&Cart_pendulum_sim_M)->solverInfo,
                       &(&Cart_pendulum_sim_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Cart_pendulum_sim_M)->solverInfo, &(&Cart_pendulum_sim_M)
                 ->derivs);
    rtsiSetContStatesPtr(&(&Cart_pendulum_sim_M)->solverInfo, (real_T **)
                         &(&Cart_pendulum_sim_M)->contStates);
    rtsiSetNumContStatesPtr(&(&Cart_pendulum_sim_M)->solverInfo,
      &(&Cart_pendulum_sim_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Cart_pendulum_sim_M)->solverInfo,
      &(&Cart_pendulum_sim_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Cart_pendulum_sim_M)->solverInfo,
      &(&Cart_pendulum_sim_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Cart_pendulum_sim_M)->solverInfo,
      &(&Cart_pendulum_sim_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Cart_pendulum_sim_M)->solverInfo,
                          (&rtmGetErrorStatus((&Cart_pendulum_sim_M))));
    rtsiSetRTModelPtr(&(&Cart_pendulum_sim_M)->solverInfo, (&Cart_pendulum_sim_M));
  }

  rtsiSetSimTimeStep(&(&Cart_pendulum_sim_M)->solverInfo, MAJOR_TIME_STEP);
  (&Cart_pendulum_sim_M)->intgData.y = (&Cart_pendulum_sim_M)->odeY;
  (&Cart_pendulum_sim_M)->intgData.f[0] = (&Cart_pendulum_sim_M)->odeF[0];
  (&Cart_pendulum_sim_M)->intgData.f[1] = (&Cart_pendulum_sim_M)->odeF[1];
  (&Cart_pendulum_sim_M)->intgData.f[2] = (&Cart_pendulum_sim_M)->odeF[2];
  (&Cart_pendulum_sim_M)->contStates = ((X_Cart_pendulum_sim_T *)
    &Cart_pendulum_sim_X);
  rtsiSetSolverData(&(&Cart_pendulum_sim_M)->solverInfo, static_cast<void *>
                    (&(&Cart_pendulum_sim_M)->intgData));
  rtsiSetSolverName(&(&Cart_pendulum_sim_M)->solverInfo,"ode3");
  rtmSetTPtr((&Cart_pendulum_sim_M), &(&Cart_pendulum_sim_M)->Timing.tArray[0]);
  (&Cart_pendulum_sim_M)->Timing.stepSize0 = 0.001;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Cart_pendulum_sim_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  Cart_pendulum_sim_X.Integrator1_CSTATE = 0.017453292519943295;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  Cart_pendulum_sim_X.Integrator2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  Cart_pendulum_sim_X.Integrator3_CSTATE = 0.0;
}

/* Model terminate function */
void Cart_pendulum_simModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Cart_pendulum_simModelClass::Cart_pendulum_simModelClass() :
  Cart_pendulum_sim_B(),
  Cart_pendulum_sim_X(),
  Cart_pendulum_sim_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
Cart_pendulum_simModelClass::~Cart_pendulum_simModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Cart_pendulum_sim_T * Cart_pendulum_simModelClass::getRTM()
{
  return (&Cart_pendulum_sim_M);
}
