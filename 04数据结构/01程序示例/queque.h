#include<iostream>
#include<fstream>
#include<string>
#define MAXQSIZE 100//队列可能达到的最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct {
	char name[20]; //姓名
	char sex[8]; //性别，'F'表示女性，'M'表示男性
} Person;

//- - - - - 队列的顺序存储结构- - - - - 
typedef struct {
	Person *base; //队列中数据元素类型为Person
	int front; //头指针
	int rear; //尾指针
} SqQueue;

SqQueue custmers;
int countofcustmer;

int InitQueue(SqQueue &Q) {//构造一个空队列Q
	Q.base = new Person[MAXQSIZE]; //为队列分配一个最大容量为MAXSIZE的数组空间
	if (!Q.base)
		exit( OVERFLOW); //存储分配失败
	Q.front = Q.rear = 0; //头指针和尾指针置为零，队列为空
	return OK;
}

int EnQueue(SqQueue &Q, Person e) {//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q.base[Q.rear] = e; //新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; //队尾指针加1
	return OK;
}

int QueueEmpty(SqQueue &Q) {
	if (Q.front == Q.rear) //队空
		return OK;
	else
		return ERROR;
}

//求循环队列的长度
int QueueLength(SqQueue Q) {//返回Q的元素个数，即队列的长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

int DeQueue(SqQueue &Q, Person &e)//删除Q的队头元素，用e返回其值
{
	if (Q.front == Q.rear)
		return ERROR; //队空
	e = Q.base[Q.front]; //保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; //队头指针加1
	return OK;
}

Person GetHead(SqQueue Q) {//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) //队列非空
		return Q.base[Q.front]; //返回队头元素的值，队头指针不变
}

void ShowInfo(SqQueue Q){
	cout<<"当前排队人数:"<<QueueLength(Q)<<"\n";
	cout<<"已办理完人数："<<countofcustmer-QueueLength(Q)<<"\n";
	Person p;
	p=GetHead(Q);
	cout<<"正在办理业务的客户为："<<p.name<<" "<<p.sex<<"\n";

}

