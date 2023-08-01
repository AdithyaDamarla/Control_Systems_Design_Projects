
clear all
close all
clc

time = 30;

% V = 40/3.6      %longitudinal speed
V = 17          %non minimum-phase speed (k0vy<0)
r = 100          %curve radius

%%System Parameters
%=================================================
mu = 1.0        %[.]        friction coefficient
m  = 1864       %[Kg]       mass
J  = 3654       %[Kg*m^(2)] momentum
cr = 213800 *mu %[N/rad]    rear cornering stiff.
cf = 101600 *mu %[N/rad]    front cornering stif.
lr = 1.32       %[m]        rear wheel-CM distance
lf = 1.51       %[m]        front wheel-CM distance

%%Combined Parameters {vehicle}
alpha= cf/m+cr/m
beta = -cf*lf+cr*lr
gamma= (cf*lf^2+cr*lr^2)/J

b1   = cf/m
b2   = cf*lf/J

%%Combined Parameters {model reference}
alpha_r= alpha
beta_r = beta
gamma_r= gamma

b1_r   = b1
b2_r   = b2

%%System Matrices
%-------------------------------------------------
A = [  -alpha/V   -(V-beta/(m*V)),
      beta/(J*V)        -gamma/V];
  
b = [ b1 ; b2];

C = [ 0  1 ];

% % syms v
% % V_mf=double(solve(b1*gamma/v-b2*(v-beta/(m*v)),v))
% % 
% % V=V_mf(2) %%non minimum-phase speed (k0vy<0)
%=================================================

%Design via YOULA PARAMETRIZATION
%================================================================
%-------------------------------------------------
%FIRST ORDER
w_band = 1000;            %[rad/s]
tau    = 2*pi/w_band;     %[s]

%-------------------------------------------------
%SECOND ORDER
zita = 0.7;
wn   = 1/(zita*tau)

%process t.f.
[numP,denP] = ss2tf(A,b,C,0,1) %(from r to y)
P = tf([numP],[denP])

%Youla Sensitivity t.f.s
Sigma1=tf([tau 1],[1])               %1st order
Sigma2=tf([1/wn^2 2*zita/wn 1],[1])  %2nd order

Q  = (1/P)/Sigma1
T  = P*Q
S  = 1-T

%Controller t.f. Design
C  = Q/S
% C  = (tf([1],[tau 1])/tf([1 0.9],[1 0.5 1]))/(1-tf([1],[tau 1]))
% C  = tf([1 0.5 1],[tau 0.9*tau 0])

[nC,dC]  = (tfdata(C, 'V'))
nC       = double(nC)
dC       = double(dC)

%-------------------------------------------------
% close all

CS = Q
PS = P*(1-P*Q)

figure
bode(S,T,CS,PS)
grid on
title('GoF: Youla Design of a Lane-Keeping controller')

%%Simulation {Youla Param. Controller}
%=================================================
%Parameter variation (enviroment)
mu = 1.0 
cr = 213800 *mu %[N/rad]    rear cornering stiff.
cf = 101600 *mu %[N/rad]    front cornering stif.

alpha= cf/m+cr/m
beta = -cf*lf+cr*lr
gamma= (cf*lf^2+cr*lr^2)/J

b1   = cf/m
b2   = cf*lf/J
%-------------------------------------------------
%Initial condition
vy_0        = 0
vy_r0       = 0
% sim('Lane_Keeping_control_BMW730_sim.slx')
%================================================================


%================================================================
%================================================================
%autonomous vehicle
% load('y.mat')
step_size = 1e-4
t = linspace(0,time,time/step_size+1)';

kd =-1
kP2=-10
kI2=-0.01
kI3=-0.1

sim('Lane_Keeping_control_BMW730_auto_sim.slx')
%================================================================


figure
plot(x_position,y_position,'LineWidth',1.5)
hold on
plot(xr_position,yr_position,'--','LineWidth',1.5)
xlim([0 V*time*0.9])
legend('Trajectory','Reference Trajcetory','Location','southeast')
















