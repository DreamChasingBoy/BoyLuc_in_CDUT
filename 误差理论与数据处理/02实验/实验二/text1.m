e=[13,4,0.1,0.5];
b=[13.8,4.8,3];
E=[0,0,0,0];
B=[0,0,0];
for i=1:4
    E(i)=(e(i)/2)^2;
end
for i=1:3
    B(i)=(b(i)/2)^2;
end
EE=sum(E);
BB=sum(B);
S=2*sqrt(EE+BB);