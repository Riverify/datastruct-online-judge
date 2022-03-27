/*
依次输入以下内容（以无向图图1为例）
第1行（图的定点数 n 以及边数 e）：5 6
第2行（图的类型 type): 0
第3行之后（依次输入n个顶点信息）
a
b
c
d
e
继续输入（依次输入e行数据，每行表示一条边的首尾节点的编号）：
0 1
0 3
1 2
1 4
2 3
2 4

输出
图的邻接矩阵（不需要空格）：
01010
10101
01011
10100
01100
*/


#define _CRT_SECURE_NO_WARNINGS


//图的数组（邻接矩阵）存储表示
#include <stdio.h>
#include <stdlib.h>
#define MAX_VEX_NUM 50
typedef char VertexType;
typedef enum {
    DG, UDG
} GraphType;
typedef struct {
    VertexType vexs[MAX_VEX_NUM];
    int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} MGraph;
 
//定位
int getIndexOfVexs(char vex, MGraph *MG)
{
    int i;
    for (i = 1; i <= MG->vexnum; i++) 
	{
        if (MG->vexs[i] == vex) 
		{
            return i;
        }
    }
    return 0;
}
 
//创建图
void create_MG(MGraph *MG) 
{
    int i, j, k;
    int v1, v2, type, t1, t2;
    int c1, c2;

    //printf("Please input vexmun : ");
    scanf("%d", &MG->vexnum);
    //printf("Please input arcnum : ");
    scanf("%d", &MG->arcnum);

    //printf("Please input graph type DG(0) or UDG(1) :");
    scanf("%d", &type);
    if (type == 1)
        MG->type = DG;
    else if (type == 0)
        MG->type = UDG;
    else 
	{
        //printf("Please input correct graph type DG(0) or UDG(1)!");
        return;
    }
 
    getchar();
    for (i = 1; i <= MG->vexnum; i++) 
	{
        //printf("Please input %dth vex(char):", i);
        scanf("%c", &MG->vexs[i]);
        getchar();
    }
 
    //初始化邻接矩阵
    for (i = 1; i <= MG->vexnum; i++) 
	{
        for (j = 1; j <= MG->vexnum; j++)
	   	{
            MG->arcs[i][j] = 0;
        }
    }
 
    //输入边的信息，建立邻接矩阵
    for (k = 1; k <= MG->arcnum; k++) {
        //printf("Please input %dth arc v1(char) v2(char) : ", k);
/*===============================if you input the index, just ignore this====================================*/
        // scanf("%c %c", &c1, &c2);
        // v1 = getIndexOfVexs(c1, MG);
        // v2 = getIndexOfVexs(c2, MG);
        scanf("%d %d", &t1, &t2);
        v1 = t1 + 1;
        v2 = t2 + 1;
        if (MG->type == 1)
            MG->arcs[v1][v2] = MG->arcs[v2][v1] = 1;
        else
            MG->arcs[v1][v2] = 1;
        getchar();
    }
}
/**
 * 打印邻接矩阵和顶点信息
 */
void print_MG(MGraph MG) 
{
    int i, j;
    // if(MG.type == DG)
	// {
    //     printf("Graph type : Direct graph:\n");
    // }
    // else
	// {
    //     printf("Graph type: Undirect graph:\n");
    // }
	// printf("Graph vertex number: %d \n",MG.vexnum);
    // printf("Graph arc number: %d \n",MG.arcnum);
 
    //printf("Vertex set:");
    // for (i = 1; i <= MG.vexnum; i++)
    //     printf("%c   ", MG.vexs[i]);
	// printf("\n");
    // printf("Adjacency Matrix:\n");
 
    for (i = 1; i <= MG.vexnum; i++) 
	{
        j = 1;
        for (; j < MG.vexnum; j++) 
		{
            printf("%d", MG.arcs[i][j]);
        }
		printf("%d", MG.arcs[i][j]);
		printf("\n");
    }
}
 

int main() 
{
    MGraph MG;
    create_MG(&MG);
    print_MG(MG);
    return 0;
}