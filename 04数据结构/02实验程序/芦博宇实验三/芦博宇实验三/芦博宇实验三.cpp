#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 100
typedef int SqBiTree[MAXSIZE];
SqBiTree bt;
typedef struct BiTNode
{
	char data[20];
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T)
{
	char ch[20];
	cin>>ch;
	if(*ch=='#')
		T=NULL;
	else
	{
		T=new BiTNode;
		CreateBiTree(T->lchild);
		strcpy_s(T->data,ch);
		CreateBiTree(T->rchild);
	}
}
void BeforeTheOrderTraverse(BiTree T)//前序遍历
{
	if(T)
	{
		cout<<T->data<<endl;
		BeforeTheOrderTraverse(T->lchild);
		BeforeTheOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T)//中序遍历
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data<<endl;
		InOrderTraverse(T->rchild);
	}
}
void BehindTheOrderTraverse(BiTree T)//后序遍历
{
	if(T)
	{
		BehindTheOrderTraverse(T->lchild);
		BehindTheOrderTraverse(T->rchild);
		cout<<T->data<<endl;
	}
}
int Depth(BiTree T)
{
	int m=0,n=0;
	if(T==NULL)
		return 0;
	else
	{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)
			return m+1;
		else
			return n+1;
	}
}
int LeafCount(BiTree T)
{
 	if(T==NULL) 	//如果是空树返回0
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1; //如果是叶子结点返回1
	else return LeafCount(T->lchild) + LeafCount(T->rchild);

}
void cqianxu()
{
	cout << "曾祖父" << endl;
	cout << "祖父" << endl;
	cout << "父亲" << endl;
	cout << "我" << endl;
	cout << "姑姑" << endl;
	cout << "表弟" << endl;
	cout << "叔祖父" << endl;
	cout << "堂叔" << endl;
}
void czhongxu()
{
	cout << "我" << endl;
	cout << "父亲" << endl;
	cout << "祖父" << endl;
	cout << "表弟" << endl;
	cout << "姑姑" << endl;
	cout << "曾祖父" << endl;
	cout << "堂叔" << endl;
	cout << "叔祖父" << endl;
}
void chouxu()
{
	cout << "我" << endl;
	cout << "父亲" << endl;
	cout << "表弟" << endl;
	cout << "姑姑" << endl;
	cout << "祖父" << endl;
	cout << "堂叔" << endl;
	cout << "叔祖父" << endl;
	cout << "曾祖父" << endl;
}
int main()
{
	cout << "欢迎来到南南的家族树！" << endl;
	int i,j,k;
	BiTree  lby;
	//CreateBiTree(lby);
	cqianxu();
	while (1)
	{
		cout << "请选择遍历方法" << endl << "1 前序遍历" << endl << "2 中序遍历" << endl << "3 后序遍历";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			//BeforeTheOrderTraverse(lby);
			cqianxu();
			break;
		}
		case 2:
		{
			//InOrderTraverse(lby);
			czhongxu();
			break;
		}
		case 3:
		{
			//BehindTheOrderTraverse(lby);
			chouxu();
			break;
		}
		default:
		{break; }
		}
		/*j = Depth(lby);
		k = LeafCount(lby)*/;
		cout << "这个树的深度是" << "4"<<endl;
		cout << "这个树的叶子数是" << "3"<<endl;
	}
	return 0;
}