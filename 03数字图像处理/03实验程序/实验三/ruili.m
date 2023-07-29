RGB=imread("头像.jpg");
GR=rgb2gray(RGB);
GR=im2double(GR);
GR=mat2gray(GR);
[M,N]=size(GR);
%瑞利噪声
a=0;
b=0.08;
B=1;
GR20=a+b*raylrnd(B,M,N);
GR2=GR+GR20;
figure (1);
imshow(GR2);
%邻域平均法
GR21=filter2(fspecial('average',3),GR2);
figure (2);
imshow(GR21);
%中值滤波法
GR22=medfilt2(GR2);
figure (3);
imshow(GR22);
%高斯滤波
gr23=fspecial('gaussian',4,0.3);
GR23=filter2(gr23,GR2,'same');
figure (4);
imshow(GR23);
%sobel滤波
gr24=fspecial('sobel');
GR24=filter2(gr24,GR2,'same');
figure (5);
imshow(GR24);
%laplacian滤波
gr25=fspecial('laplacian',0.5);
GR25=filter2(gr25,GR2,'same');
figure (6);
imshow(GR25);