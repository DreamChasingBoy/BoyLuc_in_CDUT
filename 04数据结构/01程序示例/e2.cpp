/***��ջ�Ͷ���Ӧ��ʵ��***/

#include"queque.h";
#include"stack.h";

//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2


//���Ƶ�ת��(��ջʵ��)
void conversion(int N) {//��������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����
	int e;
	LinkStack S;
	InitStack(S); //��ʼ����ջS
	while (N) //��N����ʱ,ѭ��
	{
		Push(S, N % 8); //��N��8����õ��İ˽�����ѹ��ջS
		N = N / 8; //N����ΪN��8����
	}
	while (!StackEmpty(S)) //��ջS�ǿ�ʱ��ѭ��
	{
		Pop(S, e); //����ջ��Ԫ��e
		cout << e; //���e
	}
}
int main() {
	
	int no,i,countofconv,choose;

	Person custmer;
	int input[10];
	no=-1;;
	while(no!=0){
		cout<<"ʵ��� ��ջ�Ͷ���Ӧ��\n";
		cout<<"1����ջӦ��֮������ת��\n";
		cout<<"2������Ӧ��֮�����Ŷ�\n";
		cout<<"0���˳�\n";
		cout<<"��ѡ��ʵ�飺";
		cin>>no;

		switch(no){
		case 0: cout<<endl;break;
		case 1:
			//�������������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����
			cout<<"���������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����\n";
			cout<<"------------------------------------------------------\n";
			cout<<"��������ת�������ĸ�����";
			cin>>countofconv;
			if(countofconv>10){
				cout<<"\n���������Χ!";
				cout<<endl;
				break;
			}
			for(i=0;i<countofconv;++i){
				cout << "�����"<<i+1<<"���Ǹ�ʮ������:\n" ;
				cin >> input[i];
			}
		
			cout<<"ת�����Ϊ��\n";
			for(i=0;i<countofconv;++i){
				conversion(input[i]);
				cout<<"\n";
			}
			break;
		case 2:
			//�����Ŷ�ʵ��
			cout<<"���пͻ��Ŷ�ʵ��\n";
			cout<<"------------------------------------------------------\n";
			//��ʼ������
			if (!InitQueue(custmers)) {
				cout << "��ʼ�������ŶӵĶ���ʧ�ܣ�"<<endl;
				break;
			}
			countofcustmer=0;
			choose=-1;
			while(choose!=0)
			{
				cout<<"��1���ͻ������Ŷ�ϵͳ\n";
				cout<<"��2���ͻ��뿪\n";
				//cout<<"��3����ѯ��ǰ�ͻ�ǰ�滹�м���\n";
				//cout<<"��4����ѯ����Ŀǰ�ܹ�������ٿͻ�\n";
				cout<<"��0������\n";
				cout<<"�Ŷӻ���ӣ���ѡ��";
				cin>>choose;		

				switch (choose) {
				case 1: //�ͻ������Ŷ�ϵͳ
					cout<<"������ͻ��������Ա�";
					cin>>custmer.name>>custmer.sex;
					EnQueue(custmers, custmer);
					++countofcustmer;
					//��ʾ���
					ShowInfo(custmers);
					break;
				case 2://�ͻ������뿪
					if(QueueEmpty(custmers)==OK){
						cout<<"��ǰû�пͻ����ŶӰ���ҵ��\n";
						break;
					}
					DeQueue(custmers, custmer);
			
					//��ʾ���
					ShowInfo(custmers);
					break;
				}//end switch(choose)
	
			}//end while choose

		break;
		} //end switch no

	}//en while no	

	
	return 0;
}