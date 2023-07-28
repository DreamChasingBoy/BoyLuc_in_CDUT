clc;
clear;
A=[1	0	0
0	1	0
0	0	1
1	-1	0
1	0	-1
0	1	-1
];
Y=[10.013;10.010;10.002;0.004;0.008;0.006];
C=inv((A')*A);
M=C*A'*Y;
v=zeros(1,6);
for i=1:6
    v(i)=Y(i)-(A(i,1)*M(1)+A(i,2)*M(2)+A(i,3)*M(3));
end
sum=0;
for j=1:6
    sum=v(j)^2+sum;
end
xigema=(sum/(6-3))^0.5;
xigema1=xigema*sqrt(C(1,1));
xigema2=xigema*sqrt(C(2,2));
xigema3=xigema*sqrt(C(3,3));