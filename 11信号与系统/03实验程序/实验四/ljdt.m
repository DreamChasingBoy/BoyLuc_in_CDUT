function [p,z]=ljdt(D,N)
p=roots(D);                  %求系统的极点
z=roots(N) ;                 %求系统的零点
p=p';                       %将极点列向量转置为行向量
z=z';       
x=max(abs([p z]));          %用来确定坐标轴的范围
x=x+0.1;
y=x;
hold on                     %重叠绘图
axis([-x x -y y]);          %确定坐标轴显示范围
plot([-x x],[0 0])          %画出横坐标
plot([0 0],[-y y])          %画出纵坐标
plot(real(p),imag(p),'x')   %画出极点
plot(real(z),imag(z),'O')   %画出零点
title('连续系统的零极点图') %加标题
text(0.2,x-0.2,'虚轴')      %加文本标注
text(y-0.2,0.2,'实轴')
end