#include<iostream>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
using namespace std;
typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;
int InitQueue(SqQueue &Q)
{
	Q.base=new int[MAXSIZE];
	if(!Q.base)
		exit (OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue Q)//求队列长度
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int EnQueue(SqQueue &Q,int e)//入队（在队尾插入）
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
int DeQueue(SqQueue &Q,int &e)//出队（将队头元素删除）
{
	if(Q.front==Q.rear)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
void now(SqQueue &Q,int k)//输出当前遍历
{
    int i=0;
    if( i==k )
    {
        cout<<"队空"<<endl;
    }
	else
    {
		cout<<"队伍的顺序如下:"<<endl;
		while(i<k)
		{
			cout<< Q.base[Q.front+i]<<endl;
			i++;
		}
	}
}
int main()
{
	cout << "欢迎来到南南的银行排队系统！" << endl;
	SqQueue lby;
	int temp;//输入状态
	int num;
	int j;
	int e;
	int a=0;//队伍长度
	int i=0;//初始化的人数
	InitQueue(lby);
	while(1)
	{
		cout<<"请选择操作"<<endl;
		cout<<"1.用户进入排队系统"<<endl;
		cout<<"2.用户离开排队系统"<<endl;
		cout<<"3.查询当前客户前面还有几人"<<endl;
		cout<<"4.查询截至目前总共办理多少客户"<<endl;
		cin>>temp;
		switch(temp)
		{
			case 1:
				{
					cout<<"请输入进入用户的号码";
					cin>>num;
					EnQueue(lby,num);
					a++;
					now(lby,a);
					break;
				}
			case 2:
				{
					DeQueue(lby,num);
					a--;
					now(lby,a);
					break;
				}
			case 3:
				{
					cout<<"请输入你要查询的用户编号";
					cin>>e;
					for(i=0;lby.base[lby.front+i]!=e;i++);
					cout<<"该用户前面的人数为：";
					cout<<i<<endl;
					break;
				}
			case 4:
				{

					cout<<"截至目前总共办理客户为："<<QueueLength(lby)<<endl;
					break;
				}
			default:
				break;
		}
	}
	return 0;
}

