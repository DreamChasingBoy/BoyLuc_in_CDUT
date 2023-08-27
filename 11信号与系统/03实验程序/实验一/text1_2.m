t=linspace(-5,5,1000);
n=linspace(-5,5,10);
f=cos(2*t);
F=cos(2*n);
subplot(2,1,1),plot(t,f);
title('f(t)=cos(2t)');
subplot(2,1,2),stem(n,F);
title('f[n]=cos(2n)');