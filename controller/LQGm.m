% System State-Space
A = [3.3545 -4.3521 2.6058 -0.6082; 1 0 0 0; 0 1 0 0; 0 0 1 0];
B = [1;0;0;0];
C = [-0.0657 0.1152 0 0];
D = [0];

den = [1, -2.354, 1.998, -0.6082];
num = [0,-0.06569, 0.1152];


% LQR
Q = C'*C;
R = 1;
[K,~,p] = dlqr(A,B,Q,R);
figure()
rlocus(tf(num,den,0.02), [1:100]);
figure();
% LQE
Qe = 100*eye(4);
Re = 1;
[M,~,~,pe] = dlqe(A,eye(4),C,Qe,Re);  
rlocus(tf(num,den,0.02), [1:100]);
figure();
% Pre-filter
N = inv([A-eye(4,4), B; C,0])*[zeros(4,1);1];
Nx = N(1:4,:);
Nu = N(5,:);
Nbar = Nu+K*Nx;

%dados do modelo
Ts=0.02;
G = ss(A,B,C,D,Ts); %Sistema a controlar
T_lqr = ss(A,B,K,D,Ts);% Função tranferência do sistema controlado
C_lqr = ss(A-B*K,B*Nbar,C,D,Ts);

[NC_lqr,DC_lqr] = tfdata(C_lqr,'v');
subplot(1,2,1)
zplane(NC_lqr,DC_lqr)
ax = axis;
subplot(1,2,2)
zplane([],p)
axis(ax)


% Open Simulink
open_system('LQG.slx');

% Set Parameters of Signal Generator
set_param('LQG/Signal Generator','Waveform','square');
set_param('LQG/Signal Generator','Amplitude','90');
set_param('LQG/Signal Generator','Frequency','0.4');

% Simulate
sim('LQG.slx');

