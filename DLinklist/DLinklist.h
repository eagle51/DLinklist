#ifndef __DLINK_LIST_H
#define __DLINK_LIST_H
typedef struct node {
	int data;
	struct node *next;
	struct node *pre;
}Node,*PNode;

PNode createDLinklist(int length);
void traverseDLinklist(PNode pHead);
bool isEmptyDLinklist(PNode pHead);
int lengthDLinklist(PNode pHead);
int insertDLinklist(PNode pHead,int pos,int data);
int delDLinklist(PNode pHead,int pos);
void freeMemory(PNode *ppHead);


#endif
