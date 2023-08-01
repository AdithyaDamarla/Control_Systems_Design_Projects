
clear all
close all
clc

syms s V mu

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
%%SYSTEM STABILITY
%At which speed the system becomes unstable?

Ev = eig(A)
Sq = beta/J-beta^2/(J*m*V^2)+alpha*gamma/(V^2)
%-------------------------------------------------
%%ZERO-FREQUENCY GAINS
%What is the expected behavior

%1 (y=vy)
Zf1 = (b1*gamma/V-b2*(V-beta/(m*V)))/Sq
Vzf1=double(solve(Zf1,V))

%2 (y=w)
Zf2 = (b2*alpha/V+b1*beta/(J*V))/Sq
Vzf2=double(solve(Zf2,V))
%=================================================

%symbolic natural frequency and damping
wn   = sqrt(beta/J-beta^2/(J*m*V^2)+alpha*gamma/(V^2))
zita = ((alpha+gamma)/V)*(1/(2*wn))

%%QUESTIONS
%=================================================
%Question 1.1 (OSCILLATIONS)
%At which speed do the oscillations start?
%at which speed v is damping smaller than 0.7?
Vosc = double(solve(zita-0.7,V))

%constant longitudinal speed
V = Vosc            %[m/s]
double(subs(zita))
%=================================================
%Question 1.2 (ROOT LOCUS) - pole zeroes map
%Draw the root locus for the eigenvalues  as v>0 varies
%Draw the root locus for the eigenvalues  as MU varies
%%System analysis (2 order)

figure
for V=1:1:Vosc

   E = double(subs(eig(A)));
   pzmap(E(1),E(2));
   hold on
end
grid on
%-------------------------------------------------
%MU varying symbolic plot

V=29.9238
figure
for mu=0.1:0.1:1.0

   E = double(subs(eig(A)));
   pzmap(E(1),E(2));
   hold on
   
end
grid on
%=================================================
%Question 2 (MINIMUM/NON-MINIMUM PHASE)
%The system is minimum phase if v>0 but
%it is non minimum phase if v<0, 

syms V

%1 (y=vy)
P1=((det(Cvy*(inv(s*eye(2,2)-A))*b)))
poles1 = double(solve(1/ans,s))
[N1,D1] = numden(P1)
CN1 = coeffs(N1) 
double(CN1/CN1(end))
CD1 = coeffs(D1)
double(CD1/CD1(end))

Vm =10
V=Vm
subs(N1)
(solve(N1,s))
double(subs(ans))

Zmp1 = -(b1*gamma/V-b2*(V-beta/(m*V)))/b1

syms V
Zmp1 = -(b1*gamma/V-b2*(V-beta/(m*V)))/b1
Vnm1 = double(solve(Zmp1,V))
%-------------------------------------------------
%2 (y=w)
P2=det(Cw*(inv(s*eye(2,2)-A))*b)
poles2 = double(solve(1/ans,s))
[N2,D2] = numden(P2)
CN2 = coeffs(N2)
double(CN2/CN2(end))
CD2 = coeffs(D2)
double(CD2/CD2(end))

Vm =10
V=Vm
subs(N2)
(solve(N2,s))
double(subs(ans))

Zmp2 = -(b2*alpha/V+b1*beta/(J*V))/b2

syms V
Zmp2 = -(b2*alpha/V+b1*beta/(J*V))/b2
Vnm2 = double(solve(Zmp2,V))
%=================================================
%Question 3 (STEP RESPONSE)
%Evaluate the step response when the steering angle
%is 0.05 rad and the speed is 10 m/s or -10m/s.

%speed value [ %V \in {Vosc,Vm,Vnmi,Vzfi} ]
V = Vzf1(2)



%eigencvalues, natural frequency and damping
E    = double(subs(eig(A)))
wn   = double(sqrt(beta/J-beta^2/(J*m*V^2)+alpha*gamma/(V^2)))
zita = double(((alpha+gamma)/V)*(1/(2*wn)))
%=================================================

%%Simulation %V \in {Vosc,Vm,Vnm}
%=================================================
delta_step = 0.05 %[rad]
sim('Dynamic_steering_sim.slx')
%=================================================

hold on
plot(x_position,y_position)



















