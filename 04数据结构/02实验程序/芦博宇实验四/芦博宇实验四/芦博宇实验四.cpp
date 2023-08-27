#include<iostream>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
using namespace std;
#define MaxInt 32767
#define MVNum 100
int D[100], S[100], Path[100];
typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;
int InitQueue(SqQueue &Q)
{
	Q.base = new int[100];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return 1;
}
int EnQueue(SqQueue &Q, int e)//入队（在队尾插入）
{
	if ((Q.rear + 1) % 100 == Q.front)
		return -1;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % 100;
	return 1;
}
int DeQueue(SqQueue &Q, int &e)//出队（将队头元素删除）
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
typedef struct
{
	char vexs[MVNum][MVNum];
	int arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;
int LocateVex(AMGraph &G, char n[MVNum])
{
	int i=0;
	while(strcmp(G.vexs[i], n))
	{
		i++;
	}
	return i;
}
int CreateUDN(AMGraph &G)//邻接矩阵法创建无向网
{
	int i,j,k,w;
	char v1[MVNum];
	char v2[MVNum];
	cout << "请输入总顶点数" << endl;
	cin >> G.vexnum;
	cout << "请输入总边数" << endl;
	cin >> G.arcnum;
	cout << "请依次输入顶点信息" << endl;
	for (i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vexs[i];
	}
	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	cout << "初始化完成" << endl;
	for (k = 0; k < G.arcnum; ++k)
	{
		cout << "请输入第"<<k+1<<"个路径的头结点、尾节点和权重" << endl;
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
	cout << "输入完成" << endl;
	return 1;
}
bool visited[MVNum];
void DFS_AM(AMGraph G, int v)
{
	int w;
	cout << G.vexs[v] << endl;
	visited[v] = true;
	for (w = 0; w < G.vexnum; w++)
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DFS_AM(G, w);
	}
}//深度优先遍历

void BFS_AM(AMGraph G, int v)
{         
	int w;
	SqQueue Q;
	InitQueue(Q);
	cout << G.vexs[v] << endl;
	visited[v] = true;
	EnQueue(Q, v);
	while (Q.front!=Q.rear) 
	{
		DeQueue(Q, v);
		for (w = 0; w < G.vexnum; w++)
		{
			if (!visited[w]) 
			{        
				cout << G.vexs[w] << endl; 
				visited[w] = true;   
				EnQueue(Q, w);
			}
		}
	}
}//广度优先遍历
void ShortestPath_DIJ(AMGraph G, int v0)
{
	int n, v, i, min, w;
	n = G.vexnum;
	for (v = 0; v < n; ++v)
	{
		S[v] = false;
		D[v] = G.arcs[v0][v];
		if (D[v] < MaxInt)
			Path[v] = v0;
		else
			Path[v] = -1;
	}
	S[v0] = true;
	D[v0] = 0;
	for (i = 1; i < n; ++i)
	{
		min = MaxInt;
		for (w = 0; w < n; ++w)
		{
			if (!S[w] && D[w] < min)
			{
				v = w;
				min = D[w];
			}
		}
		S[v] = true;
		for (w = 0; w < n; ++w)
		{
			if (!S[w] && (D[v] + G.arcs[v][w] < D[w]))
			{
				D[w] = D[v] + G.arcs[v][w];
				Path[w] = v;
			}
		}
	}
}
int main()
{
	cout << "欢迎来到南南的理工地图网！" << endl;
	AMGraph lby1,lby2;
	CreateUDN(lby1);
	lby2 = lby1;
	int a;
	int ximen = 0;
	int xiang = 3;
	while(1)
	{
		cout << "请选择你要执行的操作：(默认从西门开始遍历)" << endl;
		cout << "1：深度优先遍历" << endl;
		cout << "2：广度优先遍历" << endl;
		cout << "3：输出西门到香樟的最短距离" << endl;
		
		while (1)
		{
			cin >> a;
			switch (a)
			{
			case 1:
			{
				DFS_AM(lby1, ximen);
				break;
			}
			case 2:
			{
				BFS_AM(lby2, ximen);
				break;
			}
			case 3:
			{
				ShortestPath_DIJ(lby1, ximen);
				cout << D[xiang];
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}
	
	
	return 0;
}
