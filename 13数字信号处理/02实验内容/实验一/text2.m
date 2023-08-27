N1=10;
t1=0:N1;
y1=cos(800*pi*t1);
subplot(1,2,1),stem(t1,y1);
title('cos(800pi*n)');
xlabel('n');ylabel('幅值');

y2=cos(800*t1);
subplot(1,2,2),stem(t1,y2);
title('cos(800*n)');
xlabel('n');ylabel('幅值');
