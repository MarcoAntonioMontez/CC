load('input_and_y_pbrs')

load('z_yf_u')

z = outputs.values;

[~, fit_square] = compare(z, th);
[~, fit_1] = compare(z, th);
[~, fit_2] = compare(z, th);
[~, fit_3] = compare(z, th);
[~, fit_4] = compare(z, th);

u = z1(:,2);


yfsim = filter(num1,den1,u); % Equivalent to idsim(u,th);

error = norm((yf-yfsim),2)

figure();
hold on;
plot(t, yf);
plot(t, yfsim);
legend('filtered','yfsim');
xlabel('tempo (s)')
ylabel('angulo total diferenciado')
hold off;
[num,den] = eqtflength(num1,conv(den1,[1 -1])); % Integrador

[A, B, C, D] = tf2ss(num, den);

y_model = dlsim(A, B, C, D, u);

figure()
hold all
plot(t,y_model)
plot(t,ytrend)
%plot(t,yf)
legend('model','trend')

