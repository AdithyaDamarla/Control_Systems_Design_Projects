
%=================================================
%%LINEARIZATION TOOL (Gang-of-Four, 'Go4')
%=================================================

mdl = 'Dynamic_steering_control_Go4';
op = findop(mdl,(1/2)*time)
close all

%-------------------------------------------------
%SENSITIVITY
io1(1) = linio('Dynamic_steering_control_Go4/ref',1,'input');
io1(2) = linio('Dynamic_steering_control_Go4/Add',1,'sensitivity');
io1

linsys1 = linearize(mdl,op,io1)

Am1=double(linsys1.A);
Bm1=double(linsys1.B);
Cm1=double(linsys1.C);
Dm1=double(linsys1.D);

%tranfer function
[NUM1,DEN1] = ss2tf(Am1,Bm1,Cm1,Dm1,1) %(from r to e)
S = tf([NUM1],[DEN1])
% pzmap(S)
bode(S)
grid on
%-------------------------------------------------
%CONTROL SENSITIVITY
io2(1) = linio('Dynamic_steering_control_Go4/ref',1,'input');
io2(2) = linio('Dynamic_steering_control_Go4/C(s)',2,'sensitivity');
io2

linsys2 = linearize(mdl,op,io2)

Am2=double(linsys2.A);
Bm2=double(linsys2.B);
Cm2=double(linsys2.C);
Dm2=double(linsys2.D);

%tranfer function
[NUM2,DEN2] = ss2tf(Am2,Bm2,Cm2,Dm2,1) %(from r to u)
CS = tf([NUM2],[DEN2])
% pzmap(CS)
bode(CS)
grid on
%-------------------------------------------------
%LOAD SENSITIVITY
io3(1) = linio('Dynamic_steering_control_Go4/dist',1,'input');
io3(2) = linio('Dynamic_steering_control_Go4/Add',1,'sensitivity');
io3

linsys3 = linearize(mdl,op,io3)

Am3=double(linsys3.A);
Bm3=double(linsys3.B);
Cm3=double(linsys3.C);
Dm3=double(linsys3.D);

%tranfer function
[NUM3,DEN3] = ss2tf(Am3,Bm3,Cm3,Dm3,1) %(from d to e)
PS = tf([NUM3],[DEN3])
% pzmap(PS)
bode(PS)
grid on
%-------------------------------------------------
%COMPLEMENTARY SENSITIVITY (Tracking)
io4(1) = linio('Dynamic_steering_control_Go4/ref',1,'input');
io4(2) = linio('Dynamic_steering_control_Go4/P(s)',2,'sensitivity');
io4

linsys4 = linearize(mdl,op,io4)

Am4=double(linsys4.A);
Bm4=double(linsys4.B);
Cm4=double(linsys4.C);
Dm4=double(linsys4.D);

%tranfer function
[NUM4,DEN4] = ss2tf(Am4,Bm4,Cm4,Dm4,1) %(from r to y)
PCS = tf([NUM4],[DEN4])
% pzmap(PCS)
bode(PCS)
grid on
%=================================================

close all

%total plot
bode(S,CS,PS,PCS)
grid on
title('Gang-of-Four "S","CS","PS","PCS"')
% ylim([-100 20])

% % figure
% % pzmap(S,CS,PS,PCS)

%=================================================
% % % S
% % % CS
% % % PS
% % % PCS
% % % 
% % % C=CS/S;
% % % P=PS/S;
% % % PC = P*C
% % % 
% % % Tracking= PC/(1+PC)
% % % 
% % % figure
% % % bode(PCS,Tracking)
% % % grid on





























