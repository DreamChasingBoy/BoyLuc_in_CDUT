%1.a 归一化处理
RGB=imread("头像.jpg");
GR=rgb2gray(RGB);
GR=double(GR);
for i=1:360
    for j=1:360
        GR(i,j)=GR(i,j)/double(255);
    end
end
I=mat2gray(GR);
figure (1);
imshow(I);
%1.b 范围显示
for i=1:360
    for j=1:360
        if I(i,j)<=0.2||I(i,j)>=0.8
            I(i,j)=1;
        end
    end
end
figure (2);
imshow(I);
%1.c 全域线性变换
for i=1:360
    for j=1:360
       I(i,j)=(1/0.6)*(I(i,j)-0.2);
    end
end
figure (3);
imshow(I);
%1.d 分段线性变换
I1=zeros(360);
for i=1:360
    for j=1:360
        if I(i,j)<=0.2
            I1(i,j)=2*I(i,j);
        elseif I(i,j)>=0.2||I(i,j)<=0.8
            I1(i,j)=3*(I(i,j)-0.2)+0.4;
        else
            I1(i,j)=2*(I(i,j)-0.8)+0.6;
        end
    end
end
figure (4);
imshow(I1);
%1.e 非线性灰度转换
I2=zeros(360);
for i=1:360
    for j=1:360
       I2(i,j)=log2(I(i,j)+1);
    end
end
figure (5);
imshow(I2);