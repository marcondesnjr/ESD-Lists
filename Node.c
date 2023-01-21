#include <stdlib.h>
#include "Node.h"

struct node* createNode(int data){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = data;
	return link;
}

//Make sure the node is already deleted from the list
void destroyNode(struct node* link){
	free(link);
}