% Aplly rich stimulus 

kp = 33.79;
ke = -4.49;

t = input.time(100:end);
sigs = outputs.signals.values(100:end);

utrend = input.signals.values(100:end); % Entrada - Input signal
thetae = sigs(:,1); % Potenciómetro - Potentiometer signal
alphae = sigs(:,2); % Extensómetro - Starin gage signal

hold all
plot(t, utrend)
plot(t, thetae)
plot(t, alphae)
legend('utrend', 'thetae', 'alphae')
hold off

ytrend = thetae*kp + alphae*ke;

figure()
plot(t, ytrend)
legend('ytrend');

lambda = 0.8;
Afilt = [1 -lambda];
Bfilt = (1-lambda)*[1 -1];
% Filtragem seguida de eliminação de tendências
% Filtering and detrending
yf = filter(Bfilt,Afilt,ytrend);

figure();
plot(t, yf);
legend('filtered');

u = detrend(utrend, 'constant');
y = detrend(yf, 'constant');

z = [yf u];
na = 3; % AR part
nb = 2; % X part
nc = na; % MA part
nk = 1; % Atraso puro – pure delay
nn = [na nb nc nk];
th = armax(z,nn); % th is a structure in identification toolbox format

[den1, num1] = polydata(th);

yfsim = filter(num1,den1,u); % Equivalent to idsim(u,th);

hold on;
plot(t, yfsim)
legend('yfsim');
hold off;
[num,den] = eqtflength(num1,conv(den1,[1 -1])); % Integrador

[A, B, C, D] = tf2ss(num, den);