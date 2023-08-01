% ========================================================================
% CONTROL OF MECHANICAL SYSTEMS (Homework n°9)                  11/25/2019
% Vehicle dynamic model: Cruise Control design (1/2)
% ========================================================================
% Considerations about vehicle dynamic model: nonlinear counter forces and
% motor-torque curve desmocription. Feedback control design that attempts to
% regulate the speed of the car in presence of disturbances. First order
% model and control linearization of error dynamics around the selected
% operating point (constant speed-target).
% Simulink nonlinear model building. PI controller gains “kP,kI” design
% (gain scheduled control) with anti wind-up.
% ========================================================================

clear all
close all
clc


syms s

time   = 40

%parametrizzazione
% ========================================================================
trise = 7.5
tau   = trise/4
zita  = 0.7 %0.7
wn    = 1/(tau*zita)
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
% ========================================================================
 
%gear  ratios
a1 = 40;
a2 = 25;
a3 = 16;
a4 = 12;
a5 = 10;
 
%current gear
an = a3 %16 %25
% ========================================================================
 
%road slope
theta = 12  %0 %12       %[deg]
slope = theta*pi/180    %[rad]
% ========================================================================
% ========================================================================

%initial and target longitudinal speed [m/s]
v0 = 55/3.6 %55-65
vr = 70/3.6 %95-100
% ========================================================================

%reference control
u0 = 0
eq = an*s*Tm*(1-b*((an*vr/wm)-1)^2) - M*g*Cr*sign(vr) - (1/2)*p*Cd*A*(vr^2) - M*g*sind(theta)
ur = double(solve(eq,s))
% ========================================================================
 
%linearization matrices 
FL = -an*ur*Tm*2*b*((an*vr/wm)-1)*(an/wm) - p*Cd*A*vr
GL = an*Tm*(1-b*((an*vr/wm) - 1)^2)
% ========================================================================
 
%tuningPI
kI = (M*wn^2)/GL
kP = (2*zita*wn*M + FL)/GL

% kI=0.7176
% kP=0.6376

% pR = -zita*wn
% pi = wn*sqrt(1-zita^2)
% 
% p  = pR+i*pi
% p  = [ p conj(p)]
% 
% A  = [ (F-G*kP)/M G/M;
%            -kI      0]
% 
% eig(A)
% ========================================================================

%anti wind-up gain
kT = 2;

%simulation
sim('CruiseControl_sim.slx')
% ========================================================================


