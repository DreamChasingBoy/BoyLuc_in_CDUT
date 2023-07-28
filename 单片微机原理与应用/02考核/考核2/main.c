#include <STC89C5xRC.H>
#include <SMG.h>
#include <intrins.h>
sbit DO=P1^5;
sbit CS=P1^4;
sbit SCLK=P1^3;
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
void delay(unsigned int t)
{
	while(t--);
}	
void timer0() interrupt 1
{
	SMG_dis();
}
unsigned int counting(unsigned char a)
{
	float j;
	j=a*1.9607843137254;
	return (unsigned int)j;
}
unsigned int TLC549_AD() //TLC549处理
{
	unsigned char i;
  unsigned int data_ad=0;
	CS=1; //初始化，启动
	SCLK=0;
	DO=1;
	CS=0;
	_nop_();
	for(i=0;i<8;i++) //读取采集数据，读取的是上一次采集数据
	{
		SCLK=1;
		if(DO)data_ad|=0x01;
		SCLK=0;
		data_ad<<=1;
	}
	CS=1;
//	data_ad=data_ad*(500/256)+0.5; //0.5V进行四舍五入补偿
	return data_ad;
}
unsigned char ad549_read()
{
	unsigned int i;
	unsigned char k=0;
	DO=1;
	for(i=0;i<8;i++)
	{
		k=k<<1;
		if(DO) 
			k++;
		SCLK=1;
		SCLK=0;
		delay(10);
			
	}
	return k;
}
unsigned char ad549_export()
{
	unsigned char date;
	CS=0;
	date=ad549_read();
	CS=1;
	delay(20);
	return date;
}
void main()
{
	unsigned char i;
	unsigned int count;
	Timer0Init();
	while(1)
	{
		count=counting(ad549_export());
		mo2[3]=count%10;
		mo2[2]=count/10%10;
		mo2[1]=count/100+32;
	}
}