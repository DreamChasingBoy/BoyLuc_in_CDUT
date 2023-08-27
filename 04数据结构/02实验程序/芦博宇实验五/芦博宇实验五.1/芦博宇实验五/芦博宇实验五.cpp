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
int InitList(SSTable &ST)//初始化
{
	ST.R = new ElemType[MAXSIZE];//分配存储空间
	if (!ST.length)
		exit(OVERFLOW);
	ST.length = 0;//空表长度为0
	cout << "初始化完成！" << endl;
	return OK;
}
int ListCreate(SSTable &ST, int j, ElemType e)//输入顺序表
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
		cout << "第" << ST.length-i+1 << "次比较元素" << ST.R[i].key << endl;
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
			cout << "第" << i << "次比较元素" << ST.R[mid].key << endl;
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
	cout << "欢迎来到追梦少年南南的查找！" << endl;
	ElemType nannan;
	SSTable lby;
	InitList(lby);
	cout << "请输入要创建的表的个数：";
	cin >> n;
	cout << "开始输入：";
	for (i = 1; i <= n; i++)
	{
		cin >> nannan.key;
		ListCreate(lby, i, nannan);
	}
	cout << "输入完成！开始你的查找！" << endl << "你要查找哪个元素呢？" << endl;
	cin >> k;
	cout << "你想选择哪种方法呢？" << endl;
	cout << "1.顺序查找" << endl;
	cout << "2.折半查找" << endl;
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
			cout << "没有这种查找方式！";
			break;
		}
	}
	if (j)
	{
		cout << "查找成功，i=" << j;
	}
	else
	{
		cout << "查找失败";
	}
	return 0;
}