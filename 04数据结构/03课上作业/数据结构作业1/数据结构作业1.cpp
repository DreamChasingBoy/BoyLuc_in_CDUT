#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 80
char num[N][N];
char str[50];
typedef struct student
{
	char num_name[80];
	int apples;
}node;
node cekongsanban[33];
void init()//��ʼ���������˶�û��ƻ��
{
	int i;
	for(i=0;i<34;i++)
	{cekongsanban[i].apples=0;}
}
void file()//��ȡ�ļ������ļ��е���Ϣ�ŵ���ά�ַ�������
{
	int i;
	FILE *fp;
	fp=fopen("E:\\name.txt","r");
	if(fp==NULL)
	{
		printf("file cannot be open.\n");
		exit(0);
	}
	
	while(!feof(fp))
	{
		for(i=0;i<=34;i++)
		{
			fgets(num[i],80,fp);
			strcpy(cekongsanban[i].num_name,&num[i][N]);
		}
		
	}
	fclose(fp);
}
void jisuan()
{
	int i,j;
	for(j=1;j<4;j++)
	{
		for(i=0;i<=33;i++)
		{
			if((i+1)%((int)(pow((float)3,j)))==0)
			{cekongsanban[i].apples++;}
		}
	}
}
int max(int a,int b)//˭�����˭��һ�������a
{
	if(a>=b)
	{
		return a;
	}
	else 
	{
		return b;
	}
}
int sheiduo()
{
	int i,j;
	j=max(cekongsanban[0].apples,cekongsanban[1].apples);//0�ź�1��˭��
	for(i=2;i<=34;i++)
	{
		j=max(j,cekongsanban[i].apples);
	}
	return j;
}
void mingzi()
{
	int i;
	for(i=0;i<=34;i++)
	{
		if(cekongsanban[i].apples==sheiduo())
			strcpy(str,cekongsanban[i].num_name);
	}
}


int main()
{
	int ping;
	file();
	jisuan();
	ping=sheiduo();
	mingzi();
	printf("�����˳Ե���%d��ƻ��������������ѧ����%s",ping,str);
	printf("«����Ե���%d��ƻ��\n",cekongsanban[29].apples);
	//printf("%s",cekongsanban[26].num_name);
	return 0;
}