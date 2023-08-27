#include<iostream>
#include<string.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{
	int key;
	int otherinfo;
}ElemType;
typedef struct
{
	ElemType *R;
	int length;
}SSTable;
int InitList(SSTable &ST)//��ʼ��
{
	ST.R = new ElemType[MAXSIZE];//����洢�ռ�
	if (!ST.length)
		exit(OVERFLOW);
	ST.length = 0;//�ձ���Ϊ0
	cout << "��ʼ����ɣ�" << endl;
	return OK;
}
int ListCreate(SSTable &ST, int j, ElemType e)//����˳���
{
	if (j<0 || j>MAXSIZE)
		return ERROR;
	if (ST.length == MAXSIZE)
		return OVERFLOW;
	ST.R[j].key = e.key;
	ST.length++;
	return OK;
}
int Search_Seq(SSTable ST, int key)
{
	int i;
	ST.R[0].key = key;
	for (i = ST.length; ST.R[i].key != key; --i)
	{
		cout << "��" << ST.length-i+1 << "�αȽ�Ԫ��" << ST.R[i].key << endl;
	}
	return i;
}
int Search_Bin(SSTable ST, int key)
{
	int low = 1;
	int mid,i=1;
	int high = ST.length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == ST.R[mid].key)
		{
			return mid;
		}
		else
		{
			cout << "��" << i << "�αȽ�Ԫ��" << ST.R[mid].key << endl;
			i++;
			if (key <= ST.R[mid].key)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		
	}
	return 0;
}
int main()
{
	int n,i,j,k,a;
	cout << "��ӭ����׷���������ϵĲ��ң�" << endl;
	ElemType nannan;
	SSTable lby;
	InitList(lby);
	cout << "������Ҫ�����ı�ĸ�����";
	cin >> n;
	cout << "��ʼ���룺";
	for (i = 1; i <= n; i++)
	{
		cin >> nannan.key;
		ListCreate(lby, i, nannan);
	}
	cout << "������ɣ���ʼ��Ĳ��ң�" << endl << "��Ҫ�����ĸ�Ԫ���أ�" << endl;
	cin >> k;
	cout << "����ѡ�����ַ����أ�" << endl;
	cout << "1.˳�����" << endl;
	cout << "2.�۰����" << endl;
	cin >> a;
	switch (a)
	{
		case 1:
		{
			j = Search_Seq(lby, k);
			break;
		}
		case 2:
		{
			j = Search_Bin(lby, k);
			break;
		}
		default:
		{
			cout << "û�����ֲ��ҷ�ʽ��";
			break;
		}
	}
	if (j)
	{
		cout << "���ҳɹ���i=" << j;
	}
	else
	{
		cout << "����ʧ��";
	}
	return 0;
}