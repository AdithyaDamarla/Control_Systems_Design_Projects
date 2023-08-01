% ========================================================================
% CONTROL OF MECHANICAL SYSTEMS (Homework n°9)                  12/09/2020
% Adaptive Cruise Control design
% ========================================================================
% Review of physical model and control definition concepts.
% Stability analysis of controlled linearized system with scheduled gain.
% LQR control assignation and comparison with Lyapunov matrix approach.
% Autonomous Cruise control: (a) Adaptive vehicle platoon control design;
% (b) negative slope case; (c) automatic gears.
% ========================================================================

clear all
close all
clc


syms s

time   = 50

%parametrization
% ========================================================================
trise = 10
tau   = trise/4
zita  = 1 %0.7
wn    = 1/(tau*zita)

tau0  = 1
% ========================================================================

%parameters
% ========================================================================
% ========================================================================
M  = 1000;          %[kg]  mass 
Tm = 190;           %[N*m] maximum motor torque =: T(wm)
wm = 420;           %[rad*s^(-1)] maximum motor speed [about 4000 rpm]
b  = 0.4;           %[.] adim. torque curve shape parameter
g  = 9.81;          %[m*s^(-2)] gravity acceleration
Cr = 0.01;          %[.] adim. rolling friction coeff.
Cd = 0.32;          %[.] adim. shape-dependend aerodynamic drag coeff.
p  = 1.3;           %[kg*m^(-3)] air density
A  = 2.4;           %[m^(2)] car frontal area
% r  = 0.3;           %[m] wheel radius
% Je = 20;            %[kg*m^2] engine moment of inertia
% Jw = 2;             %[kg*m^2] wheel moment of inertia
% kB = 0.9;           %[N*m*Pa^(-1)] pressure gain
% ========================================================================

%gear  ratios
a1 = 40;
a2 = 25;
a3 = 16; 
a4 = 12;
a5 = 10;
 
%starting gear
an = a2 %16 %25
n  = 3

wMin = 2000     %[rpm]
wMax = 3300     %[rpm]
% ========================================================================

%road slope
theta = -2  %0 %12
slope = theta*pi/180
% ========================================================================
% ========================================================================

%initial and target longitudinal speed
v0 = 50/3.6 %55-65
vr = 60/3.6 %95-100

v02 = vr
% ========================================================================

%reference control
u0 = 0
eq = an*s*Tm*(1-b*((an*vr/wm)-1)^2) - M*g*Cr*sign(vr) - (1/2)*p*Cd*A*(vr^2) - M*g*sind(theta)
ur = double(solve(eq,s))
% ========================================================================
 
%linearization matrices 
F = -an*ur*Tm*2*b*((an*vr/wm)-1)*(an/wm) - p*Cd*A*vr
G = an*Tm*(1-b*((an*vr/wm) - 1)^2)
% ========================================================================

%tuning P.I.D. control
kI = (tau0*M*wn^2)/G
kP = (2*zita*wn*tau0 + wn^2)*M/G
kD = ((2*zita*wn+tau0)*M + F)/G

%brake model
Vc = 100/3.6
c  = M*g/Vc
% ========================================================================

%eigenvalues analysis
%Riccati
R = 1
Q = [ 1  0  0;
      0 100  0;
      0  0  50]

Ar = [ 0   1    0;
       0   0    1;
       0   0  F/M]

Br = [ 0   0  G/M]'

[gains,P,poles] = lqr(Ar,Br,Q,R,0)
% =================================
% %Lyapunov
Q_bar = Q+P*Br*inv(R)*Br'*P
K     = (inv(R)*Br'*P)
AL    = Ar-Br*(inv(R)*Br'*P)

PL = lyap(AL',Q_bar)
-((AL')*PL+PL*AL)

kI = gains(1)
kP = gains(2)
kD = gains(3)
% =================================
%Overshoot and time constant
tauL  = 2*min(eig(P))/min(eig(Q_bar))
timeL = 4*tauL

P_eigs = eig(P)
Q_eigs = eig(Q_bar)

overS = sqrt(max(eig(P))/min(eig(P)))
% ========================================================================

% %drawing ellipsoid
% [x, y, z] = ellipsoid(0,0,0,P_eigs(1),P_eigs(2),P_eigs(3),50);
% figure
% surf(x, y, z)
% xlabel('x')
% ylabel('y')
% zlabel('z')
% ========================================================================

%initial conditions (position)
x01 = 0
x02 = 88
L   = 90 %desired distance

%anti wind-up gain
kT = 2;

%simulation
sim('Adaptive_CruiseControl_sim.slx')
% ========================================================================


