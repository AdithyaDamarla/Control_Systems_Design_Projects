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

ht=tf([m*l],[-(Mt*Jt-m^2*l^2) 0 m*g*l*Mt])
figure()
pzmap(ht)
grid on
[n,d]=(tfdata(ht,'v'))

[a,b,c,d]=tf2ss(n,d)

eig(a)


hp=tf([-Jt 0 m*g*l],[-(Mt*Jt-m^2*l^2) 0  m*g*l*Mt 0 0])
figure()
pzmap(hp)
grid on
[n1,d1]=(tfdata(hp,'v'))

[a1,b1,c1,d1]=tf2ss(n1,d1)

eig(a1)

p=sqrt( m*g*l*Mt/(Mt*Jt-m^2*l^2))

z=sqrt( m*g*l/Jt)


