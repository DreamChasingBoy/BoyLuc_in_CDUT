I=zeros(532);
I(166:366,241:291)=1;
J=imrotate(I,-45);
figure (1);
imshow(J);
G=fft2(J); 
V=log10(1+abs(G));
figure (2);
imshow(V);