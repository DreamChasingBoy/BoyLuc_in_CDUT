clear;
clc;
N=10;
t1=0:0.01:N;
t1=t1(1:N*100);
un=ones(1,N*100);
xn=(6.^t1).*un;
subplot(1,2,1),stem(t1,xn);
title('6^n*u(n)');
xlabel('n');ylabel('幅值');
b=[1];
a=[1,-6];
[h,w]=freqz(b,a);
subplot(1,2,2),
plot(w/pi,abs(h));grid
title('幅度谱')
xlabel('\omega/\pi');ylabel('幅度')