clc;clear;close all;
fs=44100; %语音信号采样频率为22050
x1=audioread('我的祖国.wav'); %读取语音信号的数据，赋给变量x1
sound(x1,fs); %播放语音信号
y1=fft(x1,1024); %对信号做1024点FFT变换
f=fs*(0:511)/1024;
figure(1);
plot(x1) %做原始语音信号的时域图形
title('原始语音信号');xlabel('time n');ylabel('fuzhi n');
figure(2);freqz(x1) %绘制原始语音信号的频率响应图
title('频率响应图')
figure(3);subplot(2,1,1);
plot(abs(y1(1:512))) %做原始语音信号的FFT频谱图
title('原始语音信号FFT频谱');
subplot(2,1,2);
plot(f,abs(y1(1:512)));
title('原始语音信号频谱')
xlabel('频率/Hz');ylabel('幅值');
X1=fft(x1);
L=length(X1);
k=0:L-1;
c1=0.1*sin (2*pi*6000*k/fs);
x2=x1+c1';
sound(x2,44100)
y2=fft(x2,1024);
figure(1);
plot(k,x2);
title('加噪后的信号');
xlabel('time n');
ylabel('fuzhi n');
figure(2);
subplot(2,1,1);
plot(f,abs(y1(1:512)));
title('原始语音信号频谱');
xlabel('频率/Hz');ylabel('幅值');hold on
subplot(2,1,2);
plot(f,abs(y2(1:512)));
title('加噪后的信号频谱');
xlabel('频率/Hz');ylabel('幅值');hold on

wp=0.15*pi;%实际的通带截止频率为(wp/pi)*fs/2
ws=0.2*pi;
wdelta=ws-wp;
wn=(ws+wp)/2;
N=ceil(6.2*pi/wdelta);%选汉明窗
Window=hanning(N+1);
b=fir1(N,wn/pi,Window);
s=filter(b,1,x2);
SE=fft(s,1024);
figure;
plot(f,abs(SE(1:512)));
title('去噪后的信号频谱');
xlabel('频率/Hz');ylabel('幅值');