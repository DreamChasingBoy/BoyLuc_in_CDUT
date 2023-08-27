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

int InitStack(SqStack &S)   //初始化
{
	S.base=new int[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}

int Push(SqStack &S,int e) //将元素e压入栈
{
	if(S.top-S.base==S.stacksize)
		return ERROR;
	*S.top++=e;
	return OK;
}

int Pop(SqStack &S,int &e)  //将元素e拿出栈
{
	if(S.top==S.base)
		return ERROR;
	e=*--S.top;
	return OK;
}

int main()
{
	cout << "欢迎来到南南的进制转换！" << endl;
	SqStack lby;
	InitStack(lby);
	int c[10];//输出
	int i,j;
	int b[10];//要被转换的十进制数
	cout<<"请输入要转换的个数（最多十个）"<<endl;
	cin>>j;
	for(i=0;i<j;i++)
	{
		cout<<"请输入第"<<i+1<<"个数";
		cin>>b[i];
	}
	for(i=0;i<=j;i++)
	{
		while(b[i]>0)
		{
			Push(lby,b[i]%8); //将b%8扔到栈里
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