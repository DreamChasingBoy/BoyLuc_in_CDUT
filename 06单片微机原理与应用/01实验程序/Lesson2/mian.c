#include <reg52.h>
#include <intrins.h>
unsigned char code LedCode[]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09,0x11,0xc1,0x63,0x85,0x61,0x71};
unsigned char str=8;
unsigned char t=0;
void Timer0init()
{
	SCON = 0x00;
	TMOD=0x01;
	TH0=0x3c;
	TL0=0xb0;
	ET0=1;
	EA=1;
	TR0=1;
}
void Display()
{
	SBUF=LedCode[str];
	while(!TI);
	TI=0;
	SBUF=LedCode[2];
	while(!TI);
	TI=0;
}
void main()
{
	Timer0init();
	Display();
	while(1);
}
void timer0() interrupt 1
{
	if(++t>=10)
	{
		t=0;
		if(++str>9)
			str=0;
		Display();
	}
}