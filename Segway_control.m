% ========================================================================
% CONTROL OF MECHANICAL SYSTEMS (Exercise n°8-HM 12)(2/2)       12/21/2020 
% Balance System-based design: Segway control
% ========================================================================
% Model of a Segway cart through Eulero-Lagrange equations:
% from energy balance a feedforward+feedback and a feedback linearizing
% controllers are found for stabilizing the rotation of the vertical bar.
% Since the system is reachable a tracking controller for a constant
% requested angle is implemented.
% There is no control on the rotative joint: in this way a residuali=2^10
% dynamics for the cart longitudinal motion is found. This dynamics must
% diverge in longitudinal position, in order to make the cart a transport
% system. The possibility to tracking a time-variant reference is also
% allowed by the control design: manual rail cart example (RMS).
% ========================================================================

clear all
close all
clc


syms s

d2r    = pi/180

time   = 30

freq   = 5/20
wf     = 2*pi*freq
A_s    = 6*d2r

%parameters
% ========================================================================
% ========================================================================
M  = 10;          %[kg]  cart mass 
m  = 65;          %[kg]  pendulum mass 
g  = 9.81;        %[m*s^(-2)] gravity acceleration
l  = 1;           %[m] bar length
% ========================================================================

%initial and target longitudinal speed
x0   = 0          %position
phi0 = 0*d2r      %[rad] initial angle
v0   = 0/3.6      %[m*s^(-1)] initial cart speed
w0   = 0          %[rad*s^(-1)] initial angular speed
w0f  = A_s*wf     %[rad*s^(-1)] initial angular speed

phi_r    = 1*d2r
phi_r_1d = 0
phi_r_2d = 0
% ========================================================================

%control gains (positive definite)
%u_F.L. (nonlinear: feedback linearizing control)
%constant reference
kP = 400
kv = 100

% %u_FF+u_FB (linear feedback + feedforward control)
% %constant reference
% kP = 4000
% kv = 1000

%sinusoidal reference
w0    = w0f
phi_r = A_s
% ========================================================================

a   = g*tan(phi_r)
a_gs= tan(phi_r)

%simulation
sim('Segway.slx')

v_avg = rms(vx)
% ========================================================================


