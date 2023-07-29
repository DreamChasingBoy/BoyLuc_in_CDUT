RGB=imread('头像.jpg');
figure (1);
imshow(RGB);
I=rgb2gray(RGB);
figure (2);
imshow(I);
R=grayslice(I,128);
figure (3);
imshow(R);
info=imfinfo('头像.jpg');
S1=imtranslate(I,[50, 0],'OutputView','full');
figure (4)
imshow(S1);
[sx,sy]=size(I);
sx=sx.*1.5;
sy=sy.*2.5;
S2=imresize(I,[sx sy]);
figure (5)
imshow(S2);
S3=imrotate(I,-45,'nearest','loose');
figure (6)
imshow(S3);
title('最近邻差法旋转');
S4=imrotate(I,-45,'bilinear','loose');
figure (7)
imshow(S4);
title('双线性差值法旋转');

[ROW,COL,DIM] = size(I);
Ih = uint8(zeros(ROW,COL,DIM));
for i =1:ROW
    for j=1:COL
        for k=1:DIM
        x = i;
        y = COL-j+1;
        z = k;
        Ih(x,y,z) =I(i,j,k);
        end
    end
end
figure (8)
imshow(Ih);
title('水平');

S8=I';
figure (9)
imshow(S8);
title('转置');

