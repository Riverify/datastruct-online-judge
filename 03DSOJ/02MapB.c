#define _CRT_SECURE_NO_WARNINGS


//ͼ�����飨�ڽӾ��󣩴洢��ʾ
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
 
//��λ
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

//����ͼ
void create_MG(MGraph *MG) 
{
    //printf("Please input vexmun : ");
    scanf("%d", &MG->vexnum);
    //printf("Please input arcnum : ");
    scanf("%d", &MG->arcnum);

    int i, j, k;
    int v1, v2, type;
    int c1, c2;
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
 
    //��ʼ���ڽӾ���
    for (i = 1; i <= MG->vexnum; i++) 
	{
        for (j = 1; j <= MG->vexnum; j++)
	   	{
            MG->arcs[i][j] = 0;
        }
    }
 
    //����ߵ���Ϣ�������ڽӾ���
    for (k = 1; k <= MG->arcnum; k++) {
        //printf("Please input %dth arc v1(char) v2(char) : ", k);
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
 *  
 * ����ͼ��ӱ�Ľ���
 *  
 */
 void printTable(MGraph MG)
 {
    int i, j;
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