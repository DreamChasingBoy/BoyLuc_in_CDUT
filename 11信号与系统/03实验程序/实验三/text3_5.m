clc;
clear;
t=linspace(1,1000,1000);
ft=sin(200*pi*t)+sin(500*pi*t);
subplot(2,1,1),plot(t,ft);
Ft=fft(ft);
subplot(2,1,2),plot(t,Ft);