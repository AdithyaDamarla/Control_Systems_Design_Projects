/*
 * Active_suspension_sim.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Active_suspension_sim".
 *
 * Model version              : 1.34
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sun Oct  1 11:56:16 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Active_suspension_sim.h"
#include "Active_suspension_sim_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void Active_suspension_simModelClass::rt_ertODEUpdateContinuousStates
  (RTWSolverInfo *si )
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
  int_T nXc { 2 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Active_suspension_sim_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Active_suspension_sim_derivatives();

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
  Active_suspension_sim_derivatives();

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
void Active_suspension_simModelClass::step()
{
  if (rtmIsMajorTimeStep((&Active_suspension_sim_M))) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&(&Active_suspension_sim_M)->solverInfo,
                          (((&Active_suspension_sim_M)->Timing.clockTick0+1)*
      (&Active_suspension_sim_M)->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Active_suspension_sim_M))) {
    (&Active_suspension_sim_M)->Timing.t[0] = rtsiGetT
      (&(&Active_suspension_sim_M)->solverInfo);
  }

  /* Integrator: '<Root>/Integrator' */
  Active_suspension_sim_B.y_dot = Active_suspension_sim_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep((&Active_suspension_sim_M))) {
    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Sum: '<Root>/Sum1'
     */
    Active_suspension_sim_B.Sum2 = -1373.4;
  }

  /* Gain: '<Root>/Gain2' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Integrator: '<Root>/Integrator1'
   *  Sum: '<Root>/Add'
   */
  Active_suspension_sim_B.y_2dot = ((Active_suspension_sim_B.Sum2 - 1171.0 *
    Active_suspension_sim_B.y_dot) - 20000.0 *
    Active_suspension_sim_X.Integrator1_CSTATE) * 0.0071428571428571426;
  if (rtmIsMajorTimeStep((&Active_suspension_sim_M))) {
    rt_ertODEUpdateContinuousStates(&(&Active_suspension_sim_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++(&Active_suspension_sim_M)->Timing.clockTick0;
    (&Active_suspension_sim_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&Active_suspension_sim_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      (&Active_suspension_sim_M)->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Active_suspension_simModelClass::Active_suspension_sim_derivatives()
{
  XDot_Active_suspension_sim_T *_rtXdot;
  _rtXdot = ((XDot_Active_suspension_sim_T *) (&Active_suspension_sim_M)->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Active_suspension_sim_B.y_2dot;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Active_suspension_sim_B.y_dot;
}

/* Model initialize function */
void Active_suspension_simModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Active_suspension_sim_M)->solverInfo,
                          &(&Active_suspension_sim_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&Active_suspension_sim_M)->solverInfo, &rtmGetTPtr
                ((&Active_suspension_sim_M)));
    rtsiSetStepSizePtr(&(&Active_suspension_sim_M)->solverInfo,
                       &(&Active_suspension_sim_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Active_suspension_sim_M)->solverInfo,
                 &(&Active_suspension_sim_M)->derivs);
    rtsiSetContStatesPtr(&(&Active_suspension_sim_M)->solverInfo, (real_T **) &(
      &Active_suspension_sim_M)->contStates);
    rtsiSetNumContStatesPtr(&(&Active_suspension_sim_M)->solverInfo,
      &(&Active_suspension_sim_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Active_suspension_sim_M)->solverInfo,
      &(&Active_suspension_sim_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Active_suspension_sim_M)->solverInfo,
      &(&Active_suspension_sim_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Active_suspension_sim_M)->solverInfo,
      &(&Active_suspension_sim_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Active_suspension_sim_M)->solverInfo,
                          (&rtmGetErrorStatus((&Active_suspension_sim_M))));
    rtsiSetRTModelPtr(&(&Active_suspension_sim_M)->solverInfo,
                      (&Active_suspension_sim_M));
  }

  rtsiSetSimTimeStep(&(&Active_suspension_sim_M)->solverInfo, MAJOR_TIME_STEP);
  (&Active_suspension_sim_M)->intgData.y = (&Active_suspension_sim_M)->odeY;
  (&Active_suspension_sim_M)->intgData.f[0] = (&Active_suspension_sim_M)->odeF[0];
  (&Active_suspension_sim_M)->intgData.f[1] = (&Active_suspension_sim_M)->odeF[1];
  (&Active_suspension_sim_M)->intgData.f[2] = (&Active_suspension_sim_M)->odeF[2];
  (&Active_suspension_sim_M)->contStates = ((X_Active_suspension_sim_T *)
    &Active_suspension_sim_X);
  rtsiSetSolverData(&(&Active_suspension_sim_M)->solverInfo, static_cast<void *>
                    (&(&Active_suspension_sim_M)->intgData));
  rtsiSetSolverName(&(&Active_suspension_sim_M)->solverInfo,"ode3");
  rtmSetTPtr((&Active_suspension_sim_M), &(&Active_suspension_sim_M)
             ->Timing.tArray[0]);
  (&Active_suspension_sim_M)->Timing.stepSize0 = 0.0001;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Active_suspension_sim_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  Active_suspension_sim_X.Integrator1_CSTATE = 0.0;
}

/* Model terminate function */
void Active_suspension_simModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Active_suspension_simModelClass::Active_suspension_simModelClass() :
  Active_suspension_sim_B(),
  Active_suspension_sim_X(),
  Active_suspension_sim_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
Active_suspension_simModelClass::~Active_suspension_simModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Active_suspension_si_T * Active_suspension_simModelClass::getRTM()
{
  return (&Active_suspension_sim_M);
}
