% Sensor Data Conversion
PotentiometerGain = 33.79;
ExtensometerGain = -4.49;

% System State-Space
A = [3.3545 -4.3521 2.6058 -0.6082; 1 0 0 0; 0 1 0 0; 0 0 1 0];
B = [1;0;0;0];
C = [-0.0657 0.1152 0 0];
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
open_system('Implementation.slx');

% Set Parameters of Signal Generator
set_param('Implementation/Signal Generator','Waveform','square');
set_param('Implementation/Signal Generator','Amplitude','30');
set_param('Implementation/Signal Generator','Frequency','2');

% Simulate
sim('Implementation.slx');

