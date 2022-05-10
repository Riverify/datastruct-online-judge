/*  
*
*  银行家算法     
*  3种资源  5个进程
*
*  test1.c
*/
#include <stdio.h>

//可利用资源向量
int available[3]={3,3,2};
//最大需求矩阵
int max_r[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
//已分配矩阵
int allocation[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
//需求矩阵
int need[5][3]={{7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1}};

//标记是否有足够资源  1 TRUE；0 FALSE
int finish[5];


//打印系统当前资源信息
void printInfo()
{
	int i, j;

	printf("\n------------------------------------------------------------------------------------\n");  
	printf("当前资源剩余Available：");
    for(j = 0; j < 3; j++) {
        printf("%d ",available[j]);
    }
    printf("\n\n系统当前资源分配情况：\n");
    printf(" PID\t Max\t\tAllocation\t Need\n");
    for(i = 0; i < 5; i++) {
        printf(" P%d\t",i);
        for(j = 0; j < 3; j++) {
            printf("%2d",max_r[i][j]);
        }
        printf("\t\t");
        for(j = 0; j < 3; j++) {
            printf("%2d",allocation[i][j]);
        }
        printf("\t\t");
        for(j = 0; j < 3; j++) {
            printf("%2d",need[i][j]);
        }
        printf("\n");
    }
}

//打印执行安全性检查后的进程P[i]行
void printSafeInfo(int *p_work, int i)
{
    int j;
    printf(" P%d\t",i);
    for(j = 0; j < 3; j++) {
        printf("%2d", p_work[j]);
    }   
    printf("\t\t");
    for(j = 0; j < 3; j++) {
        printf("%2d", allocation[i][j]);
    }
	printf("\t\t");
    for(j = 0; j < 3; j++) {
        printf("%2d", need[i][j]);
    }
    printf("\t\t");
    for(j = 0; j < 3; j++) {
        printf("%2d", allocation[i][j] + p_work[j]);
    }
    printf("\t\t\t   %d", finish[i]);
    printf("\n");
}



//安全性算法     返回：1安全；0不安全
int isSafe()
{
	int safeSeries[5]={0,0,0,0,0};   //安全序列
    int work[3] = {0,0,0};           //工作向量
	    //其它局部变量

	
	//请补充完整安全性算法剩余部分




}


void main()
{
    int request[3];      //当前进程请求向量
	  //其它局部变量
    
    
	printInfo(); //开始先打印当前资源情况
	
    printf("\n安全性检查\n");
	printf(" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation\t\t Finish\n");
	while(!isSafe());//开始也要执行一次安全性算法，安全才能通过
    
	//请补充完整循环体
    while(1)
	{   
		
		


    }
}


