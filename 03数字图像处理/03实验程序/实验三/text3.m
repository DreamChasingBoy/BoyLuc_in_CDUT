RGB=imread("头像.jpg");
GR=rgb2gray(RGB);
GR=im2double(GR);
GR=mat2gray(GR);
%高斯噪声
GR1=imnoise(GR,'gaussian',0,0.02);
figure (1);
imshow(GR1);
%邻域平均法
GR11=filter2(fspecial('average',3),GR1);
figure (2);
imshow(GR11);
%中值滤波法
GR12=medfilt2(GR1);
figure (3);
imshow(GR12);
%高斯滤波
gr13=fspecial('gaussian',4,0.3);
GR13=filter2(gr13,GR1,'same');
figure (4);
imshow(GR13);
%sobel滤波
gr14=fspecial('sobel');
GR14=filter2(gr14,GR1,'same');
figure (5);
imshow(GR14);
%laplacian滤波
gr15=fspecial('laplacian',0.5);
GR15=filter2(gr15,GR1,'same');
figure (6);
imshow(GR15);



