I=imread("头像.jpg");
C=rgb2gray(I);
B=dct2(C);
figure (1);
B(abs(B)<5)=0;
K=idct2(B);
imshow(K,[]);
imwrite(K,'3（1）.png');
a=mean(K(:));
M=zeros(360,360);
for i=1:360
    for j=1:360
        M(i,j)=(K(i,j)-C(i,j)).^2;
    end
end
S=(mean(M(:))).^0.5;
