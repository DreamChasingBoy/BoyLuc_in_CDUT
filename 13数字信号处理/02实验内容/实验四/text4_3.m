clc;
clear;
fs=600;%采样频率
f1=100;
f2=180;
f3=250;
N=1024;%100、180和250的最小公倍数是900，N取2的整数次幂
n=linspace(1,N,1024);
t=n/fs;
y=sin(200*pi*t)+sin(360*pi*t)+sin(500*pi*t);
Y=fft(y,N);
amplitude=abs(Y);
f=n*fs/N;
subplot(3,1,1),plot(f,amplitude);
title('滤波前');xlabel('f');ylabel('幅值');
Wp=[(f1+10)/(fs/2) (f3-10)/(fs/2)];
Ws=[(f2-10)/(fs/2) (f2+10)/(fs/2)];
[nn,Wc]=buttord(Wp,Ws,1,100);%nn是巴特沃斯滤波器阶数
[B,A]=butter(nn,Wc,'stop');%传递函数的参数
z=filter(B,A,y);%对y进行滤波
Z=fft(z,1024);
amplitude=abs(Z);
subplot(3,1,2),plot(f,amplitude);
title('不保留180Hz滤波后');xlabel('f');ylabel('幅值');
[h1,w1]=freqz(B,A,1024);
subplot(3,1,3),plot(w1/pi*(fs/2),abs(h1));
title('滤波器频谱');xlabel('f');ylabel('幅值');