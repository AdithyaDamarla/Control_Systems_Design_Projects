
close all


kP = 4.43835153116722
kI = 4.44585214018421
kD = 0.113035926291012


N = 5.94701634168054
tau = 1/N


P  = tf([1 0.9],[1 0.5 1])
% pzmap(P)
% grid on

C= 1*tf([1 (kI*tau+kP)/(kP*tau+kD) kI/(kP*tau+kD)],[1 1/tau 0])
pzmap(C)
grid on

G = P*C

%S sensitivity
S = 1/(1+G)
figure
bode(S)
grid on

%T complementary sensitivity (tracking)
T = G*S
figure
bode(T)
grid on

%CS control sensitivity
CS = C*S
figure
bode(CS)
grid on

%PS load sensitivity
PS = P*S
figure
bode(PS)
grid on


close all

bode(S,T,CS,PS)
grid on
title('GoF: PID Numerical Tuning Design')

























