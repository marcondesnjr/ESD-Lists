#include <stdbool.h>
#include <stdio.h>
#include "Slist.h"



void main() {

	struct SList* slist = createList(10);
	insertFirst(slist,10);
	insertFirst(slist,20);
	insertFirst(slist,30);
	insertFirst(slist,1);
	insertFirst(slist,40);
	insertFirst(slist,56);
	insertLast(slist,70);

	printf("Original List: "); 
		
	//print list
	printList(slist);

	while(!isEmpty(slist)) {            
		int temp = deleteFirst(slist);
		printf("\nDeleted value:");
		printf("(%d) ",temp);
	}  
		
	printf("\nList after deleting all items: ");
	printList(slist);
	insertFirst(slist,10);
	insertFirst(slist,20);
	insertFirst(slist,30);
	insertFirst(slist,1);
	insertFirst(slist,40);
	insertFirst(slist,56);
	insertLast(slist,70);

	printf("\nRestored List: ");
	printList(slist);
	printf("\n");

	int foundLink = findNode(slist,4);
		
	if(foundLink != NULL) {
		printf("Element 4 found: ");
		printf("(%d) ", foundLink);
		printf("\n");  
	} else {
		printf("Element not found.");
	}

	deleteNode(slist,4);
	printf("List after deleting an item: ");
	printList(slist);
	printf("\n");
	foundLink = findNode(slist,4);
		
	if(foundLink != NULL) {
		printf("Element 4 found: ");
		printf("(%d) ", foundLink);
		printf("\n");
	} else {
		printf("Element not found.");
	}
    
}