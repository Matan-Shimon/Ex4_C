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

int Dijkstra (int src,int dest,struct NodeLinkedList *l) {
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
                        int t = niber->weight + curr->weight;
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
//int main (){
//    NodeLinkedList l;
//    init_LinkedListbyNumber(&l,4);
//    addEdge(&l,0,1,1);
//    addEdge(&l,0,2,8);
//    addEdge(&l,0,3,7);
//    addEdge(&l,3,1,2);
//    addEdge(&l,1,2,21);
//    int arr[3] = {2,3,1};
//    int min = INT_MAX;
//    TSP(&l,arr,3,0,2,&min);
//    printf("%d",min);
//}

