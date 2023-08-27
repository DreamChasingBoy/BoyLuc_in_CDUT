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

int QueueLength(SqQueue Q)//����г���
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int EnQueue(SqQueue &Q,int e)//��ӣ��ڶ�β���룩
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
int DeQueue(SqQueue &Q,int &e)//���ӣ�����ͷԪ��ɾ����
{
	if(Q.front==Q.rear)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
void now(SqQueue &Q,int k)//�����ǰ����
{
    int i=0;
    if( i==k )
    {
        cout<<"�ӿ�"<<endl;
    }
	else
    {
		cout<<"�����˳������:"<<endl;
		while(i<k)
		{
			cout<< Q.base[Q.front+i]<<endl;
			i++;
		}
	}
}
int main()
{
	cout << "��ӭ�������ϵ������Ŷ�ϵͳ��" << endl;
	SqQueue lby;
	int temp;//����״̬
	int num;
	int j;
	int e;
	int a=0;//���鳤��
	int i=0;//��ʼ��������
	InitQueue(lby);
	while(1)
	{
		cout<<"��ѡ�����"<<endl;
		cout<<"1.�û������Ŷ�ϵͳ"<<endl;
		cout<<"2.�û��뿪�Ŷ�ϵͳ"<<endl;
		cout<<"3.��ѯ��ǰ�ͻ�ǰ�滹�м���"<<endl;
		cout<<"4.��ѯ����Ŀǰ�ܹ�������ٿͻ�"<<endl;
		cin>>temp;
		switch(temp)
		{
			case 1:
				{
					cout<<"����������û��ĺ���";
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
					cout<<"��������Ҫ��ѯ���û����";
					cin>>e;
					for(i=0;lby.base[lby.front+i]!=e;i++);
					cout<<"���û�ǰ�������Ϊ��";
					cout<<i<<endl;
					break;
				}
			case 4:
				{

					cout<<"����Ŀǰ�ܹ�����ͻ�Ϊ��"<<QueueLength(lby)<<endl;
					break;
				}
			default:
				break;
		}
	}
	return 0;
}

