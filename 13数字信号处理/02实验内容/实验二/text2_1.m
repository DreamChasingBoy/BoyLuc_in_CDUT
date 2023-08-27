clc;
clear;
n=1000;
x=[ones(1,7),zeros(1,n-7)];
w=linspace(0,2*pi,n);
X=myDTFT(x,w);
subplot(2,2,1),
plot(w,X);
title('DTFT');

N=8;
xx=[1 1 1 1];
X_8=abs((fft(xx,8)));
w=0:2*pi/(N-1):2*pi;
subplot(2,2,2),
stem(w/pi,X_8);
title('8点DFT');

N=16;
X_16=abs((fft(xx,16)));
w=0:2*pi/(N-1):2*pi;
subplot(2,2,3),
stem(w/pi,X_16);
title('16点DFT');

N=128;
X_128=abs((fft(xx,128)));
w=0:2*pi/(N-1):2*pi;
subplot(2,2,4),
stem(w/pi,X_128);
title('128点DFT');

% 补零可以让结果变得平滑