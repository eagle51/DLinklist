#include "DLinklist.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	PNode head;
	if(!isEmptyDLinklist(head = createDLinklist(5)))
		printf("create success!\n");
	traverseDLinklist(head);
	printf("length: %d\n",lengthDLinklist(head));
	insertDLinklist(head, 1, 100);
	traverseDLinklist(head);
	insertDLinklist(head, 7,200);
	traverseDLinklist(head);
	insertDLinklist(head, 7,300);
	traverseDLinklist(head);
	delDLinklist(head, 1);
	traverseDLinklist(head);
	delDLinklist(head, 7);
	traverseDLinklist(head);
	delDLinklist(head, 3);
	traverseDLinklist(head);
	freeMemory(&head);
	if (head == NULL)
		printf("链表销毁成功！\n");
	else
		return -1;

	system("pause");
	return 0;
}