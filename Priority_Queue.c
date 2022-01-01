#include <stdio.h>
#include "stdlib.h"
#include "Priority_Queue.h"


//typedef struct node {
//    int data;
//
//    // Lower values indicate higher priority
//    double weight;
//
//    struct node* next;
//
//} node;

// Function to Create A New Node
node* newNode(int d, double weight)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->weight = weight;
    temp->next = NULL;

    return temp;
}

// Return the value at head
void  peek(node** head,struct node* curr)
{
    curr->weight=(*head)->weight;
    curr->data=(*head)->data;
}

// Removes the element with the
// highest priority form the list
void pop(node** head)
{
    node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

// Function to push according to priority
void push(node** head, int d, double weight)
{
    node* start = (*head);

    // Create new Node
    node* temp = newNode(d, weight);
    if(*head==NULL){
        node *newhead =  newNode(d,weight);
        *head = newhead;
        return;

    }

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->weight > weight) {

        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {

        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->weight < weight) {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}
//struct node* getnode(struct node ** head,int data){
//    if(*head==NULL){
//        return NULL;
//    }
//    node * temp = *head;
//    while (temp!=NULL){
//        if(temp->data==data){
//            return temp;
//        }
//        temp = temp->next;
//    }
//    return NULL;
//
//}

// Function to check is list is empty
int isEmpty(node** head)
{
    return (*head) == NULL;
}