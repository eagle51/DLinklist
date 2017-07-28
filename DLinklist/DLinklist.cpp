#include "DLinklist.h"
#include <stdio.h>
#include <stdlib.h>

PNode createDLinklist(int length)
{
	int data = 0;
	PNode pHead = (PNode)malloc(sizeof(Node));
	PNode pTail = NULL;

	if (pHead == NULL) {
		printf("内存分配失败！\n");
		exit(EXIT_FAILURE);
	}

	pHead->data = 0;
	pHead->pre = NULL;
	pHead->next = NULL;
	pTail = pHead;

	for (int i = 1;i <= length;++i) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL) {
			printf("内存分配失败！\n");
			exit(EXIT_FAILURE);
		}

		printf("请输出第%d个元素的值：", i);
		scanf_s("%d", &data);

		pNew->data = data;
		pNew->next = NULL;
		pNew->pre = pTail;
		pTail->next = pNew;
		pTail = pNew;
	}
	return pHead;
}

void traverseDLinklist(PNode pHead)
{
	PNode p = pHead;
	printf("遍历结果如下：\n");
	while (p->next != NULL)
	{
		printf("uuu  %d\n", p->next->data);
		p = p->next;
	}
}

bool isEmptyDLinklist(PNode pHead)
{
	if (pHead->next == NULL)
		return true;
	else
		return false;
}

int lengthDLinklist(PNode pHead)
{
	PNode p = pHead;
	int len = 0;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

int insertDLinklist(PNode pHead, int pos, int data)
{
	PNode p = NULL, pNew = NULL;
	if (pos > 0 && pos < lengthDLinklist(pHead) + 2) {
		pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL) {
			printf("内存分配失败!\n");
			exit(EXIT_FAILURE);
		}
		for (int i = 1;i < pos;++i) {
			pHead = pHead->next;
		}

		p = pHead->next;
		pNew->data = data;
		pNew->next = p;
		if (p != NULL)
			p->pre = pNew;
		pNew->pre = pHead;
		pHead->next = pNew;

		return 0;
	}
	else
		return -1;
}

int delDLinklist(PNode pHead, int pos)
{
	PNode p = NULL;
	if (pos > 0 && pos < lengthDLinklist(pHead) + 1) {
		for (int i = 1;i < pos;++i)
			pHead = pHead->next;

		p = pHead->next->next;
		free(pHead->next);
		pHead->next = p;
		if (p != NULL)
			p->pre = pHead;
		return 0;
	}
	else
		return -1;
}

void freeMemory(PNode * ppHead)
{
	PNode p = NULL;
	while (*ppHead != NULL) {
		p = (*ppHead)->next;
		free(*ppHead);
		if(p != NULL)
			p->pre = NULL;
		*ppHead = p;
	}
}