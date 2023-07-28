clc,clear;
x1=[12	13	14	15	16	18	20	22	24	26]';
y=[52.0	55.0	58.0	61.0	65.0	70.0	75.0	80.0	85.0	91.0]';
figure(1)
plot(x1,y,'*')%画数据散点图
hold on
x=[ones(10,1),x1];
[b,bint,r,rint,stats]=regress(y,x);
x2=[50:70];
plot(x2,b(1)+b(2)*x2)%画拟合图
figure(2)
rcoplot(r,rint)%画残差图
b,bint,stats
