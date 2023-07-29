 I=imread("头像.jpg");
I=rgb2gray(I);
I=double(I)/255;
[M1,M2]=size(I);
K1=zeros(1,M2);
for i=1:M2
    for j=1:M1
    K1(1,i)=K1(1,i)+I(j,i);
    end
end
T=dctmtx(8);
T1=fft2(I);
B=blkproc(I,[8 8],'P1*x*P2',T,T');
M=zeros(8,8);
for i=1:4
    for j=1:8
    M(i,j)=1;
    end
end
B2=blkproc(B,[8 8],'P1.*x',M);
I2=blkproc(B2,[8 8],'P1*x*P2',T',T);
subplot(321);imshow(I2);title('余弦变换2:1');
K2=zeros(1,M2);
for i=1:M2
    for j=1:M1
    K2(1,i)=K2(1,i)+I2(j,i);
    end
end
s1=std((K1-K2),1);
[k,p]=size(I);
t_fft=blkproc(I,[8 8],'fft2(x)');
t_block=im2col(t_fft,[8 8],'distinct');
[t_change,ix]=sort(t_block);
[m,n]=size(t_block);
cr=0.5; 
nums=64*cr;
for i=1:n
 t_block(ix(1:nums),i)=0;
end
t_rchange=col2im(t_block,[8 8],[k p],'distinct');
t_ifft=blkproc(t_rchange,[8 8],'ifft2(x)');
subplot(322);imshow(t_ifft);title('傅里叶2:1');
K2=zeros(1,M2);
for i=1:M2
    for j=1:M1
    K2(1,i)=K2(1,i)+t_ifft(j,i);
    end
end
  s2=std((K1-K2),1) 
for i=1:4
    for j=1:4
    M(i,j)=1;
    end
end
B2=blkproc(B,[8 8],'P1.*x',M);
I2=blkproc(B2,[8 8],'P1*x*P2',T',T);
subplot(323);imshow(I2);title('4:1');
K2=zeros(1,M2);
for i=1:M2
    for j=1:M1
    K2(1,i)=K2(1,i)+I2(j,i);
    end
end
  s3=std((K1-K2),1) 
[k,p]=size(I);
t_fft=blkproc(I,[8 8],'fft2(x)');
t_block=im2col(t_fft,[8 8],'distinct');
[t_change,ix]=sort(t_block);
[m,n]=size(t_block);
cr=0.25; 
nums=64*cr;
for i=1:n
 t_block(ix(1:nums),i)=0;
end
t_rchange=col2im(t_block,[8 8],[k p],'distinct');
t_ifft=blkproc(t_rchange,[8 8],'ifft2(x)');
subplot(324);imshow(t_ifft);title('4:1');
K2=zeros(1,M2);
for i=1:M2
    for j=1:M1
    K2(1,i)=K2(1,i)+t_ifft(j,i);
    end
end
  s4=std((K1-K2),1) 
for i=1:2
    for j=1:4
    M(i,j)=1;
    end
end
B2=blkproc(B,[8 8],'P1.*x',M);
I2=blkproc(B2,[8 8],'P1*x*P2',T',T);
subplot(325);imshow(I2);title('8:1');
K2=zeros(1,M2);
for i=1:M2
    for j=1:M1
    K2(1,i)=K2(1,i)+I2(j,i);
    end
end
 s5=std((K1-K2),1)
[k,p]=size(I);
t_fft=blkproc(I,[8 8]);