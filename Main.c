#include <stdbool.h>
#include <stdio.h>
#include "List.h"
#include "Stack.h"
#include "Queue.h"



void main() {
	struct List* list = createList();
	insertFirst(list,10);
	insertFirst(list,20);
	insertFirst(list,30);
	insertFirst(list,1);
	insertFirst(list,40);
	insertFirst(list,56);
	insertLast(list,70);

	printf("Original List: "); 
		
	//print list
	printList(list);

	while(!isEmpty(list)) {            
		struct node *temp = deleteFirst(list);
		printf("\nDeleted value:");
		printf("(%d) ",temp->data);
	}  
		
	printf("\nList after deleting all items: ");
	printList(list);
	insertFirst(list,10);
	insertFirst(list,20);
	insertFirst(list,30);
	insertFirst(list,1);
	insertFirst(list,40);
	insertFirst(list,56);
	insertLast(list,70);

	printf("\nRestored List: ");
	printList(list);
	printf("\n");  

	struct node *foundLink = findNode(list,4);
		
	if(foundLink != NULL) {
		printf("Element 4 found: ");
		printf("(%d) ", foundLink->data);
		printf("\n");  
	} else {
		printf("Element not found.");
	}

	deleteNode(list,4);
	printf("List after deleting an item: ");
	printList(list);
	printf("\n");
	foundLink = findNode(list,4);
		
	if(foundLink != NULL) {
		printf("Element 4 found: ");
		printf("(%d) ", foundLink->data);
		printf("\n");
	} else {
		printf("Element not found.");
	}

	bubbleSort(list);
	printList(list);
	printf("\n");

	struct node* node = binarySearch(list,20);
	printf("Node 20 found: %d\n", 20);
		

    struct Queue* queue = createQueue();

    pushQueue(queue, 10);
    pushQueue(queue, 20);
    pushQueue(queue, 30);
    pushQueue(queue, 40);
    pushQueue(queue, 50);
    printList(queue->list);
    printf("\n");
    while (!isEmpty(queue->list)){
        popQueue(queue);
        printList(queue->list);
        printf("\n");
    }

    struct Stack* stack = createStack();

    pushStack(stack, 10);
    pushStack(stack, 20);
    pushStack(stack, 30);
    pushStack(stack, 40);
    pushStack(stack, 50);
    printList(stack->list);
    printf("\n");
    while (!isEmpty(stack->list)){
        popStack(stack);
        printList(stack->list);
        printf("\n");
    }
    
}