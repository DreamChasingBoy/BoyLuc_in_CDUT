b=[1];
a=[1,-6];
[h,w]=freqz(b,a);

subplot(2,2,1)
plot(w/pi,real(h));grid
title('实部')
xlabel('\omega/\pi');ylabel('幅度')

subplot(2,2,2)
plot(w/pi,imag(h));grid
title('虚部')
xlabel('\omega/\pi');ylabel('幅度')

subplot(2,2,3)
plot(w/pi,abs(h));grid
title('幅度谱')
xlabel('\omega/\pi');ylabel('幅度')

subplot(2,2,4)
plot(w/pi,angle(h));grid
title('相位谱')
xlabel('\omega/\pi');ylabel('相位（rad）')