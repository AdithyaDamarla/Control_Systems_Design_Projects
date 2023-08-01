
close all


kP = 1.07685821962111
kI = 1.0858024492111
kD = 0.2358332669453


N = 18.3345971303554
tau = 1/N

hP  = tf([1 0.9],[1 0.5 1])
pzmap(hP)
grid on

hC= ((kP*tau+kD)/tau)*tf([1 (kI*tau+kP)/(kP*tau+kD) kI/(kP*tau+kD)],[1 1/tau 0])

G = hP*hC
% pzmap(H)

figure
rlocus(G)
grid on

figure
bode(G/(1+G))
grid on