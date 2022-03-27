#define _CRT_SECURE_NO_WARNINGS

#include <malloc.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node* next;

} LinkList;


// ALL INDEX START BY 1 !!!

LinkList* createList()
{
	LinkList* headNode = (LinkList*)malloc(sizeof(LinkList));
	// 初始化
	//headnode->data = 1;
	headNode->next = NULL;
	return headNode;
}

LinkList* createNode(int data)
{
	LinkList* newNode = (LinkList*)malloc(sizeof(LinkList));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int getListLength(LinkList* headNode)
{
	int length = 1;
	LinkList* pMove = headNode;
	while (pMove->next != NULL) {
		pMove = pMove->next;
		length++;
	}
	return length;
}

void insertNodeByHead(LinkList* headNode, int data)
{
	//创建插入的节点
	LinkList* newNode = createNode(data);
	newNode->next = headNode->next;   
	headNode->next = newNode;
}

void insertNodoInSpecificPlace(LinkList* headNode, int num, int data)
{
	//LinkList* node = createNode(data);
	LinkList* pMove = headNode;
	for (int i = 1; i < num; i++)
	{
		pMove = pMove->next;
	}
	insertNodeByHead(pMove, data);
}

void insertNodeByFoot(LinkList* headNode, int data)
{
	int length = getListLength(headNode);
	insertNodoInSpecificPlace(headNode, length, data);
}

void deleteIndex(LinkList* headNode, int num)
{
	LinkList* pMove = headNode->next;
	LinkList* fontPMove = headNode;
	for (int i = 0; i < num - 1; i++)
	{
		fontPMove = pMove;
		pMove = pMove->next;
	}
	fontPMove->next = pMove->next;
	free(pMove);

}


// infact equals index + 1
int getIndex(LinkList* headNode, int value) {
	LinkList* pMove = headNode->next;
	int index = 1;
	while (pMove->data != value) {
		pMove = pMove->next;
		index++;
	}
	return index;
}

int getValue(LinkList* headNode, int index)
{
	LinkList* pMove = headNode->next;
	for (int i = 0; i < index - 1; i++)
	{
		pMove = pMove->next;
	}
	return pMove->data;
}

void printList(LinkList* headNode)
{
	LinkList* pMove = headNode->next;
	while (pMove)
	{
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

void transposeList(LinkList* headNode, int start, int end)
{
    if (start >= end) {
        printf("Wrong start\n");
    }

    int count = 0;
    int mid;

    if ((start + end) % 2 != 0) { // 1 2 3 4 5 6
        mid = (start + end + 1) / 2;
    }
    else {
        mid = (start + end) / 2;
    }

    
    for (int i = start; i < mid; i++) {
        int temp1 = getValue(headNode, end - count);
        int temp2 = getValue(headNode, i);
        deleteIndex(headNode, i);
        insertNodoInSpecificPlace(headNode, i, temp1);
        deleteIndex(headNode, end - count);
        insertNodoInSpecificPlace(headNode, end - count, temp2);
        count++;
    }
}



int main()
{
	LinkList* list = createList();

	int n;
    int left, right;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		insertNodeByFoot(list, data);
	}


    scanf("%d %d", &left, &right);

    transposeList(list, left, right);

    printList(list);

	return 0;

}