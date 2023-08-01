% ========================================================================
% CONTROL OF MECHANICAL SYSTEMS (Exercise n°8-HM 12)(1/2)       12/21/2020 
% Balance System: inverted pendulum stabilization
% ========================================================================
% Model of a Segway cart through Eulero-Lagrange equations:
% a) state-feedback to stabilize the rotation of the vertical bar;
% b) LQR controller design.
% ========================================================================

clear all
close all
clc

time = 30;

syms s


%parameters
% ========================================================================
% ========================================================================
M  = 10;          %[kg]  cart mass 
m  = 80;          %[kg]  pendulum mass 
g  = 9.8;         %[m*s^(-2)] gravity acceleration
l  = 1;           %[m] bar length
J  = 100;         %[Kg*m^(2)*s^(-2)] bar moment of inertia
c  = 0.1;         %[N*s*m^(-1)] viscosity
gamma= 0.01;      %[N*s*m]

%secondary parameters
Mt = M+m;
Jt = J+m*(l^2);
mu = Mt*Jt-(m*l)^2;
% ========================================================================

%initial and target longitudinal speed
x0   = 0           %position
phi0 = 1*pi/180    %[rad] initial angle
v0   = 0/3.6       %[m*s^(-1)] initial cart speed
w0   = 0           %[rad*s^(-1)] initial angular speed
% ========================================================================

%linear matrices
A = [ 0             0          1                 0  ,
      0             0          0                 1  ,
      0  ((m*l)^2)*g/mu   -c*Jt/mu  -gamma*Jt*m*l/mu,
      0     Mt*m*g*l/mu  -c*m*l/mu      -gamma*Mt/mu]
  
B = [ 0; 0; Jt/mu; m*l/mu ]

% C = [ 0 0 1 0,
%       0 0 0 1]
C = eye(4,4)

%open-loop eigenvalues
eig(A)

% C*inv(s*eye(4,4)-A)*B
% double(solve(ans(2),s))

%natural frequency
w01 = sqrt(m*g*l/(J+m*(l^2)))

%desired dynamics (fast)
zita_star1 = 0.5;
l1 = (-zita_star1*w01+w01*i)    %/3
l2 = (-zita_star1*w01-w01*i)    %/3

sqrt(1-zita_star1^2)

%desired dynamics (slow)
zita_star2 = 0.7;
w02        = 0.5    %/1.9
tc2        = 2/(zita_star2*w02)
l3 = -zita_star2*w02*(1+i)
l4 = -zita_star2*w02*(1-i)

%control gains (positive definite)
%state-feedback stabilizing control (place)
p = [l1,l2,l3,l4]
K = -place(A,B,p)

%feedforward gain
kr = 1/(C*inv(A-B*K)*B)

%control gains (LQR design)
%eigenvalues analysis
%Riccati
R = 100
Q = [ 1  0   0   0,
      0 1e2  0   0,
      0  0  1e2  0,
      0  0   0  1e2];

Ar = A

Br = B

[gains,P,poles] = lqr(Ar,Br,Q,R,0)
% =================================
% %Lyapunov
Q_bar = Q+P*Br*inv(R)*Br'*P
K     = -(inv(R)*Br'*P)
AL    = Ar-Br*(inv(R)*Br'*P)

PL = lyap(AL',Q_bar)
-((AL')*PL+PL*AL)
% =================================
%Overshoot and time constant
tauL  = 2*min(eig(P))/min(eig(Q_bar))

P_eigs = eig(P)
Q_eigs = eig(Q_bar)

overS = sqrt(max(eig(P))/min(eig(P)))

kr = [0,0,0,0]

% ========================================================================
%simulation
sim('Cart_pendulum_sim.slx')
% ========================================================================


