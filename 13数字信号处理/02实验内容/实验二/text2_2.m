clc;
clear;
x1=[1,1,1,1];
x2=[1,1,1,1,1];
y1=conv(x1,x2);
n=length(y1);
subplot(3,1,1),
stem(1:n-1,y1(1:7));
title('线性卷积');
y_7=cconv(x1,x2,7);
subplot(3,1,2),
stem(1:7,y_7);
title('7点圆周卷积cconv');
X1E=fft(x1,n-1);
X2E=fft(x2,n-1);
y_7_dft=ifft(X1E.*X2E);
subplot(3,1,3),
stem(1:7,y_7_dft);
title('7点圆周卷积DFT');

figure;
subplot(3,1,1),
stem(1:n,y1);
title('线性卷积');
y_8=cconv(x1,x2,8);
subplot(3,1,2),
stem(1:8,y_8);
title('8点圆周卷积cconv');
X1E=fft(x1,n);
X2E=fft(x2,n);
y_8_dft=ifft(X1E.*X2E);
subplot(3,1,3),
stem(1:8,y_8_dft);
title('8点圆周卷积DFT');

figure;
y1=[y1 0 0 ];
subplot(3,1,1),
stem(1:10,y1);
title('线性卷积');
y_10=cconv(x1,x2,10);
subplot(3,1,2),
stem(1:10,y_10);
title('10点圆周卷积cconv');
X1E=fft(x1,10);
X2E=fft(x2,10);
y_10_dft=ifft(X1E.*X2E);
subplot(3,1,3),
stem(1:10,y_10_dft);
title('10点圆周卷积DFT');




