#include <STC89C5xRC.H>
#include "SMG.h"
unsigned int t10ms=0;
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
	t10ms++;
}
unsigned char status=0;
void main()
{
	Timer0Init();
	while(1)
	{
		if(t10ms>=100)
		{
			t10ms=0;
			
			if(mo1[3]>=16)
			{
				status=1;
			}
			if(mo1[3]<=8)
			{
				status=0;
			}
			if(status==0)
				mo1[3]++;
			else
				mo1[3]--;
		}
	}
}