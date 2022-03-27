#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node* next;

} LinkList;


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

int main()
{
	LinkList* list = createList();

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		insertNodeByHead(list, data);
	}


	return 0;

}