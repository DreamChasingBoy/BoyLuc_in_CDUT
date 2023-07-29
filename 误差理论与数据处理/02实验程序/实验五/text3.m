clc;
clear;
x=[12	13	14	15	16	18	20	22	24	26];
y=[52.0	55.0	58.0	61.0	65.0	70.0	75.0	80.0	85.0	91.0];
plot(x,y);
X=[ones(size(x')), x'];
[b,bint,r,rint,stats]= regress(y',X,0.05);
