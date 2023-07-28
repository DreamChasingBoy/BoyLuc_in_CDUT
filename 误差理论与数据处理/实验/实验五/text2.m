clc;
clear;
x=[150 150 150	200 200 200	250 250 250	 300 300 300 ];
y=[77.4	76.7	78.2	84.1	84.5	83.7	88.9	89.2	89.7	94.8	94.7	95.9];
plot(x,y);
X=[ones(size(x')), x'];
[b,bint,r,rint,stats]= regress(y',X,0.05);
xba=mean(x);
yba=mean(y);
lxx=0;lyy=0;lxy=0;
for i=1:9
    lxx=lxx+(x(i)-xba)^2;
    lyy=lyy+(y(i)-yba)^2;
    lxy=lxy+(x(i)-xba)*(y(i)-yba);
end
U=b(1)*lxy;
Q=lyy-b(1)*lxy;
xigema=sqrt(Q/7);
F=U/(Q/(9-2));