#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct//定义一个message的信息表
{
	char date[20];
	char time[20];
	char place[20];
	int temp;
	int hum;
}message;
typedef struct//定义一个顺序表
{
	message *p;
	int length;
}SqList;

//能够逐条输入信息，创建表
int InitList(SqList &L)//初始化
{
	L.p=new message[MAXSIZE];//分配存储空间
	if(!L.p)
		exit(OVERFLOW);
	L.length=0;//空表长度为0
	return OK;
}
int ListCreate(SqList &L,int j,message e)//输入信息
{
	if(j<0||j>MAXSIZE)
		return ERROR;
	if(L.length==MAXSIZE)
		return OVERFLOW;
	strcpy(L.p[j].date,e.date);
	strcpy(L.p[j].time,e.time);
	strcpy(L.p[j].place,e.place);
	L.p[j].temp=e.temp;
	L.p[j].hum=e.hum;
	L.length++;
	return OK;
}
int Locate(SqList L,char e[],char f[])//按时间和地点查找
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(strcmp(L.p[i].time,e)==0&&strcmp(L.p[i].place,f)==0)
		{
			cout<<"第"<<i+1<<"个信息的日期是"<<L.p[i].date<<",时间是"<<L.p[i].time<<",地点是"<<L.p[i].place<<",温度是"<<L.p[i].temp<<",湿度是"<<L.p[i].hum<<endl;
			return OK;
		}
	}
	return ERROR;
	cout<<"对不起，没找到";
}
int ListInsert(SqList &L,int i,message e)//插入一条信息
{
	int j;
	if((i<1)||(i>L.length+1))
		return ERROR;
	if(L.length==MAXSIZE)
		return ERROR;
	for(j=L.length-1;j>=i-1;j--)//插入位置及以后的元素后移
	{
		strcpy(L.p[j+1].date,L.p[j].date);
		strcpy(L.p[j+1].time,L.p[j].time);
		strcpy(L.p[j+1].place,L.p[j].place);
		L.p[j+1].temp=L.p[j].temp;
		L.p[j+1].hum=L.p[j].hum;
	}
	//将新的元素插到第i个位置去
	strcpy(L.p[i-1].date,e.date);
	strcpy(L.p[i-1].time,e.time);
	strcpy(L.p[i-1].place,e.place);
	L.p[i-1].temp=e.temp;
	L.p[i-1].hum=e.hum;
	++L.length;
	return OK;
}
int ListDelete(SqList &L,int i)//删除一条信息
{
	int j;
	if((i<1)||(i>L.length))
		return ERROR;
	for(j=i;j<=L.length-1;j++)//被删除之后的元素前移
	{
		strcpy(L.p[j-1].date,L.p[j].date);
		strcpy(L.p[j-1].time,L.p[j].time);
		strcpy(L.p[j-1].place,L.p[j].place);
		L.p[j-1].temp=L.p[j].temp;
		L.p[j-1].hum=L.p[j].hum;
	}
	--L.length;
	return OK;
}
int main()
{
	cout << "欢迎来到南南的顺序表！" << endl;
	int i,n,k,x;
	message e,g;
	SqList L;
	InitList(L);
	char str[20];
	char strr[20];
	cout<<"请输入要创建的表的个数：";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"第"<<i+1<<"个信息的日期是";
		cin>>e.date;
		cout<<"第"<<i+1<<"个信息的时间是";
		cin>>e.time;
		cout<<"第"<<i+1<<"个信息的地点是";
		cin>>e.place;
		cout<<"第"<<i+1<<"个信息的温度是";
		cin>>e.temp;
		cout<<"第"<<i+1<<"个信息的湿度是";
		cin>>e.hum;
		ListCreate(L,i,e);
	}
	for(i=0;i<n;i++)
	{
		cout<<"第"<<i+1<<"个信息的日期是"<<L.p[i].date<<",时间是"<<L.p[i].time<<",地点是"<<L.p[i].place<<",温度是"<<L.p[i].temp<<",湿度是"<<L.p[i].hum<<endl;
	}
	cout<<"请输入待查找的时间和地点："<<endl;
	cin>>str>>strr;
	Locate(L,str,strr);
	cout<<"请输入待插入的信息"<<endl;
	cout<<"待插入信息的位置是";
	cin>>k;
	cout<<"待插入信息的日期是";
	cin>>g.date;
	cout<<"待插入信息的时间是";
	cin>>g.time;
	cout<<"待插入信息的地点是";
	cin>>g.place;
	cout<<"待插入信息的温度是";
	cin>>g.temp;
	cout<<"待插入信息的湿度是";
	cin>>g.hum;
	ListInsert(L,k,g);
	cout<<"插入操作后的所有的信息如下："<<endl;
	for(i=0;i<L.length;i++)
	{
		cout<<"第"<<i+1<<"个信息的日期是"<<L.p[i].date<<",时间是"<<L.p[i].time<<",地点是"<<L.p[i].place<<",温度是"<<L.p[i].temp<<",湿度是"<<L.p[i].hum<<endl;
	}
	cout<<"请输入删除的位序";
	cin>>x;
	ListDelete(L,x);
	cout<<"删除操作后的所有的信息如下："<<endl;
	for(i=0;i<L.length;i++)
	{
		cout<<"第"<<i+1<<"个信息的日期是"<<L.p[i].date<<",时间是"<<L.p[i].time<<",地点是"<<L.p[i].place<<",温度是"<<L.p[i].temp<<",湿度是"<<L.p[i].hum<<endl;
	}
	return 0;
}