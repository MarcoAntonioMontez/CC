%%

% % load('lab2_1');
% % figure()
% % plot(Data.time,Data.signals.values);
% % 
% % load('lab2_2');
% % figure()
% % plot(outputs.time,outputs.signals.values(:,1));
% % 
% % load('lab2_3');
% % figure()
% % plot(outputs.time,outputs.signals.values(:,1));
% % 
% load('lab2_pbrs1');
% figure()
% plot(outputs.time,outputs.signals.values);
% 
% load('lab2_pbrs2');
% figure()
% plot(outputs.time,outputs.signals.values);
% 
% load('lab2_pbrs_3');
% figure()
% plot(outputs.time,outputs.signals.values);



load('lab2_square2');
% figure()
% plot(outputs.time,outputs.signals.values);
valid_time = outputs.time(251:2001);
y_valid_poten = outputs.signals.values(251:2001,1);
y_valid_exten = outputs.signals.values(251:2001,2);

y_valid_poten = y_valid_poten - mean(y_valid_poten);
y_valid_exten = y_valid_exten - mean(y_valid_exten);
 valid_input = input.signals.values(251:2001);
% 
% figure()
% hold on
% plot(valid_time,y_valid_poten);
% plot(valid_time,y_valid_exten);
% 
% 
% figure()
% plot(input.time, input.signals.values)

%% Aplly rich stimulus 

kp = 33.79;
ke = -4.49;

t = valid_time;
sigs = y_valid_poten;

utrend = valid_input; % Entrada - Input signal
thetae = y_valid_poten; % Potenciómetro - Potentiometer signal
alphae = y_valid_exten; % Extensómetro - Starin gage signal

figure()
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
na = 4; % AR part
nb = 3; % X part
nc = na; % MA part
nk = 1; % Atraso puro – pure delay
nn = [na nb nc nk];
th = armax(z,nn); % th is a structure in identification toolbox format
th1 = th;
[den1, num1] = polydata(th);

yfsim = filter(num1,den1,u); % Equivalent to idsim(u,th);

error = norm((yf-yfsim),2)
hold on;
plot(t, yfsim)
legend('yfsim');
hold off;
[num,den] = eqtflength(num1,conv(den1,[1 -1])); % Integrador

[A, B, C, D] = tf2ss(num, den);

y_model = dlsim(A, B, C, D, u);

figure()
hold all
plot(t,y_model)
%plot(t,yf)
legend('model and trend')

