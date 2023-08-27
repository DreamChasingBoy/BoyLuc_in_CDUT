/***堆栈和队列应用实验***/

#include"queque.h";
#include"stack.h";

//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2


//数制的转换(链栈实现)
void conversion(int N) {//对于任意一个非负十进制数，打印输出与其等值的八进制数
	int e;
	LinkStack S;
	InitStack(S); //初始化空栈S
	while (N) //当N非零时,循环
	{
		Push(S, N % 8); //把N与8求余得到的八进制数压入栈S
		N = N / 8; //N更新为N与8的商
	}
	while (!StackEmpty(S)) //当栈S非空时，循环
	{
		Pop(S, e); //弹出栈顶元素e
		cout << e; //输出e
	}
}
int main() {
	
	int no,i,countofconv,choose;

	Person custmer;
	int input[10];
	no=-1;;
	while(no!=0){
		cout<<"实验二 堆栈和队列应用\n";
		cout<<"1、堆栈应用之进制数转换\n";
		cout<<"2、队列应用之银行排队\n";
		cout<<"0、退出\n";
		cout<<"请选择实验：";
		cin>>no;

		switch(no){
		case 0: cout<<endl;break;
		case 1:
			//对于输入的任意一个非负十进制数，打印输出与其等值的八进制数
			cout<<"输入的任意一个非负十进制数，打印输出与其等值的八进制数\n";
			cout<<"------------------------------------------------------\n";
			cout<<"请输入需转换的数的个数：";
			cin>>countofconv;
			if(countofconv>10){
				cout<<"\n超出输出范围!";
				cout<<endl;
				break;
			}
			for(i=0;i<countofconv;++i){
				cout << "输入第"<<i+1<<"个非负十进制数:\n" ;
				cin >> input[i];
			}
		
			cout<<"转换结果为：\n";
			for(i=0;i<countofconv;++i){
				conversion(input[i]);
				cout<<"\n";
			}
			break;
		case 2:
			//银行排队实验
			cout<<"银行客户排队实验\n";
			cout<<"------------------------------------------------------\n";
			//初始化队列
			if (!InitQueue(custmers)) {
				cout << "初始化银行排队的队列失败！"<<endl;
				break;
			}
			countofcustmer=0;
			choose=-1;
			while(choose!=0)
			{
				cout<<"（1）客户进入排队系统\n";
				cout<<"（2）客户离开\n";
				//cout<<"（3）查询当前客户前面还有几人\n";
				//cout<<"（4）查询截至目前总共办理多少客户\n";
				cout<<"（0）返回\n";
				cout<<"排队或出队，请选择：";
				cin>>choose;		

				switch (choose) {
				case 1: //客户进入排队系统
					cout<<"请输入客户姓名和性别：";
					cin>>custmer.name>>custmer.sex;
					EnQueue(custmers, custmer);
					++countofcustmer;
					//显示结果
					ShowInfo(custmers);
					break;
				case 2://客户出队离开
					if(QueueEmpty(custmers)==OK){
						cout<<"当前没有客户在排队办理业务！\n";
						break;
					}
					DeQueue(custmers, custmer);
			
					//显示结果
					ShowInfo(custmers);
					break;
				}//end switch(choose)
	
			}//end while choose

		break;
		} //end switch no

	}//en while no	

	
	return 0;
}