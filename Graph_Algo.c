#include "Priority_Queue.h"
#include "Graph.h"
#include "Graph_Algo.h"
#include <stdio.h>
#include <limits.h>
#include "stdlib.h"

void SetValue(struct Node ** head){
    struct Node * temp = *head;
    while(temp!=NULL){
        temp->weight=INT_MAX;
        temp->tag=0;
        temp =temp->next;

    }

}

double Dijkstra (int src,int dest,struct NodeLinkedList *l) {
    if (l->head == NULL) {
        return -1;
    }
    SetValue(&l->head);
    Node * srcNode  = getNode(l,src);
    srcNode->weight = 0;
    struct node *pq = newNode(srcNode->id, srcNode->weight);
    while (!(isEmpty(&pq))) {
        struct node *curr = malloc(sizeof(struct node *));
        if (curr == NULL) {
            return -1;
        }
        peek(&pq, curr);
        struct Node *realNode = getNode(l, curr->data);
        pop(&pq);
        if (realNode != NULL) {
            if (realNode->tag != 1) {
                Edge *niber = getallEdgesOut(l, realNode->id);
                while (niber != NULL) {
                    if ((getNode(l, niber->dest)->tag) == 0) {
                        double t = niber->weight + curr->weight;
                        if (getNode(l, niber->dest)->weight > t) {
                            getNode(l, niber->dest)->weight = t;
                        }
                        push(&pq, niber->dest, t);
                    }
                    niber = niber->next;
                }
            }
            realNode->tag = 1;
        }
    }
    return getNode(l,dest)->weight;
}
double TSP(struct NodeLinkedList *l,int nodesNumber, int nodesArray []){
    return -1;
}

