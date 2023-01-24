#ifndef SLIST_H
#define SLIST_H

struct SNode{
    int data;
};

struct SList{
    int* data;
    int maxSize;
    int lastIndex;
};

struct SList* createList();

void printList(struct SList* list);

void insertFirst(struct SList* list,int data);

void insertLast(struct SList* list,int data);

int deleteFirst(struct SList* list); 

bool isEmpty(struct SList* list);

int deleteNode(struct SList* list, int key);

int findNode(struct SList* list, int key); 

int length(struct SList* list);

//int deleteValue(struct List* list, int key);

//int findValue(struct List* list, int key); 

//void swap(struct node* a, struct node* b);

//void bubbleSort(struct List* list);

//struct node* binarySearch(struct SList* list, int value);
#endif