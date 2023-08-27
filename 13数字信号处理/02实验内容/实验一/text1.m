N=10;
t=0:N;
x1=zeros(1,N+1);
x1(8)=1;
subplot(2,2,1),stem(t,x1);
title('单位冲激序列');
xlabel('n');ylabel('幅值');

x2=[0,0,0,0,0,0,0,1,1,1,1];
subplot(2,2,2),stem(t,x2);
title('单位阶跃序列');
xlabel('n');ylabel('幅值');

N3=500;
t3=0:N3;
y3=sin((pi/100).*t3+pi/2);
subplot(2,2,3),plot(t3,y3);axis([-1,N3+1,-1.1,1.1]);
title('正弦函数');
xlabel('x');ylabel('幅值');

N4=10;
t4=0:N4;
y4=0.4.^t4;
subplot(2,2,4),stem(t4,y4);
% axis([-1,N3+1,-1.1,1.1]);
title('指数序列0.4^n');
xlabel('n');ylabel('幅值');