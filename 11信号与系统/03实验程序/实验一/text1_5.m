t=linspace(-10,10,21);
b0=0;%信号发生突变的时刻
ut=stepfun(t,b0);%产生单位的阶跃信号ut
utt=stepfun(t,b0);
subplot(2,1,2),stem(t,ut);
title('u(t)');
y=[0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0];
subplot(2,1,1),stem(t,y);
title('δ(t)');

