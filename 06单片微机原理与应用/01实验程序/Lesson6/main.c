#include <STC89C5xRC.H>
#include <SMG.h>
#include <intrins.h>
sbit adcint=P3^5;
sbit adcrd=P3^3;
sbit adcwr=P3^4;
void Timer0Init(void)		//10ms
{
	AUXR |= 0x80;		
	TMOD &= 0xF0;		
	TL0 = 0x20;		
	TH0 = 0xD1;		
	TF0 = 0;		
	TR0 = 1;		
	ET0=1;
	EA=1;
}
void timer0() interrupt 1
{
	SMG_dis();
}
unsigned char read0804()
{
	unsigned char adddata;
	adcrd=1;
	adcwr=1;
	adcint=1;
	P1=0xff;
	adcwr=0;
	adcwr=1;
	while(adcint==1);
	adcrd=0;
	_nop_();
	_nop_();
	adddata=P1;
	adcwr=1;
	return adddata;
}
unsigned int counting(unsigned char a)
{
	float j;
	j=a*3.1372549019607+0.5;
	return (unsigned int)j;
}
void main()
{
	unsigned char i;
	unsigned int count;
	Timer0Init();
	while(1)
	{
		count=counting(read0804());
		mo2[3]=count%10;
		mo2[2]=count/10%10;
		mo2[1]=count/100+32;
	}
}