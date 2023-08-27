f=linspace(1,9,9);
n=linspace(1,9,9);
subplot(3,1,1),stem(n,f);
title('f(n)');
nn=-1-n;
subplot(3,1,2),stem(nn,f);
title('f(-1-n)');
flag=1;
for i=1:9
    if mod((n(i)-1),3)==0
        x(flag)=(n(i)-1)/3;
        flag=flag+1;
    end
end
nnn=3*x+1;
subplot(3,1,3),stem(x,nnn);
title('f(3n+1)');