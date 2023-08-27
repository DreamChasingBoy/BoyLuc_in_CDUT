#include<iostream>
#include<stdlib.h>
#include<string.h>
#define  ERROR   0
#define  OK      1
#define  OVERFLOW -2
#define  MAXSIZE 100
using namespace std;
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)   //��ʼ��
{
	S.base=new int[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}

int Push(SqStack &S,int e) //��Ԫ��eѹ��ջ
{
	if(S.top-S.base==S.stacksize)
		return ERROR;
	*S.top++=e;
	return OK;
}

int Pop(SqStack &S,int &e)  //��Ԫ��e�ó�ջ
{
	if(S.top==S.base)
		return ERROR;
	e=*--S.top;
	return OK;
}

int main()
{
	cout << "��ӭ�������ϵĽ���ת����" << endl;
	SqStack lby;
	InitStack(lby);
	int c[10];//���
	int i,j;
	int b[10];//Ҫ��ת����ʮ������
	cout<<"������Ҫת���ĸ��������ʮ����"<<endl;
	cin>>j;
	for(i=0;i<j;i++)
	{
		cout<<"�������"<<i+1<<"����";
		cin>>b[i];
	}
	for(i=0;i<=j;i++)
	{
		while(b[i]>0)
		{
			Push(lby,b[i]%8); //��b%8�ӵ�ջ��
			b[i]=b[i]/8;
		}
		while(lby.top!=lby.base)
		{
			Pop(lby,c[i]);
			cout<<c[i];
		}
		cout<<endl;
	}
	return 0;
}