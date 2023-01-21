#ifndef NODE_H
#define NODE_H

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data);

void destroyNode(struct node* link);
#endif