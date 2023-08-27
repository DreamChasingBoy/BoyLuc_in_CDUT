   % Q learning
   % Two input: R and gamma
   % immediate reward matrix; 
   % row(depart) and column(target) = states; -Inf = no door between room
   % The goal room is F, so the doors that lead immediately to the goal have instant reward of 100 
   %   A   B   C   D   E   F
   % A                 1  
   % B             1       1
   % C             1
   % D     1   1       1
   % E 1           1       1
   % F     1           1   1


function qlearning
clear all;close all; clc;
    R=[ -inf,   -inf,   -inf,   -inf,    0,      -inf;
        -inf,   -inf,   -inf,   0,      -inf,   100;
        -inf,   -inf,   -inf,   0,      -inf,   -inf;
        -inf,   0,      0,      -inf,   0,      -inf;
        0,      -inf,   -inf,   0,      -inf,   100;
        -inf,   0,      -inf,   -inf,   0,      100];
labels=['A' 'B' 'C' 'D' 'E' 'F'];
gamma=0.50;            % 学习参数
nEpisodes=5000;
[A episode]=ReinforcementLearning(R,nEpisodes,gamma);
adj=(A>0);

%# 绘制邻接矩阵
subplot(121), spy(adj)
title('Adjacency matrix');
%# 在网格上绘制连接点
X=[1 2 3.5 2 1 1.5]';
Y=[2 2 1.5 1 1 1.5]';
[xx yy] = gplot(adj, [X Y]);
subplot(122), plot(xx, yy, 'ks-', 'MarkerFaceColor','r')
title('Graph');
axis([0.5 4 0.5 2.5])
dx=0.1;dy=0.1;

for j=1:length(labels)
    text(X(j)+dx,Y(j)+dy,labels(j))
end


%% Find path
initial=3;  %C
goal=6;     %F

foundPath=false;
current=initial;

index=1;
pathPlan(index)=current;
while(not(foundPath))
    [val current]=max(A(current,:));
    index=index+1;
    pathPlan(index)=current;
    if(current==goal)
        foundPath=true;
    end
end
disp('Path:')
for j=1:length(pathPlan)
   disp(sprintf('%c',labels(pathPlan(j))))
end
end

 function y=RandomPermutation(A)
 % 返回矩阵A的随机排列
 %不像randperm(n)只给出整数1:n的排列
   [r,c]=size(A);
   b=reshape(A,r*c,1);       % 转换为列向量
   x=randperm(r*c);          % 对相似数组进行整数排列作为键
   w=[b,x'];                 % 结合矩阵和键
   d=sortrows(w,2);          % 根据键排序
   y=reshape(d(:,1),r,c);    % 返回矩阵
 end
 
 function [q episode]=ReinforcementLearning(R, nepisodes,gamma)
format short
format compact
    q=zeros(size(R));      % 将Q初始化为零
    q1=ones(size(R))*inf;  % 初始化之前的Q为大数字
    count=0;               % 计数

    for episode=0:nepisodes
       % 随机初始状态
       y=randperm(size(R,1));
       state=y(1);
       
       % 从此状态中选择任何操作
       x=find(R(state,:)>=0);        % 找出这个状态的可能动作
       if size(x,1)>0, 
          x1=RandomPermutation(x);   % 随机化可能的行动
          x1=x1(1);                  % 选择一个动作   
       end

       qMax=max(q,[],2);
       q(state,x1)= R(state,x1)+gamma*qMax(x1);   % 获得所有动作的最大值
       state=x1;
       
       % break if convergence: small deviation on q for 1000 consecutive
       %间断收敛:连续1000次在q上有小偏差
       if sum(sum(abs(q1-q)))<0.0001 & sum(sum(q >0))
          if count>1000,
             episode        % 报告最后的episode
             break          % for
          else
             count=count+1; % 如果q偏差较小，则设置计数器
          end
       else
          q1=q;
          count=0; % 当q与前一个q的偏差较大时，重置计数器
       end
    end 

    %正常的q
    g=max(max(q));
    if g>0, 
       q=100*q/g;
    end
end
      

