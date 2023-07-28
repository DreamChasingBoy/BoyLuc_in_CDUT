clc;
clear;
Y=[-5.6;
    8.1;
    0.5];
A=[1,-3
    4,1
    2,-1];
P=[1 0 0;
   0 2 0;
   0 0 3];
C=inv(A'*P*A);
M=C*A'*P*Y;
V=zeros(1,3);
for i=1:3
    V(i)=Y(i)-(A(i,1)*M(1)+A(i,2)*M(2));
end
xigema=0;
for i=1:3
    xigema=P(i,i)*V(i)*V(i)+xigema;
end
xigema=sqrt(xigema/(3-2));
xigema1=xigema*sqrt(C(1,1));
xigema2=xigema*sqrt(C(2,2));