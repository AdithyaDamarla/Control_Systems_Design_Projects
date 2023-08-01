
clear all
close all
clc

syms s

%%System Parameters
g     = 9.81        %[m*s^(-2)]
vx    = (60)/(3.6) %[m*s^(-1)]
L     = 16          %[m]
w_road= 2*pi*vx/L   %[rad*s^(-1)]
h_z   = 0.1         %[m]
%=================================================
k = 20000 %[N/m]
M = 140   %[Kg]
b = 1171  %[N*s*m^(-1)]
%=================================================

%%Tyre Model Parameters
%=================================================
kp = 130000 %[N/m]
m  = 50     %[Kg]
Mp = m;     %[Kg]
bp = 100    %[N*s*m^(-1)]
%=================================================

%%Equilibrium conditon
%=================================================
% ye = x1 + x2
% xe = x2
% ye - xe - x1 = -M*g/k
%=================================================

%%System Matrices A,B,C and Ap,Bp,Cp systems
%=================================================
%=================================================
A = [    0       1,
      -k/M    -b/M];
  
B = [ 0 ; 1/M];

C = [ 1  0 ];

%%System analysis (2 order A,B,C system)
%=================================================
eig(A)
det(C*(inv(s*eye(2,2)-A))*B)
poles = double(solve(1/ans,s))

wn   = sqrt((real(poles(1)))^2+(imag(poles(1)))^2)
wn   = sqrt(k/M)

zita = b/(2*sqrt(k*M))
zita = (-real(poles(1)))/wn
%=======================
Ap = [    0       1,
      -kp/Mp    -bp/Mp];
  
Bp = [ 0 ; 1/Mp];

Cp = [ 1  0 ];
%=================================================
%=================================================

%%System analysis (Bode Diagrams) [at equilibrium]
%=================================================
% % % h21 = tf([1 b/M k/M],[1])
% % % h22 = tf([b k],[1])
% % % h41 = tf([1 (bp+b)/m (kp+k)/m],[1])
% % % h42 = tf([bp kp],[1])
% % % %=============================================
%P_1(s) = x(s)/y(s) %%by considering z(t)=0
% % h1 = tf([-M/m 0 0],[1 (bp/m) (kp/m)])
% % figure
% % bode(h1)
% % title('Bode Diagram P_1(s) = x(s)/y(s) [@z(t)=0]')
% % grid on
% % % %=======================
%P_2(s) = y(s)/u(s) %%by considering z(t)=0
% % h2 = (1/M)*tf([1 ((bp)/m) ((kp)/m)],[1 ((bp+b)/m+b/M) ((kp+k)/m+(b/M)*(bp+b)/m+k/M-(b^2)/(m*M)) ((b/M)*(kp+k)/m+(k/M)*(bp+b)/m-(2*k*b)/(m*M)) ((k/M)*(kp+k)/m-(k^2)/(m*M))])
% % figure
% % bode(h2)
% % title('Bode Diagram P_2(s) = y(s)/u(s) [@z(t)=0]')
% % grid on
% % 
% % % [N2,D2] = tfdata(h2,'v');
% % % PN2=tf(N2,1)
% % % PD2=tf(D2,1)
%double(solve(,s))
% % % %=======================
% % % h02 = (1/M)/(h21-h22*h1/M)
% % % h2*M/M
% % % 
% % % figure
% % % bode(h2)
% % % hold on
% % % bode(h02,'r-.')
% % % grid on
% % % %=======================
%P_3(s) = y(s)/x(s) %%by considering u(t)=0
% % h3 = tf([b/M k/M],[1 b/M k/M])
% % figure
% % bode(h3)
% % title('Bode Diagram P_3(s) = y(s)/x(s) [@u(t)=0]')
% % grid on
%=======================
%P_4(s) = x(s)/z(s) %%by considering u(t)=0
% % h4 = (1/m)*tf([bp ((bp*b)/M+kp) ((b*kp+k*bp)/M) (k*kp/M)],[1 ((bp+b)/m+b/M) ((kp+k)/m+(b/M)*(bp+b)/m+k/M-(b^2)/(m*M)) ((b/M)*(kp+k)/m+(k/M)*(bp+b)/m-(2*k*b)/(m*M)) ((k/M)*(kp+k)/m-(k^2)/(m*M))])
% % figure
% % bode(h4)
% % title('Bode Diagram P_4(s) = x(s)/z(s) [@u(t)=0]')
% % grid on
% % 
% % % [N4,D4] = tfdata(h4,'v');
% % % PN4=tf(N4,1)
% % % PD4=tf(D4,1)
% % % double(solve(,s))
%=======================
% % % h04 = (h42/m)/(h41-h22*h3/m)
% % % h4*m/m*50/50
% % % 
% % % figure
% % % bode(h4)
% % % hold on
% % % bode(h04,'r-.')
% % % grid on
%=======================
%P_5(s) = P_4(s)*P_3(s)= y(s)/z(s)
% % h5 = h3*h4
% % figure
% % bode(h5)
% % title('Bode Diagram P_5(s) = P_3(s)*P_4(s)= y(s)/z(s)')
% % grid on
%=================================================
%=================================================

%%Control gains -- P,PD,PID loops on simple model
%=================================================
%%P controller
%=================================================
% wn
% wn_star = wn*0.34
% 
% a1 = abs(A(2,2))
% a0 = abs(A(2,1))
% 
% kP = M*(a0 - wn_star^2)
% 
% A_d  = A+B*kP*C
% eig(A_d)
% 
% p1 = ans(1)
% p2 = ans(2)
% 
% wn   = sqrt(p1*p2) 
% zita = abs((p1+p2)/(2*wn))
% 
% % hS = tf([1/M],[1 b/M k/M])
% % hP = tf([kP/M],[1])
% % hS*hP
% 
% href = -1*tf([kP/M],[1 b/M (k-kP)/M])
% % herr = -1*tf([1 b/M (k)/M],[1 b/M (k-kP)/M])
% 
% figure
% bode(href)
% title('Bode Diagram y(s)/y*(s) [u_1(t)=kP*y~]')
% grid on
% 
% % figure
% % bode(herr)
% % title('Bode Diagram y~(s)/y*(s) [u_1(t)=kP*y~]')
% % grid on
%=================================================
%%PD controller // PID Controller
%=================================================
wn
wn_star   = wn*1.05/2 %wn*2 %1.5
zita
zita_star=0.7    %0.7 %1.0

a1 = abs(A(2,2))
a0 = abs(A(2,1))

kP = M*(a0 - wn_star^2)
kD = M*(a1 - 2*zita_star*wn_star)

kI = -10000       %-1000000

kPD= [kP kD]

A_d  = A+B*kPD
eig(A_d)

p1 = ans(1)
p2 = ans(2)

p = [p1 p2]
K_aut = -place(A,B,p)

A_d  = A+B*(K_aut)
eig(A_d)

wn   = sqrt(p1*p2) 
zita = abs((p1+p2)/(2*wn))

%%tracking performance of Controller
hPD = -1*tf([kD/M kP/M],[1 (b-kD)/M (k-kP)/M])
hPID= -1*tf([kD kP kI],[M (b-kD) (k-kP) (-kI)])

figure
bode(hPD)
title('Bode Diagram y(s)/y*(s) [u_2(t)=kP*y~+kD*y.~]')
grid on

figure
bode(hPID)
title('Bode Diagram y(s)/y*(s) [u_3(t)=kP*y~+kD*y.~+kI*int(y~)]')
grid on
%=================================================
%=================================================

%%Engineering Derivative
%=================================================
w_T  = 100                       %[rad/s]
f_T  = w_T/(2*pi)               %[1/s]
tau  = 1/f_T;                    %[s]


hPc  = tf([0 kP],[1])
hPDc = tf([kD kP],[1])
hPIDc= tf([kD kP kI],[1 0])

figure
subplot(1,3,1)
bode(hPc)
title('Bode Diagram u_(_1_)(s)=kP*y~]')
grid on

subplot(1,3,2)
bode(hPDc)
title('Bode Diagram u_(_2_)(s)=kP*y~+kD*y.~+]')
grid on

subplot(1,3,3)
bode(hPIDc)
title('Bode Diagram u_(_3_)(s)=kP*y~+kD*y.~+kI*int(y~)]')
grid on

hold on
hPDeng = tf([(kP*tau) (kP+kD+kI*tau) kI],[tau 1 0])
bode(hPDeng)
% title('Bode Diagram u_(_3_)+u_(_3_)^E^n^g(s)=kP*y~+kD*y.~+kI*int(y~]')
legend('u_(_3_)','u_(_3_)^E^n^g')
grid on
%=================================================


close all

%%Initial conditions (+ running simulation)
%=================================================
y_0 = -0.05;
y_r = -0.025;
sim('Active_suspension_with_control_sim2.slx')
%=================================================



















