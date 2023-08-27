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
			cout << "第" << k << "次比较元素" << T->data.key << endl;
			return SearchBST(T->lchild, key);
		}
		else
		{
			cout << "第" << k << "次比较元素" << T->data.key << endl;
			return SearchBST(T->rchild, key);
		}
	}
}

int main()
{
	int a;
	cout << "欢迎来到南南的二叉树查找！" << endl;
	cout << "请创建你的树！（-1表示创建完成）" << endl;
	BSTree lby;
	CreatBST(lby);
	cout << "创建完成！" << endl;
	cout << "请输入需要查找的元素" << endl;
	cin >> a;
	SearchBST(lby, a);
	if (SearchBST(lby, a))
	{
		cout << "查找成功!";
	}
	else
	{
		cout << "查找失败!";
	}
	return 0;
}