clear,clc;
 I1=imread("头像.jpg");
 I2=rgb2gray(I1);
 imshow(I2);
[R,C]=size(I2);
a=I2(:);%1:M*N;
P=zeros(1,256);%获取符号的概率
for i=0:255
    P(i+1)=length(find(a==i))/(R*C);
end
%调用自己写的函数
[output,p]=hufuman(I2);
%  %% 计算冗余度r
%  %计算H,在这一步要把为0的值去掉，否则永远会出错误。
 H=0;
 for i=1:256
     if p(i) ~= 0
        H=H+p(i)*log2(1/p(i));
     end
 end
 %计算平均码长
 R=0;
 for i=1:256
     R=length(strtrim(output(i,:)))*p(i)+R;
 end
 %计算冗余度
 n=1-(H/(R*log2(256)));
 fprintf('冗余度n为 %f\n',n ) 
 output;
sum(p)
%自己写的编码函数文件
function [output,p]=hufuman(input)
%input为输入图像，output为输出图像。
[R,C]=size(input);
a=input(:);%1:M*N;
p=zeros(1,256);%获取符号的概率
for i=0:255
    p(i+1)=length(find(a==i))/(R*C);
end
%编码我们可以使用自带的函数，同时也可以使用自己写的函数
n=length(p); 
p=sort(p);
q=p;
m=zeros(n-1,n);%255*256
for i=1:n-1
    [q,e]=sort(q); 
    m(i,:)=[e(1:n-i+1),zeros(1,i-1)]; %由数组l 构建一个矩阵，该矩阵表明概率合并时的顺序，用于后面的编码
    q=[q(1)+q(2),q(3:n),1]; 
end
 
for i=1:n-1
    c(i,1:n*n)=blanks(n*n); %c 矩阵用于进行huffman 编码
end
    c(n-1,n)='1'; %由于a 矩阵的第n-1 行的前两个元素为进行huffman 编码加和运算时所得的最后两个概率(在本例中为0.02、0.08)，因此其值为0或1
    c(n-1,2*n)='0'; 
for i=2:n-1
    c(n-i,1:n-1)=c(n-i+1,n*(find(m(n-i+1,:)==1))-(n-2):n*(find(m(n-i+1,:)==1))); %矩阵c 的第n-i 的第一个元素的n-1 的字符赋值为对应于a 矩阵中第n-i+1 行中值为1 的位置在c 矩阵中的编码值
    c(n-i,n)='0'; 
    c(n-i,n+1:2*n-1)=c(n-i,1:n-1); %矩阵c 的第n-i 的第二个元素的n-1 的字符与第n-i 行的第一个元素的前n-1 个符号相同，因为其根节点相同
    c(n-i,2*n)='1'; 
    for j=1:i-1
         c(n-i,(j+1)*n+1:(j+2)*n)=c(n-i+1,n*(find(m(n-i+1,:)==j+1)-1)+1:n*find(m(n-i+1,:)==j+1));
            %矩阵c 中第n-i 行第j+1 列的值等于对应于a 矩阵中第n-i+1 行中值为j+1 的前面一个元素的位置在c 矩阵中的编码值
    end
end 
for i=1:n
    output(i,1:n)=c(1,n*(find(m(1,:)==i)-1)+1:find(m(1,:)==i)*n); 
    len(i)=length(find(abs(output(i,:))~=32)); 
end
output=strtrim(output);
end