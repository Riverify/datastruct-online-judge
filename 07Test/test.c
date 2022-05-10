/*  
*
*  银行家算法     
*  3种资源  5个进程
*  20112001309-赵金鑫 
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
int work[3] = {0};
int p=0;
int a[100]={0};
 
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
    int i,j,s=0;
    int k=0;
    int safeSeries[5]={0,0,0,0,0};   //安全序列
    for(i=0;i<5;i++){
        finish[i]=0;
    }
    for(i=0;i<3;i++){
        work[i]=available[i];
    }
        //其它局部变量
    i=0;
    while(1){
            if(finish[i]==0){
                for(j=0;j<3;j++){
                    if(need[i][j]>work[j]){
                        break;
                    }
                }
                if(j>=3){
                    finish[i]=1; 
                    safeSeries[s]=i; 
                    s++;
                    printSafeInfo(work,i);
                    for(j=0;j<3;j++){
                        work[j]+=allocation[i][j];
                    }
                    k=0;
                }
                else {
                    k++;
                }
            }
            else{
                    k++;
            }
        i=(i+1)%5;
        if(k>=5){
            printf("\n当前系统不安全！\n\n"); 
            printf("分配失败！\n"); 
            return 0;
        }
        if(s==5)break;//安全 
    }
    printf("\n当前系统安全!\n\n");
    printf("安全序列为："); 
    for(i=0;i<5;i++){
        for(j=0;j<p;j++){
            if(safeSeries[i]==a[j])break;
        }
        if(j>=p) 
        printf("%d ",safeSeries[i]);
    } 
    //请补充完整安全性算法剩余部分
    return 1; 
}
 
 
void main()
{
    printf("20111304028罗健\n"); 
    int request[3];      //当前进程请求向量
    //其它局部变量
    int x;
    int i;
    int h;
    printInfo(); //开始先打印当前资源情况
    printf("\n安全性检查\n");
    printf(" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation\t\t Finish\n");
    while(!isSafe());//开始也要执行一次安全性算法，安全才能通过
    //请补充完整循环体
    while(1)
    {
        printf("\n------------------------------------------------------------------------------------\n\n"); 
        printf("20111304028罗健\n\n");    
        printf("输入要分配的进程：");
        scanf("%d",&x); 
        for(i=1;i<=3;i++){
            printf("请输入要分配给进程 P%d 的第 %d 类资源：",x,i);
            scanf("%d",&request[i-1]);
        }
        printf("\n");
        for(i=0;i<3;i++){
            if(request[i]>need[x][i]||request[i]>available[i])break;
        }
        if(i<3){
            printf("发生错误！可能原因如下：\n"); 
            printf("(1)您请求分配的资源可能大于该进程的某些资源的最大需求！\n"); 
            printf("(2)系统所剩的资源已经不足！\n"); 
        }
        else{
            int o=0;
            for(i=0;i<3;i++){
                available[i]-=request[i];
                allocation[x][i]+=request[i];
                need[x][i]-=request[i];
                if(need[x][i]==0)o++; 
            }
            if(o==3){
                a[p]=x;
                p++;
                printf("\n本次分配后进程%d执行完成!\n",x);
            }
            else{
                printf("\n本次分配后进程%d仍未完成!\n",x); 
            }
            if(p==5){
                printf("\n所有进程已完！！！！\n",x);
                break;
            }
            else{
                printf("\n安全性检查\n");
                printf(" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation\t\t Finish\n");
                h=isSafe();
                if(h==1&&o==3){
                    for(i=0;i<3;i++){
                        available[i]+=allocation[x][i];
                        allocation[x][i]=0;
                    }
                    printInfo();
                }
                else if(h==1){
                    printInfo();
                } 
                else{
                    available[i]+=request[i];
                    allocation[x][i]-=request[i];
                    need[x][i]+=request[i];
                }
            } 
             
        }
    }
}