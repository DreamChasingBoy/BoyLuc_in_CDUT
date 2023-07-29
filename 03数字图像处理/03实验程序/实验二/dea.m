I=zeros(532);
for i=166:366
    for j=241:291
        I(i,j)=1;
    end
end
J=mat2gray(I);
K=im2bw(J,0.5);
figure (1);
imshow(K);
G=fft2(J); 
G1=log(abs(G));
figure (2)
imshow(G1);
G=fftshift(G);
V=log10(1+abs(G));
figure (2);
imshow(V);



