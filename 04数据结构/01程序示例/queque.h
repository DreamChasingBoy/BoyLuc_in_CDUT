#include<iostream>
#include<fstream>
#include<string>
#define MAXQSIZE 100//���п��ܴﵽ����󳤶�
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct {
	char name[20]; //����
	char sex[8]; //�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
} Person;

//- - - - - ���е�˳��洢�ṹ- - - - - 
typedef struct {
	Person *base; //����������Ԫ������ΪPerson
	int front; //ͷָ��
	int rear; //βָ��
} SqQueue;

SqQueue custmers;
int countofcustmer;

int InitQueue(SqQueue &Q) {//����һ���ն���Q
	Q.base = new Person[MAXQSIZE]; //Ϊ���з���һ���������ΪMAXSIZE������ռ�
	if (!Q.base)
		exit( OVERFLOW); //�洢����ʧ��
	Q.front = Q.rear = 0; //ͷָ���βָ����Ϊ�㣬����Ϊ��
	return OK;
}

int EnQueue(SqQueue &Q, Person e) {//����Ԫ��eΪQ���µĶ�βԪ��
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //βָ����ѭ�������ϼ�1�����ͷָ�룬��������
		return ERROR;
	Q.base[Q.rear] = e; //��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; //��βָ���1
	return OK;
}

int QueueEmpty(SqQueue &Q) {
	if (Q.front == Q.rear) //�ӿ�
		return OK;
	else
		return ERROR;
}

//��ѭ�����еĳ���
int QueueLength(SqQueue Q) {//����Q��Ԫ�ظ����������еĳ���
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

int DeQueue(SqQueue &Q, Person &e)//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
{
	if (Q.front == Q.rear)
		return ERROR; //�ӿ�
	e = Q.base[Q.front]; //�����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE; //��ͷָ���1
	return OK;
}

Person GetHead(SqQueue Q) {//����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if (Q.front != Q.rear) //���зǿ�
		return Q.base[Q.front]; //���ض�ͷԪ�ص�ֵ����ͷָ�벻��
}

void ShowInfo(SqQueue Q){
	cout<<"��ǰ�Ŷ�����:"<<QueueLength(Q)<<"\n";
	cout<<"�Ѱ�����������"<<countofcustmer-QueueLength(Q)<<"\n";
	Person p;
	p=GetHead(Q);
	cout<<"���ڰ���ҵ��Ŀͻ�Ϊ��"<<p.name<<" "<<p.sex<<"\n";

}

