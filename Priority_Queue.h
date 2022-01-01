//#include <stdio.h>
//#include  <stdlib.h>

#ifndef EX4_2_PRIORITY_QEUE_H
#define EX4_2_PRIORITY_QEUE_H

typedef struct node {
    int data;

    // Lower values indicate higher priority
    int weight;

    struct node* next;

}node ;
struct node* newNode(int d, int p);
void peek( node** head,struct node * curr);
void pop(node** head);
void push(node** head, int d, int p);
int isEmpty(node** head);
struct node* getnode(struct node ** head,int data);





#endif //EX4_2_PRIORITY_QEUE_H