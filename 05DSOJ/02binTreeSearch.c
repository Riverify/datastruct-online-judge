//
// Created by river on 3/15/22.
//

#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree treenode;
typedef treenode *btree;

btree insertnode(btree root,int value) //插入新结点
{
    btree newnode;
    btree current;
    btree back;
    newnode=(btree)malloc(sizeof(treenode));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        return newnode;
    }
    else
    {
        current=root;
        while(current!=NULL)
        {
            back=current;
            if(current->data > value)
                current=current->left;
            else
                current=current->right;
        }
        if(back->data > value)
            back->left=newnode;
        else
            back->right=newnode;
    }
    return root;
}

btree createBtree(int *data,int len) //创建二叉排序树
{
    btree root=NULL;
    int i;
    for(i=0;i<len;i++)
    {
        root=insertnode(root,data[i]);
    }
    return root;
}

void searchParents(btree ptr, int search)
{
    if (ptr != NULL)
    {
        if (ptr->data == search) {
            printf("Success None\n");
            return;
        }
        else if ((ptr->left && ptr->left->data == search) || (ptr->right && ptr->right->data == search)) {
            printf("Success %d\n", ptr->data);
            return;
        }
            // else if (ptr->left == NULL && ptr->right == NULL) {
            //     printf("Failure\n");
            // }
        else {
            searchParents(ptr->left, search); 
            searchParents(ptr->right, search);
        }
    }
}

void preOrder(btree ptr) //前序遍历
{
    if(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void inOrder(btree ptr) //中序遍历
{
    if(ptr!=NULL)
    {
        inOrder(ptr->left);
        printf("%d ",ptr->data);
        inOrder(ptr->right);
    }
}

void postOrder(btree ptr) //后序遍历
{
    if(ptr!=NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ",ptr->data);
    }
}

int main()
{
    btree root=NULL;
    int len;
    scanf("%d", &len);
    int data[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &data[i]);
    }
    root=createBtree(data,len);
    int search;
    scanf("%d", &search);
    int flag = 0;
    for (int j = 0; j < len; j++) {
        if (data[j] == search) {
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("Failure\n");
    }
    searchParents(root, search);
    //printf("\n前序遍历序列: ");
    //preOrder(root);
    //printf("\n中序遍历序列: ");
    //inOrder(root);
    //printf("\n后序遍历序列: ");
    //postOrder(root);
    return 0;
}