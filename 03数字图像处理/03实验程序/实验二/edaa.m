I=imread("头像.jpg");
U=rgb2gray(I);
figure (1);
imshow(U);
G1=fft2(U); 
G1=fftshift(G1);
V1=log10(1+abs(G1));
figure (4);
imshow(V1);