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
void init()//初始化，所有人都没有苹果
{
	int i;
	for(i=0;i<34;i++)
	{cekongsanban[i].apples=0;}
}
void file()//读取文件，令文件中的信息放到二维字符串组中
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
int max(int a,int b)//谁大输出谁，一样大输出a
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
	j=max(cekongsanban[0].apples,cekongsanban[1].apples);//0号和1号谁多
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
	printf("最多的人吃到了%d个苹果，他的姓名和学号是%s",ping,str);
	printf("芦博宇吃到了%d个苹果\n",cekongsanban[29].apples);
	//printf("%s",cekongsanban[26].num_name);
	return 0;
}