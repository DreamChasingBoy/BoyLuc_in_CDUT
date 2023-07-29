t=50;
%向左
I1=zeros(532);
I1(166:366,241-t:291-t)=1;
figure (1);
imshow(I1);
G1=fft2(I1); 
V1=log10(1+abs(G1));
figure (2);
imshow(V1);
%向右
I2=zeros(532);
I2(166:366,241+t:291+t)=1;
figure (3);
imshow(I2);
G2=fft2(I2); 
V2=log10(1+abs(G2));
figure (4);
imshow(V2);
%向下
I3=zeros(532);
I3(166+t:366+t,241:291)=1;
figure (5);
imshow(I3);
G3=fft2(I3); 
V3=log10(1+abs(G3));
figure (6);
imshow(V3);
%向上
I4=zeros(532);
I4(166-t:366-t,241:291)=1;
figure (7);
imshow(I4);
G4=fft2(I4); 
V4=log10(1+abs(G4));
figure (8);
imshow(V4);
