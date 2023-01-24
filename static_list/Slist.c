#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Slist.h"


struct SList* createList(int maxSize){
    struct SList* slist = malloc(sizeof(struct SList));
    slist->data = malloc(maxSize * sizeof(int));
    slist->maxSize = maxSize;
    slist->lastIndex = -1;
	return slist;
}

//display the list
void printList(struct SList* list) {
   printf("\n[ ");
	
   //start from the beginning
   for(int i = 0; i <= list->lastIndex; i++){
    	printf("(%d) ", list->data[i]);
   }
	
   printf(" ]");
}


void insertFirst(struct SList* list, int data) {
	if(isEmpty(list)){
		list->data[0] = data;
		list->lastIndex++;
	}else{
		for(int i = list->lastIndex; i >= 0; i--){
			list->data[i+1] = list->data[i];
		}
		list->data[0] = data;
		list->lastIndex++;

	}
}

void insertLast(struct SList* list, int data) {
	
    if(list->lastIndex == list->maxSize-1){
        printf("Cheio");
		exit(EXIT_FAILURE);
    }
	list->lastIndex++;
    
    //create a link
	list->data[list->lastIndex] = data;

}

//delete first item
int deleteFirst(struct SList* list) {
	int value = list->data[0];
	for(int i = 0; i < list->lastIndex; i++){
		list->data[i] = list->data[i+1];
	}
	//return the deleted link
	list->lastIndex--;
	return value;
}

bool isEmpty(struct SList* list) {
	return list->lastIndex == -1 || list->data == NULL;
}

int length(struct SList* list) {
	return list->lastIndex+1;
}

int findNode(struct SList* list,int key) {

	return list->data[key];
}

int deleteNode(struct SList* list,int key) {

	int value = list->data[key];

	for(int i = key; i < list->lastIndex; i++){
		list->data[i] = list->data[i+1];
	}
	list->lastIndex--;
	return value;
}

// void bubbleSort(struct List* list) 
// { 
//     int i;
// 	bool swapped; 
//     struct node* startPtr; 
//     struct node* lastPtr = NULL; 
  
//     //empty list
//     if (list->head == NULL) 
//         return; 
  
//     do
//     { 
//         swapped = false; 
//         startPtr = list->head; 
  
//         while (startPtr->next != lastPtr) 
//         { 
//             if (startPtr->data > startPtr->next->data) 
//             { 
//                 swap(startPtr, startPtr->next); 
//                 swapped = true; 
//             } 
//             startPtr = startPtr->next; 
//         } 
//         lastPtr = startPtr; 
//     } 
//     while (swapped); 
// } 
  
//swap data
// void swap(struct node* a, struct node* b) 
// { 
//     int temp = a->data; 
//     a->data = b->data; 
//     b->data = temp; 
// } 

// int deleteValue(struct List* list, int key){
// 	if(list->head == NULL){
// 		exit(EXIT_FAILURE);
// 	}
// 	if(key == 0 ){
// 		struct node* link = deleteFirst(list);
// 		int value = link->data;
// 		destroyNode(link);
// 		return value;
// 	}else{
// 		struct node* link = deleteNode(list, key);
// 		int value = link->data;
// 		destroyNode(link);
// 		return link->data;
// 	}
// };

// int findValue(struct List* list, int key){
// 	return findNode(list, key)->data;
// };

// //middle between two elements
// struct node* middle(struct node* start, struct node* last)
// {
//     if (start == NULL)
//         return NULL;
  
//     struct node* slow = start;
//     struct node* fast = start -> next;
  
//     while (fast != last)
//     {
//         fast = fast -> next;
//         if (fast != last)
//         {
//             slow = slow -> next;
//             fast = fast -> next;
//         }
//     }
  
//     return slow;
// }

// struct node* binarySearch(struct List* list, int value)
// {
//     struct node* start =list->head;
//     struct node* last = NULL;
  
//     do
//     {
//         struct node* mid = middle(start, last);
  
//         //empty
//         if (mid == NULL){
//             return NULL;
// 		}
//         // found value
//         if (mid -> data == value){
//             return mid;
// 		}
//         // more than mid
//         else if (value > mid -> data){
//             start = mid -> next;
// 		}
//         //less than mid.
//         else{
//             last = mid;
// 		}

//     } while (last == NULL ||
//              last != start);
  
//     // value not present
//     return NULL;
// }