
clear all
close all
clc

syms s

%%System Parameters
%=================================================
k = 20000 %[N/m]
M = 140   %[Kg]
b = 1171  %[N*s*m^(-1)]
g = -9.81 %[m*s^(-2)]

ye = M*g/k
%=================================================

%%System Matrices
%=================================================
A = [    0       1,
      -k/M    -b/M];
  
B = [ 0 ; 1/M];

C = [ 1  0 ];
%=================================================

%%System analysis (2 order)
%=================================================
eig(A)

det(C*(inv(s*eye(2,2)-A))*B)
poles = solve(1/ans,s)

wn   = sqrt((real(poles(1)))^2+(imag(poles(1)))^2)
wn   = sqrt(k/M)

zita = b/(2*sqrt(k*M))
zita = (-real(poles(1)))/wn


% figure
% %%Root locus
h1 = tf([1/M],[1 b/M k/M])
% rlocus(h1)
% grid on

figure
%%Bode diagram 1
bode(h1)
grid on

% figure
% %%Root locus (Step response)
h2 = tf([-10/M],[1 b/M k/M 0])
% rlocus(h2)
% grid on
%=================================================

%%Parametric plot (10cm step response)
%=================================================
% % wzk =[]
% % figure
% % for x = k/10:k/1:k*10
% %   
% % h1x = tf([1/M],[1 b/M x/M])
% % 
% % wnx   = sqrt(x/M)
% % zitax = b/(2*sqrt(x*M))
% % 
% % wzk = [ wzk ; wnx zitax ]
% % bode(h1x)
% % 
% % grid on
% % hold on
% % end

% % wzb =[]
% % figure
% % for y = b/10:b/1:b*10
% %   
% % h1y = tf([1/M],[1 y/M k/M])
% % 
% % wny   = sqrt(k/M)
% % zitay = y/(2*sqrt(k*M))
% % 
% % wzb = [ wzb ; wny zitay ]
% % bode(h1y)
% % 
% % grid on
% % hold on
% % end
%=================================================

%%System residuals (10cm step response)
%=================================================
k1 = -10/(wn^2)
k2 = 5i*poles(1)/(abs(imag(poles(1)))*(wn^2))
k3 = conj(k2)
%=================================================

y_0 = 0;
sim('Active_suspension_sim.slx')




















