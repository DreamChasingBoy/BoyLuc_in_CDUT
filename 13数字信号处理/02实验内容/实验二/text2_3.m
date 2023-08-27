clc;
clear;
X=[1 2 -1 3];
XE_8=fft(X,8)
XE_16=fft(X,16)
Xi_8=ifft(XE_8)
Xi_16=ifft(XE_16)