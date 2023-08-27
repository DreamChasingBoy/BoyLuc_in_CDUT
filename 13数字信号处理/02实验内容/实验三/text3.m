clc;
clear;
x=[-2+1i 4+2i 3 4];
XE=fft(x,4)
Xi=ifft(XE)