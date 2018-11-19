fs = 50;
T = 60;
f = 1;
t = (0: 1/fs: T)';
%u = square(2*pi*f*t);

B = 0.08;
u = idinput(length(t), 'PRBS', [0 B]);
mean(u)
