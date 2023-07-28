#include <STC89C5xRC.H>
#include <SMG.h>
#include <button.h>
sbit din=P3^0;
sbit sclk=P3^2;
sbit cs=P3^1;
sbit dout=P3^3;
unsigned int t10ms=0;
#define Vref 5
float v0=0;
float count_DAC(unsigned char u);
unsigned char i=0;
unsigned char statue=0;
bit control=0;
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
float count()
{
	float sum=0;
	float xianshi=0;
	sum=mo2[1]*100+mo2[2]*10+mo2[3];
	xianshi=(sum/4.096)*1024;
	return xianshi;
}
void Write5615(unsigned int wdata)
{
	unsigned char i;
	cs=0;
	wdata<<=2;
	for(i=0;i<12;i++)
	{
		sclk=0;
		din=(wdata&0x0800)?1:0;
		sclk=1;
		wdata<<=1;
	}
	cs=1;
}
void timer0() interrupt 1
{
	SMG_dis();
	t10ms++;
	button();
}
unsigned int volt=0;
void main()
{
	Timer0Init();
	while(1)
	{
		
		
		if(key_v==7&&key_s==2)//0
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=0;
				i++;
			}
		}
		if(key_v==11&&key_s==2)//1
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=1;
				i++;
			}
		}
		if(key_v==15&&key_s==2)//2
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=2;
				i++;
			}
		}
		if(key_v==19&&key_s==2)//3
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=3;
				i++;
			}
		}
		if(key_v==6&&key_s==2)//4
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=4;
				i++;
			}
		}
		if(key_v==10&&key_s==2)//5
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=5;
				i++;
			}
		}
		if(key_v==14&&key_s==2)//6
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=6;
				i++;
			}
		}
		if(key_v==18&&key_s==2)//7
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=7;
				i++;
			}
		}
		if(key_v==5&&key_s==2)//8
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=8;
				i++;
			}
		}
		if(key_v==9&&key_s==2)//9
		{
			if(statue==0)
			{
				statue=1;
				mo2[i]=9;
				i++;
			}
		}
		if(key_v==13&&key_s==2)//input
		{
			SMG_cun=mo2;
		}
		if(key_v==17&&key_s==2)//start
		{
			SMG_cun=mo3;
			mo3[1]=mo2[1]+32;
			mo3[2]=mo2[2];
			mo3[3]=mo2[3];
		}
		if(key_v==4&&key_s==2)//stop
		{
			control=0;
		}
		if(P1==0x0f)
		{
			statue=0;
		}
		volt=mo2[1]*100+mo2[2]*10+mo2[3];
		Write5615(volt);
		
	}
}