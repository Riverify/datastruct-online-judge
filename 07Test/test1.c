/*  
*
*  ���м��㷨     
*  3����Դ  5������
*
*  test1.c
*/
#include <stdio.h>

//��������Դ����
int available[3]={3,3,2};
//����������
int max_r[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
//�ѷ������
int allocation[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
//�������
int need[5][3]={{7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1}};

//����Ƿ����㹻��Դ  1 TRUE��0 FALSE
int finish[5];


//��ӡϵͳ��ǰ��Դ��Ϣ
void printInfo()
{
	int i, j;

	printf("\n------------------------------------------------------------------------------------\n");  
	printf("��ǰ��Դʣ��Available��");
    for(j = 0; j < 3; j++) {
        printf("%d ",available[j]);
    }
    printf("\n\nϵͳ��ǰ��Դ���������\n");
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

//��ӡִ�а�ȫ�Լ���Ľ���P[i]��
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



//��ȫ���㷨     ���أ�1��ȫ��0����ȫ
int isSafe()
{
	int safeSeries[5]={0,0,0,0,0};   //��ȫ����
    int work[3] = {0,0,0};           //��������
	    //�����ֲ�����

	
	//�벹��������ȫ���㷨ʣ�ಿ��




}


void main()
{
    int request[3];      //��ǰ������������
	  //�����ֲ�����
    
    
	printInfo(); //��ʼ�ȴ�ӡ��ǰ��Դ���
	
    printf("\n��ȫ�Լ��\n");
	printf(" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation\t\t Finish\n");
	while(!isSafe());//��ʼҲҪִ��һ�ΰ�ȫ���㷨����ȫ����ͨ��
    
	//�벹������ѭ����
    while(1)
	{   
		
		


    }
}


