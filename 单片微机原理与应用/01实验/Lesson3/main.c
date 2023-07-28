#include <STC89C5xRC.H>
#include "SMG.h"
unsigned int t10ms=0;
void Timer0Init(void)		//10����@12.000MHz
{
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x20;		//���ö�ʱ��ֵ
	TH0 = 0xD1;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
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