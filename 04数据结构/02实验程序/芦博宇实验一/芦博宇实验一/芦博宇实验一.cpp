#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct//����һ��message����Ϣ��
{
	char date[20];
	char time[20];
	char place[20];
	int temp;
	int hum;
}message;
typedef struct//����һ��˳���
{
	message *p;
	int length;
}SqList;

//�ܹ�����������Ϣ��������
int InitList(SqList &L)//��ʼ��
{
	L.p=new message[MAXSIZE];//����洢�ռ�
	if(!L.p)
		exit(OVERFLOW);
	L.length=0;//�ձ���Ϊ0
	return OK;
}
int ListCreate(SqList &L,int j,message e)//������Ϣ
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
int Locate(SqList L,char e[],char f[])//��ʱ��͵ص����
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(strcmp(L.p[i].time,e)==0&&strcmp(L.p[i].place,f)==0)
		{
			cout<<"��"<<i+1<<"����Ϣ��������"<<L.p[i].date<<",ʱ����"<<L.p[i].time<<",�ص���"<<L.p[i].place<<",�¶���"<<L.p[i].temp<<",ʪ����"<<L.p[i].hum<<endl;
			return OK;
		}
	}
	return ERROR;
	cout<<"�Բ���û�ҵ�";
}
int ListInsert(SqList &L,int i,message e)//����һ����Ϣ
{
	int j;
	if((i<1)||(i>L.length+1))
		return ERROR;
	if(L.length==MAXSIZE)
		return ERROR;
	for(j=L.length-1;j>=i-1;j--)//����λ�ü��Ժ��Ԫ�غ���
	{
		strcpy(L.p[j+1].date,L.p[j].date);
		strcpy(L.p[j+1].time,L.p[j].time);
		strcpy(L.p[j+1].place,L.p[j].place);
		L.p[j+1].temp=L.p[j].temp;
		L.p[j+1].hum=L.p[j].hum;
	}
	//���µ�Ԫ�ز嵽��i��λ��ȥ
	strcpy(L.p[i-1].date,e.date);
	strcpy(L.p[i-1].time,e.time);
	strcpy(L.p[i-1].place,e.place);
	L.p[i-1].temp=e.temp;
	L.p[i-1].hum=e.hum;
	++L.length;
	return OK;
}
int ListDelete(SqList &L,int i)//ɾ��һ����Ϣ
{
	int j;
	if((i<1)||(i>L.length))
		return ERROR;
	for(j=i;j<=L.length-1;j++)//��ɾ��֮���Ԫ��ǰ��
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
	cout << "��ӭ�������ϵ�˳���" << endl;
	int i,n,k,x;
	message e,g;
	SqList L;
	InitList(L);
	char str[20];
	char strr[20];
	cout<<"������Ҫ�����ı�ĸ�����";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"��"<<i+1<<"����Ϣ��������";
		cin>>e.date;
		cout<<"��"<<i+1<<"����Ϣ��ʱ����";
		cin>>e.time;
		cout<<"��"<<i+1<<"����Ϣ�ĵص���";
		cin>>e.place;
		cout<<"��"<<i+1<<"����Ϣ���¶���";
		cin>>e.temp;
		cout<<"��"<<i+1<<"����Ϣ��ʪ����";
		cin>>e.hum;
		ListCreate(L,i,e);
	}
	for(i=0;i<n;i++)
	{
		cout<<"��"<<i+1<<"����Ϣ��������"<<L.p[i].date<<",ʱ����"<<L.p[i].time<<",�ص���"<<L.p[i].place<<",�¶���"<<L.p[i].temp<<",ʪ����"<<L.p[i].hum<<endl;
	}
	cout<<"����������ҵ�ʱ��͵ص㣺"<<endl;
	cin>>str>>strr;
	Locate(L,str,strr);
	cout<<"��������������Ϣ"<<endl;
	cout<<"��������Ϣ��λ����";
	cin>>k;
	cout<<"��������Ϣ��������";
	cin>>g.date;
	cout<<"��������Ϣ��ʱ����";
	cin>>g.time;
	cout<<"��������Ϣ�ĵص���";
	cin>>g.place;
	cout<<"��������Ϣ���¶���";
	cin>>g.temp;
	cout<<"��������Ϣ��ʪ����";
	cin>>g.hum;
	ListInsert(L,k,g);
	cout<<"�������������е���Ϣ���£�"<<endl;
	for(i=0;i<L.length;i++)
	{
		cout<<"��"<<i+1<<"����Ϣ��������"<<L.p[i].date<<",ʱ����"<<L.p[i].time<<",�ص���"<<L.p[i].place<<",�¶���"<<L.p[i].temp<<",ʪ����"<<L.p[i].hum<<endl;
	}
	cout<<"������ɾ����λ��";
	cin>>x;
	ListDelete(L,x);
	cout<<"ɾ������������е���Ϣ���£�"<<endl;
	for(i=0;i<L.length;i++)
	{
		cout<<"��"<<i+1<<"����Ϣ��������"<<L.p[i].date<<",ʱ����"<<L.p[i].time<<",�ص���"<<L.p[i].place<<",�¶���"<<L.p[i].temp<<",ʪ����"<<L.p[i].hum<<endl;
	}
	return 0;
}