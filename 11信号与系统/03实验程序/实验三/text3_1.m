syms t;
a=2;
f=exp(-a*abs(t));
F=fourier(f);
ezplot(F);