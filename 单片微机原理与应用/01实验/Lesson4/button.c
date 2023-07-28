#include <STC89C5xRC.H>
#include "button.h"
unsigned char buff[4][4]=
{
	4,5,6,7,
	8,9,10,11,
	12,13,14,15,
	16,17,18,19,
};
unsigned char C;
unsigned char R;
unsigned char key_s;
unsigned char key_v;
void button_pad()
{
	P1=0x0f; //0000 1111; 0000 1110 ;1111 0010 &0000 1111
	if(~P1&0x0f)
	{
		if(key_s<255)
		{key_s++;}
		
		if(P13==0)
			C=0;
		if(P12==0)
			C=1;
		if(P11==0)
			C=2;
		if(P10==0)
			C=3;
		
		P1=0xf0;//1111 0000
		if(P14==0)
			R=0;
		if(P15==0)
			R=1;
		if(P16==0)
			R=2;
		if(P17==0)
			R=3;
		
		key_v=buff[3-C][3-R];
	}
	else
	{
		key_s=0;
		key_v=0;
	}
}