/*
 * Adaptive_CruiseControl_sim.cpp
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

#include "Adaptive_CruiseControl_sim.h"
#include "Adaptive_CruiseControl_sim_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void Adaptive_CruiseControl_simModelClass::rt_ertODEUpdateContinuousStates
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
  int_T nXc { 8 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Adaptive_CruiseControl_sim_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Adaptive_CruiseControl_sim_derivatives();

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
  Adaptive_CruiseControl_sim_derivatives();

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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (std::isinf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void Adaptive_CruiseControl_simModelClass::step()
{
  real_T rtb_Saturation1;
  real_T rtb_ur;
  real_T rtb_wrpm;
  real_T tmp;
  real_T u;
  int32_T tmp_0;
  if (rtmIsMajorTimeStep((&Adaptive_CruiseControl_sim_M))) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
                          (((&Adaptive_CruiseControl_sim_M)->Timing.clockTick0+1)*
      (&Adaptive_CruiseControl_sim_M)->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Adaptive_CruiseControl_sim_M))) {
    (&Adaptive_CruiseControl_sim_M)->Timing.t[0] = rtsiGetT
      (&(&Adaptive_CruiseControl_sim_M)->solverInfo);
  }

  /* Integrator: '<S1>/Integrator' */
  Adaptive_CruiseControl_sim_B.v =
    Adaptive_CruiseControl_sim_X.Integrator_CSTATE;

  /* Integrator: '<S4>/Integrator' */
  Adaptive_CruiseControl_sim_B.v2 =
    Adaptive_CruiseControl_sim_X.Integrator_CSTATE_n;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<S4>/Constant'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S4>/Integrator1'
   *  SignalConversion generated from: '<S1>/Vector Concatenate'
   *  SignalConversion generated from: '<S4>/Vector Concatenate'
   *  Sum: '<S4>/Add1'
   */
  Adaptive_CruiseControl_sim_B.Sum[0] =
    (Adaptive_CruiseControl_sim_X.Integrator1_CSTATE - 90.0) -
    Adaptive_CruiseControl_sim_X.Integrator1_CSTATE_f;
  Adaptive_CruiseControl_sim_B.Sum[1] = Adaptive_CruiseControl_sim_B.v2 -
    Adaptive_CruiseControl_sim_B.v;

  /* Sum: '<S6>/Add' incorporates:
   *  Gain: '<S11>/Gain'
   *  Gain: '<S6>/Gain3'
   *  Gain: '<S6>/Gain4'
   *  Integrator: '<S11>/Integrator'
   *  Integrator: '<S6>/Integrator'
   *  Sum: '<S6>/Add1'
   */
  rtb_ur = ((10.712902916437496 * Adaptive_CruiseControl_sim_B.Sum[0] +
             Adaptive_CruiseControl_sim_X.Integrator_CSTATE_e) +
            7.3796328001739919 * Adaptive_CruiseControl_sim_B.Sum[1]) + 2.0 *
    Adaptive_CruiseControl_sim_X.Integrator_CSTATE_ed;

  /* Saturate: '<S6>/Saturation1' */
  if (rtb_ur > 1.0) {
    rtb_Saturation1 = 1.0;
  } else if (rtb_ur < 0.0) {
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtb_ur;
  }

  /* End of Saturate: '<S6>/Saturation1' */
  if (rtmIsMajorTimeStep((&Adaptive_CruiseControl_sim_M))) {
    /* Saturate: '<S5>/Saturation' incorporates:
     *  Memory: '<S5>/Memory'
     */
    if (Adaptive_CruiseControl_sim_DW.Memory_PreviousInput > 5.0) {
      /* Saturate: '<S5>/Saturation' */
      Adaptive_CruiseControl_sim_B.Saturation = 5.0;
    } else if (Adaptive_CruiseControl_sim_DW.Memory_PreviousInput < 1.0) {
      /* Saturate: '<S5>/Saturation' */
      Adaptive_CruiseControl_sim_B.Saturation = 1.0;
    } else {
      /* Saturate: '<S5>/Saturation' */
      Adaptive_CruiseControl_sim_B.Saturation =
        Adaptive_CruiseControl_sim_DW.Memory_PreviousInput;
    }

    /* End of Saturate: '<S5>/Saturation' */

    /* MultiPortSwitch: '<S5>/Index Vector' */
    switch (static_cast<int32_T>(Adaptive_CruiseControl_sim_B.Saturation)) {
     case 1:
      /* MultiPortSwitch: '<S5>/Index Vector' incorporates:
       *  Constant: '<S5>/Constant'
       */
      Adaptive_CruiseControl_sim_B.IndexVector = 40.0;
      break;

     case 2:
      /* MultiPortSwitch: '<S5>/Index Vector' incorporates:
       *  Constant: '<S5>/Constant1'
       */
      Adaptive_CruiseControl_sim_B.IndexVector = 25.0;
      break;

     case 3:
      /* MultiPortSwitch: '<S5>/Index Vector' incorporates:
       *  Constant: '<S5>/Constant2'
       */
      Adaptive_CruiseControl_sim_B.IndexVector = 16.0;
      break;

     case 4:
      /* MultiPortSwitch: '<S5>/Index Vector' incorporates:
       *  Constant: '<S5>/Constant3'
       */
      Adaptive_CruiseControl_sim_B.IndexVector = 12.0;
      break;

     case 5:
      /* MultiPortSwitch: '<S5>/Index Vector' incorporates:
       *  Constant: '<S5>/Constant4'
       */
      Adaptive_CruiseControl_sim_B.IndexVector = 10.0;
      break;

     default:
      /* MultiPortSwitch: '<S5>/Index Vector' incorporates:
       *  Constant: '<S5>/Constant5'
       */
      Adaptive_CruiseControl_sim_B.IndexVector = 25.0;
      break;
    }

    /* End of MultiPortSwitch: '<S5>/Index Vector' */
  }

  /* Product: '<S7>/Product1' */
  rtb_wrpm = Adaptive_CruiseControl_sim_B.IndexVector *
    Adaptive_CruiseControl_sim_B.v;

  /* Sum: '<S2>/Add' incorporates:
   *  Gain: '<S2>/Gain3'
   *  Gain: '<S2>/Gain4'
   *  Integrator: '<S2>/Integrator'
   */
  u = (10.712902916437496 * Adaptive_CruiseControl_sim_B.Sum[0] +
       Adaptive_CruiseControl_sim_X.Integrator_CSTATE_np) + 7.3796328001739919 *
    Adaptive_CruiseControl_sim_B.Sum[1];

  /* Signum: '<S8>/Sign' */
  if (u < 0.0) {
    u = -1.0;
  } else if (u > 0.0) {
    u = 1.0;
  } else if (u == 0.0) {
    u = 0.0;
  } else {
    u = (rtNaN);
  }

  /* End of Signum: '<S8>/Sign' */

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Constant'
   *  Switch: '<S8>/Switch'
   */
  u = Adaptive_CruiseControl_sim_B.v * -353.15999999999997 * static_cast<real_T>
    (!(u > 0.0));

  /* Signum: '<S3>/Sign' */
  if (Adaptive_CruiseControl_sim_B.v < 0.0) {
    tmp = -1.0;
  } else if (Adaptive_CruiseControl_sim_B.v > 0.0) {
    tmp = 1.0;
  } else if (Adaptive_CruiseControl_sim_B.v == 0.0) {
    tmp = 0.0;
  } else {
    tmp = (rtNaN);
  }

  /* End of Signum: '<S3>/Sign' */

  /* Saturate: '<S8>/Saturation' */
  if (u > 0.0) {
    u = 0.0;
  } else if (u < -353.15999999999997) {
    u = -353.15999999999997;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Gain: '<S1>/Gain' incorporates:
   *  Fcn: '<S3>/Fcn1'
   *  Fcn: '<S7>/Fcn'
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain2'
   *  Product: '<S3>/Product3'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product2'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<S2>/Sum3'
   *  Sum: '<S3>/Add'
   */
  Adaptive_CruiseControl_sim_B.Gain = (((1.0 - rt_powd_snf(rtb_wrpm / 420.0 -
    1.0, 2.0) * 0.4) * 190.0 * (rtb_Saturation1 *
    Adaptive_CruiseControl_sim_B.IndexVector) + u) + ((342.36406265153448 - 0.01
    * tmp * 9810.0) - 0.49920000000000003 * rt_powd_snf
    (Adaptive_CruiseControl_sim_B.v, 2.0))) * 0.001;

  /* Gain: '<S7>/Gain' */
  rtb_wrpm *= 9.5492965855137211;

  /* Sum: '<S5>/Sum3' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  Gain: '<S5>/Gain1'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  Adaptive_CruiseControl_sim_B.Sum3 = (-static_cast<real_T>(rtb_wrpm < 2000.0) +
    Adaptive_CruiseControl_sim_B.Saturation) + static_cast<real_T>(rtb_wrpm >
    3300.0);

  /* Sum: '<S11>/Add' */
  Adaptive_CruiseControl_sim_B.uur = rtb_Saturation1 - rtb_ur;

  /* Step: '<S4>/Step1' incorporates:
   *  Step: '<S4>/Step'
   */
  tmp = (&Adaptive_CruiseControl_sim_M)->Timing.t[0];
  if (tmp < 14.0) {
    tmp_0 = 0;
  } else {
    tmp_0 = -1;
  }

  /* End of Step: '<S4>/Step1' */

  /* Sum: '<S4>/Add' incorporates:
   *  Step: '<S4>/Step'
   */
  Adaptive_CruiseControl_sim_B.Add = static_cast<real_T>(!(tmp < 10.0)) +
    static_cast<real_T>(tmp_0);

  /* Gain: '<S4>/Gain1' incorporates:
   *  TransferFcn: '<S4>/Transfer Fcn'
   */
  Adaptive_CruiseControl_sim_B.a2 = 20.0 *
    Adaptive_CruiseControl_sim_X.TransferFcn_CSTATE * 0.69444444444444442;
  if (rtmIsMajorTimeStep((&Adaptive_CruiseControl_sim_M))) {
    if (rtmIsMajorTimeStep((&Adaptive_CruiseControl_sim_M))) {
      /* Update for Memory: '<S5>/Memory' */
      Adaptive_CruiseControl_sim_DW.Memory_PreviousInput =
        Adaptive_CruiseControl_sim_B.Sum3;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&Adaptive_CruiseControl_sim_M))) {
    rt_ertODEUpdateContinuousStates(&(&Adaptive_CruiseControl_sim_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++(&Adaptive_CruiseControl_sim_M)->Timing.clockTick0;
    (&Adaptive_CruiseControl_sim_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&Adaptive_CruiseControl_sim_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      (&Adaptive_CruiseControl_sim_M)->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Adaptive_CruiseControl_simModelClass::
  Adaptive_CruiseControl_sim_derivatives()
{
  XDot_Adaptive_CruiseControl_s_T *_rtXdot;
  _rtXdot = ((XDot_Adaptive_CruiseControl_s_T *) (&Adaptive_CruiseControl_sim_M
             )->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = Adaptive_CruiseControl_sim_B.Gain;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = Adaptive_CruiseControl_sim_B.Sum[0];

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Adaptive_CruiseControl_sim_B.v2;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_n = Adaptive_CruiseControl_sim_B.a2;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_f = Adaptive_CruiseControl_sim_B.v;

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE_ed = Adaptive_CruiseControl_sim_B.uur;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_np = Adaptive_CruiseControl_sim_B.Sum[0];

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += -20.0 *
    Adaptive_CruiseControl_sim_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Adaptive_CruiseControl_sim_B.Add;
}

/* Model initialize function */
void Adaptive_CruiseControl_simModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
                          &(&Adaptive_CruiseControl_sim_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo, &rtmGetTPtr
                ((&Adaptive_CruiseControl_sim_M)));
    rtsiSetStepSizePtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
                       &(&Adaptive_CruiseControl_sim_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
                 &(&Adaptive_CruiseControl_sim_M)->derivs);
    rtsiSetContStatesPtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo, (real_T **)
                         &(&Adaptive_CruiseControl_sim_M)->contStates);
    rtsiSetNumContStatesPtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
      &(&Adaptive_CruiseControl_sim_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
      &(&Adaptive_CruiseControl_sim_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Adaptive_CruiseControl_sim_M)
      ->solverInfo, &(&Adaptive_CruiseControl_sim_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Adaptive_CruiseControl_sim_M)
      ->solverInfo, &(&Adaptive_CruiseControl_sim_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
                          (&rtmGetErrorStatus((&Adaptive_CruiseControl_sim_M))));
    rtsiSetRTModelPtr(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
                      (&Adaptive_CruiseControl_sim_M));
  }

  rtsiSetSimTimeStep(&(&Adaptive_CruiseControl_sim_M)->solverInfo,
                     MAJOR_TIME_STEP);
  (&Adaptive_CruiseControl_sim_M)->intgData.y = (&Adaptive_CruiseControl_sim_M
    )->odeY;
  (&Adaptive_CruiseControl_sim_M)->intgData.f[0] =
    (&Adaptive_CruiseControl_sim_M)->odeF[0];
  (&Adaptive_CruiseControl_sim_M)->intgData.f[1] =
    (&Adaptive_CruiseControl_sim_M)->odeF[1];
  (&Adaptive_CruiseControl_sim_M)->intgData.f[2] =
    (&Adaptive_CruiseControl_sim_M)->odeF[2];
  (&Adaptive_CruiseControl_sim_M)->contStates = ((X_Adaptive_CruiseControl_sim_T
    *) &Adaptive_CruiseControl_sim_X);
  rtsiSetSolverData(&(&Adaptive_CruiseControl_sim_M)->solverInfo, static_cast<
                    void *>(&(&Adaptive_CruiseControl_sim_M)->intgData));
  rtsiSetSolverName(&(&Adaptive_CruiseControl_sim_M)->solverInfo,"ode3");
  rtmSetTPtr((&Adaptive_CruiseControl_sim_M), &(&Adaptive_CruiseControl_sim_M)
             ->Timing.tArray[0]);
  (&Adaptive_CruiseControl_sim_M)->Timing.stepSize0 = 0.001;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Adaptive_CruiseControl_sim_X.Integrator_CSTATE = 13.888888888888889;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  Adaptive_CruiseControl_sim_X.Integrator_CSTATE_e = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  Adaptive_CruiseControl_sim_X.Integrator1_CSTATE = 88.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  Adaptive_CruiseControl_sim_X.Integrator_CSTATE_n = 16.666666666666668;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  Adaptive_CruiseControl_sim_X.Integrator1_CSTATE_f = 0.0;

  /* InitializeConditions for Integrator: '<S11>/Integrator' */
  Adaptive_CruiseControl_sim_X.Integrator_CSTATE_ed = 0.0;

  /* InitializeConditions for Memory: '<S5>/Memory' */
  Adaptive_CruiseControl_sim_DW.Memory_PreviousInput = 3.0;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Adaptive_CruiseControl_sim_X.Integrator_CSTATE_np = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn' */
  Adaptive_CruiseControl_sim_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void Adaptive_CruiseControl_simModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Adaptive_CruiseControl_simModelClass::Adaptive_CruiseControl_simModelClass() :
  Adaptive_CruiseControl_sim_B(),
  Adaptive_CruiseControl_sim_DW(),
  Adaptive_CruiseControl_sim_X(),
  Adaptive_CruiseControl_sim_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
Adaptive_CruiseControl_simModelClass::~Adaptive_CruiseControl_simModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Adaptive_CruiseContr_T * Adaptive_CruiseControl_simModelClass::getRTM()
{
  return (&Adaptive_CruiseControl_sim_M);
}
