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

//int Dijkstra (int src,int dest,struct NodeLinkedList *l) {
//    if (l->head == NULL) {
//        return -1;
//    }
//    SetValue(&l->head);
//    Node * srcNode  = getNode(l,src);
//    srcNode->weight = 0;
//    struct node *pq = newNode(srcNode->id, srcNode->weight);
//    struct node *curr = malloc(sizeof(struct node *));
//    while (!(isEmpty(&pq))) {
//        if (curr == NULL) {
//            return -1;
//        }
//        peek(&pq, curr);
//        struct Node *realNode = getNode(l, curr->data);
//        pop(&pq);
//        if (realNode != NULL) {
//            if (realNode->tag != 1) {
//                Edge *niber = getNode(l,curr->data)->neighbors;
//                while (niber != NULL) {
//                    if ((getNode(l, niber->dest)->tag) == 0) {
//                        int t = niber->weight + curr->weight;
//                        if (getNode(l, niber->dest)->weight > t) {
//                            getNode(l, niber->dest)->weight = t;
//                        }
//                        push(&pq, niber->dest, t);
//                    }
//                    niber = niber->next;
//                }
//            }
//            realNode->tag = 1;
//        }
//    }
//    if( getNode(l,dest)->weight==INT_MAX){
//        free(curr);
//        return -1;
//    }else{
//        free(curr);
//    return getNode(l,dest)->weight;
//}
//}
int Dijkstra (int src,int dest,struct NodeLinkedList *l) {
    if (l->head == NULL) {
        return -1;
    }
    SetValue(&l->head);
    Node * srcNode  = getNode(l,src);
    srcNode->weight = 0;
    NodeLinkedList help;
    init_LinkedList(&help);
    addNode(&help,-1);
    getNode(&help,-1)->weight = 0;
    getNode(&help,-1)->id = srcNode->id;
    while (help.head!=NULL) {
        Node *temp = help.head;
        int min= INT_MAX;
        int index =0;
        while (temp!=NULL){
            if(temp->weight<min){
                min = temp->weight;
                index = temp->id;
            }
            temp =temp->next;
        }
        removeNode(&help,index);
        struct Node *realNode = getNode(l,index);
        if (realNode != NULL) {
            if (realNode->tag != 1) {
                Edge *niber = getNode(l,realNode->id)->neighbors;
                while (niber != NULL) {
                    if ((getNode(l, niber->dest)->tag) == 0) {
                        int t = niber->weight + realNode->weight;
                        if (getNode(l, niber->dest)->weight > t) {
                            getNode(l, niber->dest)->weight = t;
                        }
                        addNode(&help,-1);
                        getNode(&help,-1)->weight=getNode(l, niber->dest)->weight;
                        getNode(&help,-1)->id=getNode(l, niber->dest)->id;
                    }
                    niber = niber->next;
                }

            }
            realNode->tag = 1;
        }
    }
    if( getNode(l,dest)->weight==INT_MAX){
        return -1;
    }else{
        return getNode(l,dest)->weight;
    }
}


void swap(int * a, int *b){
     int temp = *a;
     *a = *b;
     *b = temp;
}
void TSP(struct NodeLinkedList *l,int * arr,int len,int left,int right,int *minPath) {
    if (left==right) {
        int min = 0;
        int temp =0;
        for (int i = 0; i < len-1; ++i) {
            temp = Dijkstra(*(arr+i),*(arr+1+i),l);
            if(temp==-1){
                break;
            }
            min+= temp;
        }
        if(min!=0&&min<*minPath&&temp!=-1){
            *minPath=min;
        }
        return;
    }else {
        for(int i=left;i<=right;i++) {
            {

                swap( (arr+left), (arr+i));
                TSP(l,arr,len,left+1,right,minPath);
                swap( (arr+left), (arr+i));

            }
        }
    }
}

