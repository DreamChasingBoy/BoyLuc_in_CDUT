RGB=imread("头像.jpg");
GR=rgb2gray(RGB);
GR=im2double(GR);
GR=mat2gray(GR);
%脉冲噪声
GR6=imnoise(GR,'salt & pepper',0.02);
figure (1);
imshow(GR6);
%邻域平均法
GR61=filter2(fspecial('average',3),GR6);
figure (2);
imshow(GR61);
%中值滤波法
GR62=medfilt2(GR6);
figure (3);
imshow(GR62);
%高斯滤波
gr63=fspecial('gaussian',4,0.3);
GR63=filter2(gr63,GR6,'same');
figure (4);
imshow(GR63);
%sobel滤波
gr64=fspecial('sobel');
GR64=filter2(gr64,GR6,'same');
figure (5);
imshow(GR64);
%laplacian滤波
gr65=fspecial('laplacian',0.5);
GR65=filter2(gr65,GR6,'same');
figure (6);
imshow(GR65);