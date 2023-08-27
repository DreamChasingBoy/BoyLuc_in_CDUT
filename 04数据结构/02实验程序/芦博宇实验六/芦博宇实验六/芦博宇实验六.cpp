#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef struct
{
	int key;
	int otherinfo;
}RedType;
typedef struct
{
	RedType r[MAXSIZE + 1];
	int length;
}SqList;
int b = 0;
int c = 0;
void InitList(SqList &L)//初始化线性表
{
	int i;
	cout << "请输入你要输入数据的个数" << endl;
	cin >> L.length;
	for (i = 1; i <= L.length; i++)
	{
		cout << "请输入您的第" << i << "个数据" << endl;
		cin >> L.r[i].key;
	}
}
void BInsertSort(SqList &L)//折半插入排序
{
	int i, low, high, m, j;
	for (i = 2; i <= L.length; ++i)
	{
		L.r[0] = L.r[i];
		low = 1;
		high = i - 1;
		while (low <= high)
		{
			m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key)
			{
				high = m - 1;
			}
			else
			{
				low = m + 1;
			}
			b++;
		}
		for (j = i - 1; j >= high + 1; --j)
		{
			L.r[j + 1] = L.r[j];
			c++;
		}
		L.r[high + 1] = L.r[0];
	}
}
void BubbleSort(SqList &L)//冒泡排序
{
	int flag, m, j;
	RedType t;
	m = L.length - 1;
	flag = 1;
	while ((m > 0) && (flag == 1))
	{
		flag = 0;
		for (j = 1; j <= m; j++)
		{
			b++;
			if (L.r[j].key > L.r[j + 1].key)
			{
				flag = 1;
				t = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = t;
				c += 3;
			}
		}
		--m;
	}
}
int Partition(SqList &L, int low, int high)	//快速排序
{	
	L.r[0] = L.r[low];
	c++;
	int pivotkey = L.r[low].key;
	while (low < high)
	{
		while (low < high&&L.r[high].key >= pivotkey)
		{
			--high; 
			b++;
		}
		L.r[low] = L.r[high];
		c++;
		while (low < high&&L.r[low].key <= pivotkey)
		{
			++low; 
			b++;
		}
		L.r[high] = L.r[low]; 
		c++;
	}
	L.r[low] = L.r[0]; 
	c++;
	return low;
}
void QSort(SqList &L, int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}
void QuickSort(SqList &L)//对顺序表做快速排序
{
	QSort(L, 1, L.length);
}
void Merge(RedType R[10], RedType T[10], int low, int mid, int high)
{
	int i = low; 
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= high)
	{
		if (R[i].key <= R[j].key)
		{
			T[k++] = R[i++]; 
			b++;
			c++;
		}
		else 
		{ 
			T[k++] = R[j++]; 
			c++;
		}
		b++;
	}
	while (i <= mid) 
	{
		T[k++] = R[i++]; 
		c++;
	}
	while (j <= high) 
	{
		T[k++] = R[j++]; 
		c++;
	}
}

void MSort(RedType R[10], RedType T[10], int low, int high)					//二路归并
{
	RedType S[10];
	if (low == high) T[low] = R[low];
	else {
		int m = (low + high) / 2;//将当前的序列一分为二，分出分裂点m
		MSort(R, S, low, m);//子序列递归归并排序
		MSort(R, S, m + 1, high);//子序列递归归并排序
		Merge(S, T, low, m, high);//将归并的数组一起归并到T数组
	}
}
void MergeSort(SqList &L)
{
	MSort(L.r, L.r, 1, L.length);
}
int main()
{
	int i, d;
	SqList lby;
	cout << "欢迎来到追梦少年南南的排序！" << endl;
	InitList(lby);
	cout << "输入完成！" << endl;
	while (1)
	{
		cout << "请选择你的排序方式！" << endl;
		cout << "1.折半插入排序" << endl;
		cout << "2.冒泡排序" << endl;
		cout << "3.快速排序" << endl;
		cout << "4.二路归并排序" << endl;
		cin >> d;
		switch (d)
		{
		case 1:
		{
			BInsertSort(lby);
			break;
		}
		case 2:
		{
			BubbleSort(lby);
			break;
		}
		case 3:
		{
			QuickSort(lby);
			break;
		}
		case 4:
		{
			MergeSort(lby);
			break;
		}
		default:
			break;
		}
		cout << "排序完成！" << endl;
		cout << "比较次数:" << b << endl;
		cout << "元素移动次数:" << c << endl;
		for (i = 1; i <= lby.length; i++)
		{
			cout << lby.r[i].key << "  ";
		}
	}
	
	return 0;
}