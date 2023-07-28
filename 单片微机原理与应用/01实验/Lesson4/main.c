#include <STC89C5xRC.H>
#include "SMG.h"
#include "button.h"
unsigned int t10ms=0;
unsigned char i=0;
unsigned char statue=0;
bit control=0;
void Timer0Init(void)		//10毫秒@12.000MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x20;		//设置定时初值
	TH0 = 0xD1;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
}
void timer0() interrupt 1
{
	SMG_dis();
	button_pad();
	t10ms++;
}
unsigned char status=0;
void main()
{
	Timer0Init();
	while(1)
	{
		if(control==1)
		{
			if(t10ms>100)
			{
				t10ms=0;
				mo2[3]++;
			}
		}
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
			control=1;
		}
		if(key_v==4&&key_s==2)//stop
		{
			control=0;
		}
		if(P1==0x0f)
		{
			statue=0;
		}
	}
}