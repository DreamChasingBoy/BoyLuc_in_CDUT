RGB=imread("头像.jpg");
GR=rgb2gray(RGB);
GR=im2double(GR);
GR=mat2gray(GR);
[M,N]=size(GR);
%均匀噪声
a=0;
b=0.08;
A=0;
B=2;
GR50=a+b*unifrnd(A,B,[M,N]);
GR5=GR+GR50;
figure (1);
imshow(GR5);
%邻域平均法
GR51=filter2(fspecial('average',3),GR5);
figure (2);
imshow(GR51);
%中值滤波法
GR52=medfilt2(GR5);
figure (3);
imshow(GR52);
%高斯滤波
gr53=fspecial('gaussian',4,0.3);
GR53=filter2(gr53,GR5,'same');
figure (4);
imshow(GR53);
%sobel滤波
gr54=fspecial('sobel');
GR54=filter2(gr54,GR5,'same');
figure (5);
imshow(GR54);
%laplacian滤波
gr55=fspecial('laplacian',0.5);
GR55=filter2(gr55,GR5,'same');
figure (6);
imshow(GR55);
