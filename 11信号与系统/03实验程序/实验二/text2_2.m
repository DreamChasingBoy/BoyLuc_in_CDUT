p=0.2;
a=[1,1,0.25];
b=1;
subplot(2,1,1)
impz(b,a)
title('单位冲激响应');
t=0:p:10;
f=ones(1,length(t)); 
y=filter(b,a,f);
subplot(2,1,2)
stem(t,y);
title('单位阶跃响应');

