#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
using namespace std;
int k = 0;
typedef struct
{
	int key;
	int otherinfo;
}ElemType;
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode *lchild, *rchild;
}BSTNode,*BSTree;
void InsertBST(BSTree &T, ElemType e)
{
	BSTree S;
	if (!T)
	{
		S = new BSTNode;
		S->data = e;
		S->lchild = S->rchild = NULL;
		T = S;
	}
	else if (e.key < T->data.key)
		InsertBST(T->lchild, e);
	else if (e.key > T->data.key)
		InsertBST(T->rchild, e);
}
void CreatBST(BSTree &T)
{
	ElemType e;
	T = NULL;
	cin >> e.key;
	while (e.key != -1)
	{
		InsertBST(T, e);
		cin >> e.key;
	}
}
BSTree SearchBST(BSTree T, int key)
{
	if ((!T) || key == T->data.key) 
		return T;
	else
	{
		k++;
		if (key < T->data.key)
		{
			cout << "��" << k << "�αȽ�Ԫ��" << T->data.key << endl;
			return SearchBST(T->lchild, key);
		}
		else
		{
			cout << "��" << k << "�αȽ�Ԫ��" << T->data.key << endl;
			return SearchBST(T->rchild, key);
		}
	}
}

int main()
{
	int a;
	cout << "��ӭ�������ϵĶ��������ң�" << endl;
	cout << "�봴�����������-1��ʾ������ɣ�" << endl;
	BSTree lby;
	CreatBST(lby);
	cout << "������ɣ�" << endl;
	cout << "��������Ҫ���ҵ�Ԫ��" << endl;
	cin >> a;
	SearchBST(lby, a);
	if (SearchBST(lby, a))
	{
		cout << "���ҳɹ�!";
	}
	else
	{
		cout << "����ʧ��!";
	}
	return 0;
}