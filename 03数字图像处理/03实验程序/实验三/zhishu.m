RGB=imread("头像.jpg");
GR=rgb2gray(RGB);
GR=im2double(GR);
GR=mat2gray(GR);
[M,N]=size(GR);
%指数噪声
a=0;
b=0.08;
mu=2;
GR40=a+b*exprnd(mu,[M,N]);
GR4=GR+GR40;
figure (1);
imshow(GR4);
%邻域平均法
GR41=filter2(fspecial('average',3),GR4);
figure (2);
imshow(GR41);
%中值滤波法
GR42=medfilt2(GR4);
figure (3);
imshow(GR42);
%高斯滤波
gr43=fspecial('gaussian',4,0.3);
GR43=filter2(gr43,GR4,'same');
figure (4);
imshow(GR43);
%sobel滤波
gr44=fspecial('sobel');
GR44=filter2(gr44,GR4,'same');
figure (5);
imshow(GR44);
%laplacian滤波
gr45=fspecial('laplacian',0.5);
GR45=filter2(gr45,GR4,'same');
figure (6);
imshow(GR45);
