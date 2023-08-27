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
void BeforeTheOrderTraverse(BiTree T)//ǰ�����
{
	if(T)
	{
		cout<<T->data<<endl;
		BeforeTheOrderTraverse(T->lchild);
		BeforeTheOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T)//�������
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data<<endl;
		InOrderTraverse(T->rchild);
	}
}
void BehindTheOrderTraverse(BiTree T)//�������
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
 	if(T==NULL) 	//����ǿ�������0
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1; //�����Ҷ�ӽ�㷵��1
	else return LeafCount(T->lchild) + LeafCount(T->rchild);

}
void cqianxu()
{
	cout << "���游" << endl;
	cout << "�游" << endl;
	cout << "����" << endl;
	cout << "��" << endl;
	cout << "�ù�" << endl;
	cout << "���" << endl;
	cout << "���游" << endl;
	cout << "����" << endl;
}
void czhongxu()
{
	cout << "��" << endl;
	cout << "����" << endl;
	cout << "�游" << endl;
	cout << "���" << endl;
	cout << "�ù�" << endl;
	cout << "���游" << endl;
	cout << "����" << endl;
	cout << "���游" << endl;
}
void chouxu()
{
	cout << "��" << endl;
	cout << "����" << endl;
	cout << "���" << endl;
	cout << "�ù�" << endl;
	cout << "�游" << endl;
	cout << "����" << endl;
	cout << "���游" << endl;
	cout << "���游" << endl;
}
int main()
{
	cout << "��ӭ�������ϵļ�������" << endl;
	int i,j,k;
	BiTree  lby;
	//CreateBiTree(lby);
	cqianxu();
	while (1)
	{
		cout << "��ѡ���������" << endl << "1 ǰ�����" << endl << "2 �������" << endl << "3 �������";
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
		cout << "������������" << "4"<<endl;
		cout << "�������Ҷ������" << "3"<<endl;
	}
	return 0;
}