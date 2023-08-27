/*
  ���Ա��˳����ʾ�������C����ʾ��
  Modified by ZhuJie in CDUT
  the operation of list
*/
#include <stdio.h>
#define MAXSIZE 10
typedef int dataType;
//�������͵Ķ���
typedef struct
{
	dataType data[MAXSIZE];/*�������Ա�������*/
	int length;//����ǰ˳���ĳ���
}seqList;

//���Ա�ĳ�ʼ��
int  initSeqList(seqList *L){
    //��˳���lengthֵ��ֵΪ-1������˳�����Ϊ�ձ�
    L->length = -1;
	return 0;
}

//�ж����Ա��Ƿ�Ϊ�ձ�
int isEmpty(seqList L){
   if(L.length == -1)
	   return 1;//��Ϊ��ʱ������1��ʾȷ��
  return 0;//��Ϊ�ǿ�ʱ ����0

}

//�ж����Ա��Ƿ�����
int isFull(seqList L){
    if(L.length == MAXSIZE-1)
		return 1;
	return 0 ;
}

//���������Ա����������
int add(seqList *L){
	int i;
	int j;
	printf("������˳���ĳ���: ");
	scanf("%d",&i);
	printf("������Ԫ��\n");
   L->length = i;
   for(j=0;j<L->length;j++){
		scanf("%d",&L->data[j]);
   }
   return 0;
}

//����ָ������λ���ϵ���ֵ������
int getData(seqList *L,int index){
	int i=0;
	//�ж�˳����Ƿ�����
	if(isFull(*L)==1)
		return -1;//���������޷�����
	//�ж��Ѹ����������Ƿ�Ϸ�
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

//����ָ����ֵ����Ӧ������ֵ��������
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

//ɾ��ָ������λ������
int deleData(seqList *L,int index){
	int i=0,j=0;
   if(isEmpty(*L)==1)
	   return 0;//�ñ�Ϊ�ձ�
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

//���ݲ���
int insertData(seqList *L,int index,dataType data){
	//index ��������λ�ã�data ������Ҫ�����Ԫ��ֵ
    int j;
	//�ж�˳����Ƿ�����
	if(isFull(*L)==1)
		return -1;//���������޷�����
	//�ж��Ѹ����������Ƿ�Ϸ�
	if(index<=0||index>L->length+1)
		return 0;
	//β��ֱ�����
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

//�ϲ��������Ա�
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


//�ڵ�Ԫ�ص�˳�����
int display(seqList	*L){
	int i =0;
	while(i<L->length){
		printf("\t%d. %d\n",i,L->data[i]);
	    i++;
	}
	return 1;
}

//�����˵�����
int operationList(seqList *L){
	int flag=1;
	int data;
	int index;
	int key;
	int ele;
	int local;
	while(flag){
  printf("\t1.��ʼ��˳���\n");
  printf("\t2.����Ԫ��    \n");
  printf("\t3.��ȡָ��λ�õ�Ԫ��\n");
  printf("\t4.��ȡָ��Ԫ�ص�λ��\n");
  printf("\t5.ɾ��ָ��λ��Ԫ��\n");
  printf("\t6.չʾ��ǰ˳���\n");
  printf("\t0.������һ��\n");
  printf("\n");
  printf("������������֣�\n");
  scanf("%d",&key);
  printf("\n");
    switch(key){
	case 1:
		add(L);
		break;
	case 2:
		printf("������Ŀ��λ���Լ�Ԫ��ֵ��");
		scanf("%d  %d",&index,&data);
		insertData(L,index,data);
		printf("\n");
		break;
	case 3:
		printf("������ָ����λ�ã�");
		scanf("%d",&index);
		ele=getData(L,index);
		printf("%d",index);
		printf("��Ӧ��Ԫ��Ϊ��");
		printf("%d ",ele);
		printf("\n");
		break;
	case 4:
		printf("��������Ҫ���ҵ�Ԫ�أ�");
		scanf("%d",&data);
		local=getIndex(L,data);
		printf("%d",data);
		printf("���ڵ�λ��Ϊ��");
		printf("%d",local);
		printf("\n");
		break;
	case 5:
		printf("��������Ҫɾ����λ�ã�");
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

//������
int main(){
	int key;
	int  isFlag=1;
	seqList La,Lb,Lc;
	initSeqList(&La);
	initSeqList(&Lb);
	initSeqList(&Lc);
	while(isFlag){
    printf("\t1.˳���La�Ĳ���\n");
	printf("\t2.˳���Lb�Ĳ���\n");
	printf("\t3.˳���ĺϲ�����\n");
	printf("\t4.��ʾ�ϲ����˳���\n");
	printf("\t0.�˳�����ϵͳ\n");
	printf("\n������������֣�");
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


