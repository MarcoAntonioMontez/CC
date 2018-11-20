% Sensor Data Conversion
PotentiometerGain = 180/5.3145;
ExtensometerGain = -3.1481;

% System State-Space
A = [3.11506910744011 -3.74010634305672 2.06382118501694 -0.438783949400328; 1 0 0 0; 0 1 0 0; 0 0 1 0];
B = [1;0;0;0];
C = [-0.0767099115028891 0.161398714293952 0 0];
D = [0];

% LQR
Q = C'*C;
R = 100;
[K,~,p] = dlqr(A,B,Q,R);

% LQE
Qe = 100*eye(4);
Re = 1;
[M,~,~,pe] = dlqe(A,eye(4),C,Qe,Re);  

% Integrator
Int_gain = 0.1;

% Pre-filter
N = inv([A-eye(4,4), B; C,0])*[zeros(4,1);1];
Nx = N(1:4,:);
Nu = N(5,:);
Nbar = Nu+K*Nx;

% Open Simulink
open_system('LQG.slx');

% Set Parameters of Signal Generator
set_param('LQG/Signal Generator','Waveform','square');
set_param('LQG/Signal Generator','Amplitude','90');
set_param('LQG/Signal Generator','Frequency','2');

% Simulate
sim('LQG.slx');

