clc;
clear;
Y=[10.002;20.002;50.006;30.004;60.002;70.002;80.008];
A=[1	0	0
0	1	0
0	0	1
1	1	0
1	0	1
0	1	1
1	1	1
];
C=inv((A')*A);
M=C*A'*Y;
v=zeros(1,7);
for i=1:7
    v(i)=Y(i)-(A(i,1)*M(1)+A(i,2)*M(2)+A(i,3)*M(3));
end
sum=0;
for j=1:7
    sum=v(j)^2+sum;
end
xigema=(sum/(7-3))^0.5;
xigema1=xigema*sqrt(C(1,1));
xigema2=xigema*sqrt(C(2,2));
xigema3=xigema*sqrt(C(3,3));
