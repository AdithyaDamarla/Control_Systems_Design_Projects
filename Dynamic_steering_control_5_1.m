
clear all
close all
clc

%Simulation time
time = 10;

syms s V

%%System Parameters
%=================================================
mu = 1.0        %[.]        friction coefficient
m  = 1864       %[Kg]       mass
J  = 3654       %[Kg*m^(2)] momentum
cr = 213800 *mu %[N/rad]    rear cornering stiff.
cf = 101600 *mu %[N/rad]    front cornering stif.
lr = 1.32       %[m]        rear wheel-CM distance
lf = 1.51       %[m]        front wheel-CM distance

%%Combined Parameters
alpha= cf/m+cr/m
beta = -cf*lf+cr*lr
gamma= (cf*lf^2+cr*lr^2)/J

b1   = cf/m
b2   = cf*lf/J
%=================================================

%%System Matrices
%=================================================
A = [  -alpha/V   -(V-beta/(m*V)),
      beta/(J*V)        -gamma/V];
  
b = [ b1 ; b2];

Cvy = [ 1  0 ];
Cw  = [ 0  1 ];
%-------------------------------------------------
%%SYSTEM ANALYSIS (V dependent)
%Native A,b,C system characteristics

Ev = eig(A)

%V current value
% V = 107.7256/3.6 %[m/s]
V = 120/3.6

Ev = double(subs(Ev))
tc = abs(1/real(Ev(1)))      %native time constant

%natural frequency and damping
wn   = sqrt(beta/J-beta^2/(J*m*V^2)+alpha*gamma/(V^2))
zita = ((alpha+gamma)/V)*(1/(2*wn))
%-------------------------------------------------
%%SYSTEM OBSERVABILITY/REACHABILITY (V dependent)
%How much is observable and reachable the system A,b,C?
C = Cw  %w considered as output

%Observability Matrix
O    = [ C; C*A ]                       %column 
% O    = [ 0,1 ; beta/(J*V) -gamma/V]
d_OB = det(O)
d_OB =double(subs(det(d_OB)))

O  = double(subs(O))
A  = double(subs(A))
OB = obsv(A,C)

%Reachability Matrix
R   = [ b, A*b ]                            %row 
% R   = [ b1 -b1*alpha/V-b2*(V-beta/(m*V)),
%         b2  b1*beta/(J*V)-b2*gamma/V ]
d_R = det(R)
d_R =double(subs(det(R)))

R  = double(subs(R))
A  = double(subs(A))
RE = ctrb(A,b)
%=================================================

%%QUESTIONS (from HM2)
%=================================================
%Question 1.1 (OSCILLATIONS)
%At which speed do the oscillations start?
%at which speed v is damping smaller than 0.7?
% % 
% % Vosc = double(solve(zita-0.7,V))
% % 
% % %constant longitudinal speed
% % V = Vosc            %[m/s]
% % double(subs(zita))
%=================================================
%Question 1.2 (ROOT LOCUS) - pole zeroes map
%Draw the root locus for the eigenvalues  as v>0 varies
%Draw the root locus for the eigenvalues  as MU varies
%%System analysis (2 order)

% % figure
% % for V=1:1:Vosc
% % 
% %    E = double(subs(eig(A)));
% %    pzmap(E(1),E(2));
% %    hold on
% %    
% % end
% % grid on
%-------------------------------------------------
%MU varying symbolic plot

% % V=29.9238 %the speed at which zita = 0.7 (mu=1)
% % figure
% % for mu=0.1:0.1:1.0
% % 
% %    E = double(subs(eig(A)));
% %    pzmap(E(1),E(2));
% %    hold on
% %    
% % end
% % grid on
%=================================================

%%OUTPUT-FEEDBACK CONTROLLER DESING
%=================================================
%Ackeramann Observer desing (V dependent)
zita_star_o = 0.7
time_const_o= tc/2       %*3
wn_star_o   = 1/(time_const_o*zita_star_o)

L1_o=2*zita_star_o*wn_star_o
L0_o=wn_star_o^2

%A(V) current value
% V = 100/3.6
% A = double(subs(A))

%Ackermann observer
Ko = -(A^2+L1_o*A+L0_o*eye(2,2))*inv(O)*[0;1]

%corresponding poles
Po=eig(A+Ko*C)

Ko = -acker(A',C',Po)

Ko1 = Ko(1)
Ko2 = Ko(2)

%-------------------------------------------------
%Ackermann Controller design
zita_star_c = 0.7
time_const_c= time_const_o*2       %/3
wn_star_c   = 1/(time_const_c*zita_star_c)

L1_c=2*zita_star_c*wn_star_c
L0_c=wn_star_c^2

%A(V) current value
% V = 100/3.6
% A = double(subs(A))

%Ackermann observer
Kc = -[0,1]*inv(R)*(A^2+L1_c*A+L0_c*eye(2,2))

%corresponding poles
Pc=eig(A+b*Kc)

Kc = -acker(A,b,Pc)

Kc1 = Kc(1)
Kc2 = Kc(2)
%=================================================

%%Simulation {System+Observer+Controller}
%=================================================
%Parameter variation
mu = 1 
cr = 213800 *mu %[N/rad]    rear cornering stiff.
cf = 101600 *mu %[N/rad]    front cornering stif.

alpha= cf/m+cr/m
beta = -cf*lf+cr*lr
gamma= (cf*lf^2+cr*lr^2)/J

b1   = cf/m
b2   = cf*lf/J

%-------------------------------------------------
%Initial condition
delta_step  = 0.05 %[rad]
vy_0        = 2
% sim('Dynamic_steering_control_obs.slx')
% sim('Dynamic_steering_control_obs_ctrl.slx')
sim('Dynamic_steer_ctrl_gs.slx')
%=================================================

%%Sensitivity analysis
%=================================================
run('System_IO_linearization_5_1.m')
%=================================================










