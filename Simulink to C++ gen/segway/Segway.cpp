/*
 * Segway.cpp
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

#include "Segway.h"
#include "Segway_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void SegwayModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
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
  int_T nXc { 6 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Segway_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Segway_derivatives();

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
  Segway_derivatives();

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
void SegwayModelClass::step()
{
  real_T rtb_MathFunction3;
  real_T rtb_SineWaveacc;
  real_T rtb_SineWavepos;
  real_T rtb_SineWavepos_tmp;
  real_T rtb_SineWavepos_tmp_tmp;
  real_T rtb_TmpSignalConversionAtGain_0;
  real_T rtb_omega_;
  real_T rtb_omega__tmp;
  real_T rtb_y_idx_0;
  real_T rtb_y_idx_1;
  real_T rtb_y_idx_2;
  if (rtmIsMajorTimeStep((&Segway_M))) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&(&Segway_M)->solverInfo,(((&Segway_M)
      ->Timing.clockTick0+1)*(&Segway_M)->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Segway_M))) {
    (&Segway_M)->Timing.t[0] = rtsiGetT(&(&Segway_M)->solverInfo);
  }

  /* Sin: '<S3>/Sine Wave acc' incorporates:
   *  Sin: '<S3>/Sine Wave omega'
   *  Sin: '<S3>/Sine Wave pos'
   */
  rtb_SineWavepos_tmp = 1.5707963267948966 * (&Segway_M)->Timing.t[0];
  rtb_SineWavepos = std::sin(rtb_SineWavepos_tmp);
  rtb_SineWaveacc = rtb_SineWavepos * -0.2583856390024985;

  /* Sin: '<S3>/Sine Wave pos' */
  rtb_SineWavepos *= 0.10471975511965978;

  /* Integrator: '<S2>/Integrator' */
  Segway_B.z_1d[0] = Segway_X.Integrator_CSTATE[0];
  Segway_B.z_1d[1] = Segway_X.Integrator_CSTATE[1];

  /* Trigonometry: '<S1>/Trigonometric Function1' incorporates:
   *  Integrator: '<S2>/Integrator1'
   *  ManualSwitch: '<S1>/Manual Switch'
   *  Trigonometry: '<S6>/Trigonometric Function1'
   */
  rtb_omega__tmp = std::sin(Segway_X.Integrator1_CSTATE[1]);

  /* Trigonometry: '<S1>/Trigonometric Function' incorporates:
   *  Integrator: '<S2>/Integrator1'
   *  ManualSwitch: '<S1>/Manual Switch'
   *  Trigonometry: '<S5>/Trigonometric Function1'
   */
  rtb_TmpSignalConversionAtGain_0 = std::cos(Segway_X.Integrator1_CSTATE[1]);

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   *  Constant: '<S5>/Constant'
   */
  Segway_B.VectorConcatenate[0] = 75.0;

  /* Gain: '<S5>/Gain3' */
  rtb_omega_ = 65.0 * rtb_TmpSignalConversionAtGain_0;

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   */
  Segway_B.VectorConcatenate[1] = rtb_omega_;

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   */
  Segway_B.VectorConcatenate[2] = 0.0;

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   */
  Segway_B.VectorConcatenate[3] = rtb_omega_;

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   *  Constant: '<S5>/Constant1'
   */
  Segway_B.VectorConcatenate[4] = 65.0;

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   */
  Segway_B.VectorConcatenate[5] = 0.0;

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   */
  Segway_B.VectorConcatenate[6] = 0.0;

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   */
  Segway_B.VectorConcatenate[7] = 0.0;

  /* SignalConversion generated from: '<S8>/Vector Concatenate' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   */
  Segway_B.VectorConcatenate[8] = 0.0;

  /* S-Function (sdspsubmtrx): '<S5>/Submatrix' incorporates:
   *  Concatenate: '<S8>/Vector Concatenate'
   */
  Segway_B.Submatrix[0] = Segway_B.VectorConcatenate[0];
  Segway_B.Submatrix[1] = Segway_B.VectorConcatenate[1];
  Segway_B.Submatrix[2] = Segway_B.VectorConcatenate[3];
  Segway_B.Submatrix[3] = Segway_B.VectorConcatenate[4];

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  S-Function (sdspsubmtrx): '<S5>/Submatrix'
   */
  if (std::abs(Segway_B.Submatrix[1]) > std::abs(Segway_B.Submatrix[0])) {
    rtb_omega_ = Segway_B.Submatrix[0] / Segway_B.Submatrix[1];
    rtb_MathFunction3 = 1.0 / (rtb_omega_ * Segway_B.Submatrix[3] -
      Segway_B.Submatrix[2]);
    rtb_y_idx_0 = Segway_B.Submatrix[3] / Segway_B.Submatrix[1] *
      rtb_MathFunction3;
    rtb_y_idx_1 = -rtb_MathFunction3;
    rtb_y_idx_2 = -Segway_B.Submatrix[2] / Segway_B.Submatrix[1] *
      rtb_MathFunction3;
    rtb_MathFunction3 *= rtb_omega_;
  } else {
    rtb_omega_ = Segway_B.Submatrix[1] / Segway_B.Submatrix[0];
    rtb_MathFunction3 = 1.0 / (Segway_B.Submatrix[3] - rtb_omega_ *
      Segway_B.Submatrix[2]);
    rtb_y_idx_0 = Segway_B.Submatrix[3] / Segway_B.Submatrix[0] *
      rtb_MathFunction3;
    rtb_y_idx_1 = -rtb_omega_ * rtb_MathFunction3;
    rtb_y_idx_2 = -Segway_B.Submatrix[2] / Segway_B.Submatrix[0] *
      rtb_MathFunction3;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* Gain: '<S6>/Gain7' */
  rtb_omega_ = 637.65 * rtb_omega__tmp;

  /* Gain: '<S1>/Gain7' incorporates:
   *  Gain: '<S6>/Gain5'
   *  ManualSwitch: '<S1>/Manual Switch'
   *  Math: '<S1>/Math Function1'
   *  Product: '<S6>/Product1'
   */
  rtb_SineWavepos_tmp_tmp = Segway_B.z_1d[1] * Segway_B.z_1d[1] * rtb_omega__tmp
    * 65.0;

  /* Sum: '<S6>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain4'
   *  Gain: '<S1>/Gain7'
   *  Gain: '<S1>/Gain9'
   *  Integrator: '<S2>/Integrator1'
   *  ManualSwitch: '<S1>/Manual Switch'
   *  Math: '<S1>/Math Function'
   *  Product: '<S1>/Divide'
   *  SignalConversion generated from: '<S4>/Gain10'
   *  Sin: '<S3>/Sine Wave omega'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   *  Sum: '<S1>/Add2'
   *  Trigonometry: '<S1>/Trigonometric Function'
   *  Trigonometry: '<S1>/Trigonometric Function1'
   *  Trigonometry: '<S1>/Trigonometric Function2'
   */
  rtb_SineWavepos_tmp = ((((Segway_B.z_1d[1] - std::sin(rtb_SineWavepos_tmp +
    1.5707963267948966) * 0.16449340668482265) * 100.0 +
    ((Segway_X.Integrator1_CSTATE[1] - rtb_SineWavepos) * 400.0 -
     rtb_SineWaveacc)) / rtb_TmpSignalConversionAtGain_0 * (rtb_omega__tmp *
    rtb_omega__tmp * 65.0 + 10.0) - rtb_SineWavepos_tmp_tmp) + 735.75 * std::tan
    (Segway_X.Integrator1_CSTATE[1])) + rtb_SineWavepos_tmp_tmp;

  /* Product: '<S2>/Matrix Multiply' incorporates:
   *  Sum: '<S6>/Add'
   */
  Segway_B.z_2d[0] = 0.0;
  Segway_B.z_2d[0] += rtb_y_idx_0 * rtb_SineWavepos_tmp;
  Segway_B.z_2d[0] += rtb_y_idx_2 * rtb_omega_;
  Segway_B.z_2d[1] = 0.0;
  Segway_B.z_2d[1] += rtb_y_idx_1 * rtb_SineWavepos_tmp;
  Segway_B.z_2d[1] += rtb_MathFunction3 * rtb_omega_;

  /* Sum: '<S7>/Add' incorporates:
   *  Gain: '<S7>/Gain3'
   *  Product: '<S7>/Divide'
   *  Trigonometry: '<S7>/Trigonometric Function'
   *  Trigonometry: '<S7>/Trigonometric Function1'
   */
  Segway_B.Add = 9.81 * std::tan(rtb_SineWavepos) - rtb_SineWaveacc / std::cos
    (rtb_SineWavepos);

  /* Integrator: '<S7>/Integrator' */
  if (Segway_DW.Integrator_IWORK != 0) {
    Segway_X.Integrator_CSTATE_m = Segway_B.z_1d[0];
  }

  /* End of Integrator: '<S7>/Integrator' */
  if (rtmIsMajorTimeStep((&Segway_M))) {
    /* Update for Integrator: '<S7>/Integrator' */
    Segway_DW.Integrator_IWORK = 0;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&Segway_M))) {
    rt_ertODEUpdateContinuousStates(&(&Segway_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++(&Segway_M)->Timing.clockTick0;
    (&Segway_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&Segway_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      (&Segway_M)->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SegwayModelClass::Segway_derivatives()
{
  XDot_Segway_T *_rtXdot;
  _rtXdot = ((XDot_Segway_T *) (&Segway_M)->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = Segway_B.z_1d[0];

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = Segway_B.z_2d[0];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = Segway_B.z_1d[1];

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = Segway_B.z_2d[1];

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = Segway_B.Add;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += -2.5 * Segway_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += 0.10471975511965978;
}

/* Model initialize function */
void SegwayModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Segway_M)->solverInfo, &(&Segway_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&Segway_M)->solverInfo, &rtmGetTPtr((&Segway_M)));
    rtsiSetStepSizePtr(&(&Segway_M)->solverInfo, &(&Segway_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Segway_M)->solverInfo, &(&Segway_M)->derivs);
    rtsiSetContStatesPtr(&(&Segway_M)->solverInfo, (real_T **) &(&Segway_M)
                         ->contStates);
    rtsiSetNumContStatesPtr(&(&Segway_M)->solverInfo, &(&Segway_M)
      ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Segway_M)->solverInfo, &(&Segway_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Segway_M)->solverInfo, &(&Segway_M)
      ->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Segway_M)->solverInfo, &(&Segway_M)
      ->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Segway_M)->solverInfo, (&rtmGetErrorStatus
      ((&Segway_M))));
    rtsiSetRTModelPtr(&(&Segway_M)->solverInfo, (&Segway_M));
  }

  rtsiSetSimTimeStep(&(&Segway_M)->solverInfo, MAJOR_TIME_STEP);
  (&Segway_M)->intgData.y = (&Segway_M)->odeY;
  (&Segway_M)->intgData.f[0] = (&Segway_M)->odeF[0];
  (&Segway_M)->intgData.f[1] = (&Segway_M)->odeF[1];
  (&Segway_M)->intgData.f[2] = (&Segway_M)->odeF[2];
  (&Segway_M)->contStates = ((X_Segway_T *) &Segway_X);
  rtsiSetSolverData(&(&Segway_M)->solverInfo, static_cast<void *>(&(&Segway_M)
    ->intgData));
  rtsiSetSolverName(&(&Segway_M)->solverInfo,"ode3");
  rtmSetTPtr((&Segway_M), &(&Segway_M)->Timing.tArray[0]);
  (&Segway_M)->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond((&Segway_M), 1);

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  Segway_X.Integrator1_CSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Segway_X.Integrator_CSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  Segway_X.Integrator1_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Segway_X.Integrator_CSTATE[1] = 0.16449340668482265;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  if (rtmIsFirstInitCond((&Segway_M))) {
    Segway_X.Integrator_CSTATE_m = 0.0;
  }

  Segway_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S7>/Integrator' */

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn1' */
  Segway_X.TransferFcn1_CSTATE = 0.0;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond((&Segway_M))) {
    rtmSetFirstInitCond((&Segway_M), 0);
  }
}

/* Model terminate function */
void SegwayModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
SegwayModelClass::SegwayModelClass() :
  Segway_B(),
  Segway_DW(),
  Segway_X(),
  Segway_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
SegwayModelClass::~SegwayModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Segway_T * SegwayModelClass::getRTM()
{
  return (&Segway_M);
}
