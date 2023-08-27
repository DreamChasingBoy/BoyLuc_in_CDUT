clc;
clear;
n=linspace(1,10,10);
fn=ones(1,10);
hn=fn;
yn=conv(fn,hn);
stem(yn);
title('y(n)')