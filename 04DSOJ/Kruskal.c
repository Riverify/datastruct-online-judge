#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 16   
typedef char VexType;                     /*�������������*/
typedef int AdjType;            /*�ڽӾ��������Ԫ�ص�����*/
typedef struct
{
	VexType vexs[MAXVEX];				//����
	AdjType arcs[MAXVEX][MAXVEX];		//�ڽӾ���
	int n;								//��¼��ǰͼ�Ķ�����
	int e; //���� 
}GraphMatrix;

typedef struct treedata {
      char beg,en;   	/* beg,en�ǽ����� */
      int length;     	/* �߳� */
}edge;



GraphMatrix* CreateGraph(void)			//���������Ȩͼ
{
	int i,j,k,e,m;
	GraphMatrix *ga;
	ga=(GraphMatrix *)malloc(sizeof(GraphMatrix));
	printf("�����붥��ĸ���(������%d):",MAXVEX);
	scanf("%d",&(ga->n));
	getchar();

	printf("��˳���������������Ϣ(��ż���,��һ���ַ���ʾ):\n");
	for(i=0; i<ga->n; i++)
		ga->vexs[i]=getchar();     /*���붥����Ϣ�����������*/
	getchar();
	for(i=0; i<ga->n; i++)
		for(j=0; j<ga->n; j++){
			if(i==j) {
				ga->arcs[i][j]=0;
			} else {
				ga->arcs[i][j]=999;
			}
		}
			                /*�ڽӾ����ʼ��*/
	printf("������ߵĸ���:");
	scanf("%d",&e);
	ga->e = e;
	printf("����������������������������:\n");
	for(k=0;k<e;k++)
	{
		scanf("%d%d%d",&i,&j,&m);                         /*������Լ�Ȩֵ*/
		ga->arcs[i][j]=m;
		ga->arcs[j][i]=m;
	}
	getchar();
	return ga;
}



void PrintGraph(GraphMatrix *ga)
{
	int i,j;
	printf("\n�����Ϊ:\n");
	for(i=0; i<ga->n; i++)
		printf("%4c",ga->vexs[i]);
	printf("\n�ڽӾ���Ϊ:\n");
	for(i=0; i<ga->n; i++)
	{
		for(j=0; j<ga->n; j++)
			printf("%4d",ga->arcs[i][j]);
		printf("\n");
	}
}


int cmp(const void *a, const void *b)
{
	return (*(edge *)a).length - (*(edge *)b).length;
}

void kruskal(GraphMatrix *ga) {
	// �ڽӾ��� edge[] 
	edge arr[MAXVEX];
	int i=0,j;
	
	int p=0;
	for(i;i<ga->e;i++) {
		for(j=0;j<i;j++) {
			if(ga->arcs[i][j] != 0 && ga->arcs[i][j] != 999) {
				arr[p].beg = j;
				arr[p].en = i;
				arr[p].length = ga->arcs[i][j];
				p++;
			}
		}
	}
	
	// arr[] ����arr[].length ���� ��С����
	
	for(i=0;i<ga->e;i++) {
		printf("%c -> %c ֵΪ %d \n",ga->vexs[arr[i].beg],ga->vexs[arr[i].en],arr[i].length);
	}
	
	printf("����length �����:\n");
	
	qsort(arr, ga->e, sizeof(edge), cmp);
	
	for(i=0;i<ga->e;i++) {
		printf("%c -> %c ֵΪ %d \n",ga->vexs[arr[i].beg],ga->vexs[arr[i].en],arr[i].length);
	}
	// 2. ɸѡ��С�� �ж��Ƿ��ǻ�·��
	
	int e_flag = 0;
	// �������Ϊ (������-1) ����Ѱ��
	
	int end_index=0;
	int ends[ga->n];
	ends[end_index] = arr[0].en;
	printf("%c��%c\n",ga->vexs[arr[0].beg],ga->vexs[arr[0].en]);
	e_flag++;

	for(i=1;i<ga->e;i++) {
		
		int flag;
		for(j=0;j<=end_index;j++) {
			flag=0;
			// ���֮ǰ�߹������ ���γɻ�· �����������ߣ� 
			if (arr[i].en == ends[j]) {
				flag =1;
				break;
			}	
		}
		if(flag==0) {
			ends[++end_index] = arr[i].en;
			e_flag++;
			printf("%c��%c\n",ga->vexs[arr[i].beg],ga->vexs[arr[i].en]);
		}
		// ����Ϊ (������-1) ����Ѱ��
		if(e_flag == ga->n-1) {
			break;
		}
	} 
	
}


int main() {
	
	GraphMatrix *graph;
	graph = CreateGraph();
	PrintGraph(graph);
	kruskal(graph);
	return 0;
}
