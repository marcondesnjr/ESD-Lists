#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"


struct List* createList(){
	struct List* list = (struct List*) malloc(sizeof(struct List));
	return list;
}

//display the list
void printList(struct List* list) {
   struct node *ptr = list->head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ", ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}


void insertFirst(struct List* list, int data) {
	//create a link
	struct node *link = createNode(data);
			
	//point it to old first node
	link->next = list->head;
		
	//point first to new first node
	list->head = link;
}

void insertLast(struct List* list, int data) {
	//create a link
	struct node *link = createNode(data);
		
	//get last node
	struct node* last = findNode(list, length(list)-1);

	if(isEmpty(list)){
		insertFirst(list, data);
	}else{
		//point the last node to it
		last->next = link;
	}
}

//delete first item
struct node* deleteFirst(struct List* list) {

	//save reference to first link
	struct node *tempLink = list->head;
		
	//mark next to first link as first 
	list->head = list->head->next;
		
	//return the deleted link
	return tempLink;
}

bool isEmpty(struct List* list) {
	return list->head == NULL;
}

int length(struct List* list) {
	int length = 0;
	struct node *current;
		
	for(current = list->head; current != NULL; current = current->next) {
		length++;
	}
		
	return length;
}

struct node* findNode(struct List* list,int key) {

	//start from the first link
	struct node* current = list->head;

	//if list is empty
	if(list->head == NULL) {
		return NULL;
	}

	//invalid key
	if(key >= length(list)){
		return NULL;
	}

	for(int i = 0; i < key; i++){
		current = current->next;
	}
		
	//return node
	return current;
}

struct node* deleteNode(struct List* list,int key) {

	//start from the first link
	struct node* current = list->head;
	struct node* previous = NULL;
		
	//if list is empty
	if(list->head == NULL) {
		return NULL;
	}
	//invalid key
	if(key >= length(list)){
		return NULL;
	}

	for(int i = 0; i < key; i++){
		previous = current;
		current = current->next;
	}

	//found a match, update the link
	if(current == list->head) {
		//change first to point to next link
		list->head = list->head->next;
	} else {
		//bypass the current link
		previous->next = current->next;
	}    
		
	return current;
}

void bubbleSort(struct List* list) 
{ 
    int i;
	bool swapped; 
    struct node* startPtr; 
    struct node* lastPtr = NULL; 
  
    //empty list
    if (list->head == NULL) 
        return; 
  
    do
    { 
        swapped = false; 
        startPtr = list->head; 
  
        while (startPtr->next != lastPtr) 
        { 
            if (startPtr->data > startPtr->next->data) 
            { 
                swap(startPtr, startPtr->next); 
                swapped = true; 
            } 
            startPtr = startPtr->next; 
        } 
        lastPtr = startPtr; 
    } 
    while (swapped); 
} 
  
//swap data
void swap(struct node* a, struct node* b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

int deleteValue(struct List* list, int key){
	if(list->head == NULL){
		exit(EXIT_FAILURE);
	}
	if(key == 0 ){
		struct node* link = deleteFirst(list);
		int value = link->data;
		destroyNode(link);
		return value;
	}else{
		struct node* link = deleteNode(list, key);
		int value = link->data;
		destroyNode(link);
		return link->data;
	}
};

int findValue(struct List* list, int key){
	return findNode(list, key)->data;
};

//middle between two elements
struct node* middle(struct node* start, struct node* last)
{
    if (start == NULL)
        return NULL;
  
    struct node* slow = start;
    struct node* fast = start -> next;
  
    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
  
    return slow;
}

struct node* binarySearch(struct List* list, int value)
{
    struct node* start =list->head;
    struct node* last = NULL;
  
    do
    {
        struct node* mid = middle(start, last);
  
        //empty
        if (mid == NULL){
            return NULL;
		}
        // found value
        if (mid -> data == value){
            return mid;
		}
        // more than mid
        else if (value > mid -> data){
            start = mid -> next;
		}
        //less than mid.
        else{
            last = mid;
		}

    } while (last == NULL ||
             last != start);
  
    // value not present
    return NULL;
}