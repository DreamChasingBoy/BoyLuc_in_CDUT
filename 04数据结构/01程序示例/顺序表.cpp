/*
  线性表的顺序表表示及其操作C语言示例
  Modified by ZhuJie in CDUT
  the operation of list
*/
#include <stdio.h>
#define MAXSIZE 10
typedef int dataType;
//抽象类型的定义
typedef struct
{
	dataType data[MAXSIZE];/*定义线性表是数组*/
	int length;//代表当前顺序表的长度
}seqList;

//线性表的初始化
int  initSeqList(seqList *L){
    //将顺序表length值赋值为-1，即将顺序表置为空表
    L->length = -1;
	return 0;
}

//判断线性表是否为空表
int isEmpty(seqList L){
   if(L.length == -1)
	   return 1;//表为空时，返回1表示确认
  return 0;//表为非空时 返回0

}

//判断线性表是否已满
int isFull(seqList L){
    if(L.length == MAXSIZE-1)
		return 1;
	return 0 ;
}

//批量向线性表中填充数据
int add(seqList *L){
	int i;
	int j;
	printf("请输入顺序表的长度: ");
	scanf("%d",&i);
	printf("请输入元素\n");
   L->length = i;
   for(j=0;j<L->length;j++){
		scanf("%d",&L->data[j]);
   }
   return 0;
}

//查找指定索引位置上的数值并返回
int getData(seqList *L,int index){
	int i=0;
	//判断顺序表是否已满
	if(isFull(*L)==1)
		return -1;//表已满，无法插入
	//判断已给出的索引是否合法
	if(index-1<0||index-1>L->length)
		return 0;
	else{
		while(i<L->length){
		  if(index-1 == i)
			  return L->data[index-1];
		i++;
		}
	}
	return 1;
}

//查找指定数值所对应的索引值，并返回
int getIndex(seqList *L,dataType data){
	int i=0;
	while(i<L->length){
		if(L->data[i]==data)
			return i+1;
		else
			return 0;
	}
	return -1;

}

//删除指定索引位置数据
int deleData(seqList *L,int index){
	int i=0,j=0;
   if(isEmpty(*L)==1)
	   return 0;//该表为空表
   if(index<=1||index-1>L->length)
	   return 0;
   else{
	   while(i<L->length){
		   if(index-1 == i ){
			   for(j=index;j<L->length;j++){
			    L->data[j-1]=L->data[j];
			   }
			   L->length--;
			   return 1;
		   }
		   i++;
	   
	   }
   }
   return 1;
}

//数据插入
int insertData(seqList *L,int index,dataType data){
	//index 代表插入的位置，data 代表需要插入的元素值
    int j;
	//判断顺序表是否已满
	if(isFull(*L)==1)
		return -1;//表已满，无法插入
	//判断已给出的索引是否合法
	if(index<=0||index>L->length+1)
		return 0;
	//尾部直接添加
	if(index == L->length){
		L->data[index]= data;
		L->length++;
		return 1;
	}else{
		for (j=L->length-1;j>=index;j--){
			L->data[j+1] = L->data[j];
		}
		L->data[index-1] = data;
		L->length++;
		return  1;
	}
	return 0;
}

//合并两个线性表
int combineList(seqList *La,seqList *Lb,seqList *Lc){
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < La->length && j < Lb->length)
	{
		if(La->data[i] < Lb->data[j]){
		Lc->data[k] = La->data[i];
		i++;
		k++;
		}
		 if(La->data[i] > Lb->data[j]){
		Lc->data[k] = Lb->data[j];
		k++;
		j++;
		}
		if(La->data[i] == Lb->data[j]){
		Lc->data[k] = La->data[i];
		i++;
		k++;
		j++;
		}
	}
	while(i<La->length){
	   Lc->data[k]=La->data[i];
	   i++;
	   k++;
	}
	while(j<Lb->length){
		Lc->data[k]=Lb->data[j];
		j++;
		k++;
	}
	Lc->length= k;
    return 1;
}


//节点元素的顺序输出
int display(seqList	*L){
	int i =0;
	while(i<L->length){
		printf("\t%d. %d\n",i,L->data[i]);
	    i++;
	}
	return 1;
}

//操作菜单定义
int operationList(seqList *L){
	int flag=1;
	int data;
	int index;
	int key;
	int ele;
	int local;
	while(flag){
  printf("\t1.初始化顺序表\n");
  printf("\t2.插入元素    \n");
  printf("\t3.获取指定位置的元素\n");
  printf("\t4.获取指定元素的位置\n");
  printf("\t5.删除指定位置元素\n");
  printf("\t6.展示当前顺序表\n");
  printf("\t0.返回上一步\n");
  printf("\n");
  printf("请输入操作数字：\n");
  scanf("%d",&key);
  printf("\n");
    switch(key){
	case 1:
		add(L);
		break;
	case 2:
		printf("请输入目标位置以及元素值：");
		scanf("%d  %d",&index,&data);
		insertData(L,index,data);
		printf("\n");
		break;
	case 3:
		printf("请输入指定的位置：");
		scanf("%d",&index);
		ele=getData(L,index);
		printf("%d",index);
		printf("对应的元素为：");
		printf("%d ",ele);
		printf("\n");
		break;
	case 4:
		printf("请输入需要查找的元素：");
		scanf("%d",&data);
		local=getIndex(L,data);
		printf("%d",data);
		printf("所在的位置为：");
		printf("%d",local);
		printf("\n");
		break;
	case 5:
		printf("请输入需要删除的位置：");
		scanf("%d",&data);
		deleData(L,data);
		printf("\n");
		break;
	case 6:
		display(L);
		printf("\n");
		break;
	case 0:
		flag = 0;
		printf("\n");
		break;
	}
 }
	return 1;
}

//主函数
int main(){
	int key;
	int  isFlag=1;
	seqList La,Lb,Lc;
	initSeqList(&La);
	initSeqList(&Lb);
	initSeqList(&Lc);
	while(isFlag){
    printf("\t1.顺序表La的操作\n");
	printf("\t2.顺序表Lb的操作\n");
	printf("\t3.顺序表的合并操作\n");
	printf("\t4.显示合并后的顺序表\n");
	printf("\t0.退出操作系统\n");
	printf("\n请输入操作数字：");
		scanf("%d",&key);
		printf("\n");
	switch (key){
	case 1:
		operationList(&La);
		printf("\n");
	    break;
	case 2:
		operationList(&Lb);
		printf("\n");
		break;
	case 3:
		combineList(&La,&Lb,&Lc);
		printf("\n");
		break;
	case 4:
		display(&Lc);
		printf("\n");
		break;
	case 0:
		isFlag = 0;
		printf("\n");
		break;
	}
 }
	return 1;
}


