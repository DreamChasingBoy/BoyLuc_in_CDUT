I=zeros(532);
I(166-100:366+100,241:291)=1;
figure (1);
imshow(I);
G=fft2(I); 
V=log10(1+abs(G));
figure (2);
imshow(V);

% I1=zeros(532);
% I1(166:366,241-25:291+25)=1;
% figure (3);
% imshow(I1);
% G1=fft2(I1); 
% V1=log10(1+abs(G1));
% figure (4);
% imshow(V1);