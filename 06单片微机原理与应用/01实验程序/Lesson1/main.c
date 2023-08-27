#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int 
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	P2=0xff;//1111 1111
	while(1)
	{
		uchar i=1;
		uchar k=0;
		for(k=0;k<8;k++)
		{
			P2=~(i<<k);
			Delay100ms();
		}
	}
}