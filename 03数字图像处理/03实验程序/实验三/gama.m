RGB=imread("头像.jpg");
GR=rgb2gray(RGB);
GR=im2double(GR);
GR=mat2gray(GR);
[M,N]=size(GR);
%伽马噪声
a=0;
b=0.08;
A=1;
B=2;
GR30=a+b*gamrnd(A,B,[M,N]);
GR3=GR+GR30;
figure (1);
imshow(GR3);
%邻域平均法
GR31=filter2(fspecial('average',3),GR3);
figure (2);
imshow(GR31);
%中值滤波法
GR32=medfilt2(GR3);
figure (3);
imshow(GR32);
%高斯滤波
gr33=fspecial('gaussian',4,0.3);
GR33=filter2(gr33,GR3,'same');
figure (4);
imshow(GR33);
%sobel滤波
gr34=fspecial('sobel');
GR34=filter2(gr34,GR3,'same');
figure (5);
imshow(GR34);
%laplacian滤波
gr35=fspecial('laplacian',0.5);
GR35=filter2(gr35,GR3,'same');
figure (6);
imshow(GR35);