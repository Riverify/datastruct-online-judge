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
    int v1, v2, type;
    int c1, c2;
    printf("Please input graph type DG(0) or UDG(1) :");
    scanf("%d", &type);
    if (type == 0)
        MG->type = DG;
    else if (type == 1)
        MG->type = UDG;
    else 
	{
        printf("Please input correct graph type DG(0) or UDG(1)!");
        return;
    }
 
    printf("Please input vexmun : ");
    scanf("%d", &MG->vexnum);
    printf("Please input arcnum : ");
    scanf("%d", &MG->arcnum);
    getchar();
    for (i = 1; i <= MG->vexnum; i++) 
	{
        printf("Please input %dth vex(char):", i);
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
        printf("Please input %dth arc v1(char) v2(char) : ", k);
/*===============================if you input the index, just ignore this====================================*/
        // scanf("%c %c", &c1, &c2);
        // v1 = getIndexOfVexs(c1, MG);
        // v2 = getIndexOfVexs(c2, MG);
/*==========================================================================================================*/
        /*======CAUTION: v1 and v2 start from 0, not 1  !!!!!!!!!=======*/
        scanf("%d %d", &v1, &v2);
        
        if (MG->type == 1)
            MG->arcs[v1 + 1][v2 + 1] = MG->arcs[v2 + 1][v1 + 1] = 1;
        else
            MG->arcs[v1 + 1][v2 + 1] = 1;
        getchar();
    }
}
/**
 * 打印邻接矩阵和顶点信息
 */
void print_MG(MGraph MG) 
{
    int i, j;
    if(MG.type == DG)
	{
        printf("Graph type : Direct graph:\n");
    }
    else
	{
        printf("Graph type: Undirect graph:\n");
    }
	printf("Graph vertex number: %d \n",MG.vexnum);
    printf("Graph arc number: %d \n",MG.arcnum);
 
    printf("Vertex set:");
    for (i = 1; i <= MG.vexnum; i++)
        printf("%c   ", MG.vexs[i]);
	printf("\n");
    printf("Adjacency Matrix:\n");
 
    for (i = 1; i <= MG.vexnum; i++) 
	{
        j = 1;
        for (; j < MG.vexnum; j++) 
		{
            printf("%d   ", MG.arcs[i][j]);
        }
		printf("%d   ", MG.arcs[i][j]);
		printf("\n");
    }
}

/**
 *  
 * 无向图领接表的建立
 *  
 */
 void printTable(MGraph MG)
 {
    int i, j;
    if(MG.type == DG)
	{
        printf("Graph type : Direct graph:\n");
    }
    else
	{
        printf("Graph type: Undirect graph:\n");
    }

    printf("Graph vertex number: %d \n",MG.vexnum);
    printf("Graph arc number: %d \n",MG.arcnum);

    for (i = 1; i <= MG.vexnum; i++) {
        printf("%c", MG.vexs[i]);
        j = MG.vexnum;
        for (; j > 0; j--) {
            if (MG.arcs[i][j] == 1) {
            printf("%c", MG.vexs[j]);
            }
        }
        printf("\n");
    }
 }
 

int main() 
{
    MGraph MG;
    create_MG(&MG);
    printTable(MG);
    return 0;
}