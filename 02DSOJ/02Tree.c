// By RiverLuo

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define MAX_SIZE 100

typedef char TElemType;

//二叉树的二叉链表的结点结构定义代码
typedef struct BTNode
{
	TElemType data;
	struct BTNode* lchild, * rchild;
}BTNode, * BTree, BinTreeNode;

BTree createBinTree_Sequence(); // 层次生成二叉树 (包含叶子节点的#)
BTNode* createBinTreeByGLists(); // 二叉树的广义表表示
void NoSpace(char *str); // 消除字符串的空格
void CreatBTree(BTree* T);// 前序遍历生成二叉树
void PrtOrderTraverse(BTree T);// 前序遍历二叉树
void InOrderTraverse(BTree T);// 中序遍历二叉树
void PostOrderTraverse(BTree T);// 后序遍历二叉树
int Deep(BTree T);// 求树的深度
int NodeCount(BTree T);// 求树的结点数
int LeafCount(BTree T);// 统计二叉树中叶子结点的个数
void PrtLeafNode(BTree T);// 打印输出所有二叉树叶子节点的值


int main()
{
	BTree T = NULL;
	T = createBinTreeByGLists();
    InOrderTraverse(T);
    printf("\n");
	return 0;
}

/*======================！CAUTION！=======================*/
//层次遍历生成二叉树 (包含叶子节点的#,即#表示叶子节点，而非空)
BTree createBinTree_Sequence(){
    TElemType temp_date;          //新建一个数据域变量
    BTree Queue[MAX_SIZE];     //创建结构体数组，用于模拟队列
    BTree temp;           //创建临时节点
    int head = 0;           //相当于头指针
    int tail = 0;           //相当于尾指针

    scanf("%c" , &temp_date);   //输入数据域
    BTree tmp = (BTree)malloc(sizeof(BTNode));  //创建头节点，分配内存

    if(temp_date == '#'){   //节点为空
    	tmp->data = '#';
    	tmp->lchild = NULL;
    	tmp->rchild = NULL;
    	return NULL;
    }else{                  //输入第一个节点
      	tmp->lchild = tmp->rchild = NULL;  
     	 tmp->data = temp_date;
      	Queue[tail++] = tmp;        //将当前头节点入队，并将尾指针+1
    }
    while(head<tail){               //判断队列不为空
    	scanf("%c" , &temp_date);   //输入左节点数据域
      	if(temp_date == '#'){         //左子树为空节点
        	temp = (BTNode*)malloc(sizeof(BTNode)); //分配内存
        	temp->data = '#';
    		temp->lchild = NULL;
        	temp->rchild = NULL;
        	Queue[head]->lchild = temp;
      	}else{                      //左子树不为空
        	temp = (BTNode*)malloc(sizeof(BTNode)); //分配内存
        	temp->lchild =  temp->rchild = NULL;
        	temp->data = temp_date;
        	Queue[head]->lchild = temp;     //将当前节点赋值给父节点
        	Queue[tail++] = temp;           //将当前头节点入队，并将尾指针+1
        }
        scanf("%c" , &temp_date);       //输入右节点，右子树与左子树一致
        if(temp_date == '#'){
          	temp = (BTNode*)malloc(sizeof(BTNode)); //分配内存
          	temp->data = '#';
          	temp->lchild = NULL;
          	temp->rchild = NULL;
          	Queue[head]->rchild = temp;
        }else{
          	temp = (BTNode*)malloc(sizeof(BTNode));
          	temp->lchild = temp->rchild = NULL;
          	temp->data = temp_date;
          	Queue[head]->rchild = temp;
          	Queue[tail++] = temp;
        }
      	head++;             //将父节点出队
    }
 	return tmp;
}


//=======================
// 下列遍历生生方法不包括‘#’
//=======================

// 二叉树的广义表表示
BTNode* createBinTreeByGLists() {
    int nodeQuantity = 0;
    char gLists[MAX_SIZE];
    scanf( "%[^\n]", gLists);

    NoSpace(gLists); // 消除空格
    
    int j = 0;
    while (gLists[j] != '\0') {
        if (gLists[j] != ',' && gLists[j] != '(' && gLists[j] != ')') {
            nodeQuantity++; 
        }
        j++;
    }

    //printf("%d\n", nodeQuantity);

    BinTreeNode *rootNode = NULL;
    BinTreeNode *currNode = NULL;

    //创建指针数组作为栈结构
    BinTreeNode **stack = (BinTreeNode **) malloc(sizeof(BinTreeNode *) * nodeQuantity);
    int top = -1;

    int flag = 0;
    const int START_LEFT_CHILD = 1, START_RIGHT_CHILD = 2;

    int index = 0;

    char c = gLists[index];

    while (c != '\0') {

        switch (c) {
            case '(':
                stack[++top] = currNode;
                flag = START_LEFT_CHILD;
                break;
            case ',':
                flag = START_RIGHT_CHILD;
                break;
            case ')':
                top--;
                break;
            case ' ':
                break;
            default:
                currNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
                currNode->data = c;
                currNode->lchild = currNode->rchild = NULL;

                if (rootNode == NULL) {
                    rootNode = currNode;
                } else {
                    switch (flag) {
                        case 1://START_LEFT_CHILD:
                            stack[top]->lchild = currNode;
                            break;
                        case 2://START_RIGHT_CHILD:
                            stack[top]->rchild = currNode;
                            break;
                    }
                }
        }

        c = gLists[++index];
    }

    //释放
    free(stack);

    return rootNode;
}

//前序遍历生成二叉树
void CreatBTree(BTree* T)
{
  	TElemType ch;
	scanf("%c ", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BTree)malloc(sizeof(BTNode));
		if (!*T)
			printf("失败\n");
		(*T)->data = ch;
		CreatBTree(&(*T)->lchild);//左子树
		CreatBTree(&(*T)->rchild);//右子树
	}
}

//前序遍历二叉树
void PrtOrderTraverse(BTree T)
{
	if (T == NULL)
	{	//printf("#");
		return;
	}
	printf("%c ", T->data);
	PrtOrderTraverse(T->lchild);
	PrtOrderTraverse(T->rchild);
}

//中序遍历二叉树
void InOrderTraverse(BTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->rchild);
}

//后序遍历二叉树
void PostOrderTraverse(BTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ", T->data);
}

int Deep(BTree T)
{
	if (T == NULL)
		return 0;
	else
	{
		int m = Deep(T->lchild);
		int n = Deep(T->rchild);
		if (m > n)
			return (m + 1);
		else
			return (n + 1);
	}
}

int NodeCount(BTree T)
{
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int LeafCount(BTree T)//统计二叉树中叶子结点的个数
{
	if (!T)
		return 0;
	if (!T->lchild && !T->rchild)//如果二叉树左子树和右子树皆为空,说明该二叉树根节点为叶子节点,加1.
	{
		return 1;
	}
	else
	{
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

void PrtLeafNode(BTree T) // 打印输出所有二叉树叶子节点的值
{
    // Todo: I don't know what to do actually
    // update: I made it!!!
    if (T->lchild == NULL && T->rchild == NULL)
	{	
        printf("# ");
		return;
	}
	PrtLeafNode(T->lchild);
	PrtLeafNode(T->rchild);
}

// 消除字符串的空格
void NoSpace(char str[])
{
	char *p=str;
	int i=0;
	while(*p)
	{
		if(*p!=' ')
			str[i++]=*p;
		p++;
	}
	str[i]='\0';
}
