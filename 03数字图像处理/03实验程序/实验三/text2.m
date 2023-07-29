RGB=imread("另一个头像.jpg");
GR=rgb2gray(RGB);
CS=GR;
figure (1);
imshow(GR);
%2.a 直方图
figure (2);
imhist(GR);
%2.b 均衡化
GR=im2double(GR);
GR=histeq(GR);
figure (3);
imshow(GR);
%2.c 规定化
a=0:1:255;
a=a/255;
s=log2(a+1);
S=sum(s);
h=s/S;
GR=histeq(GR,h);
figure (4);
imshow(GR);