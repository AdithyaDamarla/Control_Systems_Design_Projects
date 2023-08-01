
clear all
close all
clc

run('HM4.m')

%Design via YOULA PARAMETRIZATION
%================================================================
%-------------------------------------------------
%FIRST ORDER
w_band = 10;             %[rad/s]
tau    = 2*pi/w_band;    %[s]

%-------------------------------------------------
%SECOND ORDER
zita = 0.8;
wn   = 1/(zita*tau)

%process t.f.
P  = tf([1 0.9],[1 0.5 1])

%Youla Sensitivity t.f.s
Sigma1=tf([tau 1],[1])               %1st order
Sigma2=tf([1/wn^2 2*zita/wn 1],[1])  %2nd order

Q  = (1/P)/Sigma2
T  = P*Q
S  = 1-T

%Controller t.f. Design
C  = Q/S
% C  = (tf([1],[tau 1])/tf([1 0.9],[1 0.5 1]))/(1-tf([1],[tau 1]))
% C  = tf([1 0.5 1],[tau 0.9*tau 0])
% pzmap(C)
% grid on

%non-minimum phase case
% % c  = tf([1 10],[1])
% % C  = Q/(S*c)


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
title('GoF: Youla Design')

%Simulation
%================================================================
sim('HM8_Youla_sim.slx')
%================================================================

















