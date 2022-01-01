#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//typedef struct Node {
//    int id;
//    double weight;
//    int tag;
//    struct Node * next;
//    struct Edge *neighbors;
//    int neighborsSize;
//}Node;
//
//typedef struct Edge {
//    double weight;
//    int tag;
//    int src;
//    int dest;
//    struct Edge *next;
//
//}Edge;
//
//typedef struct NodeLinkedList {
//    Node *head;
//}NodeLinkedList;


int addNode(struct NodeLinkedList *q, int id){
    Node * newnode = malloc(sizeof(struct Node));
    newnode->id = id;
    newnode->tag=0;
    newnode->weight=0;
    newnode->next=NULL;
    newnode->neighbors =NULL;
    newnode->neighborsSize=0;
    Node *temp = q->head;

    if(newnode==NULL){
        return 0;
    }
    while(temp!=NULL){
        if(temp->id==id&&temp->neighbors!=NULL){
            if(temp->neighborsSize==1){
                free(temp);
                temp->neighbors=NULL;
                temp->neighborsSize=0;
            }else {
                struct Edge *curr = temp->neighbors;
                struct Edge *next = temp->neighbors->next;
                while (next != NULL) {
                    curr = next;
                    next = next->next;
                    free(curr);
                }
            }
            temp->neighborsSize=0;
            temp->neighbors=NULL;
        }
        if(temp->next==NULL){
            temp->next=newnode;
            break;
        }
        temp =temp->next;
    }
    if(q->head==NULL){
        q->head = newnode;
    }
    return 1;
}

void init_LinkedList( struct NodeLinkedList *l) {
    l->head = NULL;
};
void init_LinkedListbyNumber(struct NodeLinkedList *l,int num){
    l->head = NULL;
    for (int i = 0; i < num; ++i) {
        addNode(l,i);

    }
}
struct Node * getNode ( struct NodeLinkedList *l, int id){
    Node *temp = l->head;
    while(temp!=NULL){
        //need to check if temp!=NULL instead
        if(temp->id==id){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


int addEdge(struct NodeLinkedList *q,int src, int dest,int weight){
    Edge * newedge = malloc(sizeof(struct Edge));
    struct Node *temp = getNode(q,src);
    struct Edge *tempE = temp->neighbors;
    newedge->src = src;
    newedge->dest = dest;
    newedge->tag=0;
    newedge->weight=weight;
    newedge->next=NULL;
    if(newedge==NULL){
        return 0;
    }
    while(tempE!=NULL){
        if(tempE->next==NULL){
            tempE->next=newedge;
            temp->neighborsSize++;
            break;
        }
        tempE =tempE->next;
    }
    if(tempE==NULL){
        temp->neighborsSize++;
        temp->neighbors=newedge;
    }
    return 1;
}

struct Edge  * getEdge  ( struct NodeLinkedList *l,int src,int dest){
    Edge * temp = malloc(sizeof(struct Edge));
    struct Node *node = getNode(l,src);
    if(node->neighbors==NULL){
        return NULL;
    }
    temp = node->neighbors;
    while(temp!=NULL){
        if(temp->dest==dest){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


struct Edge * getallEdgesOut( struct NodeLinkedList *l,int id){
    struct Edge * ans ;
    Edge * temp = malloc(sizeof(struct Edge));
    struct Node *node = getNode(l,id);
    ans = (struct Edge *)malloc(sizeof(struct Edge)*node->neighborsSize);
    if(node->neighbors==NULL) {
        return NULL;
    }
    temp = node->neighbors;
    int i=0;
    while(i<node->neighborsSize){
        ans[i] = *temp;
        temp = temp->next;
        i++;
    }
    return ans;

}

void removeEdge(struct NodeLinkedList *l,int src,int dest) {
    struct Node *node = getNode(l, src);
    struct Edge **niber = &node->neighbors;
    struct Edge *edge = getEdge(l, src, dest);
    struct Edge *temp = node->neighbors;
    if (niber == NULL || edge == NULL) {
        return;
    }
    if(temp->dest==dest){
        *niber=temp->next;
        node->neighborsSize--;
        free(temp);
        return;
    }
    while (*niber != NULL) {
        if ((*niber)->dest == dest) {
            *niber = temp->next;
            node->neighborsSize--;
            free(temp);
            break;
        }
        temp=temp->next;
        niber = &((*niber)->next);
    }
}

void removeNode(struct NodeLinkedList *l,int id) {
    struct Node *node = getNode(l, id);
    if (node == NULL) {
        printf("There's no such node.\n");
        return;
    }
    // deleting out edges
    if (node->neighborsSize != 0) {
        struct Edge **niber = &node->neighbors;
        struct Edge *temp = node->neighbors;
        while (temp != NULL) {
            *niber = temp->next;
            removeEdge(l, temp->src, temp->dest);
            temp = *niber;
        }
    }
    // deleting in edges
    Node* node1 = l->head;
    while (node1!=NULL) {
        Edge* edge1 = node1->neighbors;
        while (edge1!=NULL) {
            Edge* edge2 = edge1->next;
            if (edge1->dest == id) {
                removeEdge(l, edge1->src, edge1->dest);
            }
            edge1 = edge2;
        }
        node1 = node1->next;
    }
    Node **temp = &l->head;
    Node *temp2 = l->head;
    if (temp != NULL) {
        if (temp2->id == id) {
            *temp = temp2->next;
            free(temp2);
            return;
        }
        while (*temp != NULL) {
            if ((*temp)->id == id) {
                *temp = temp2->next;
                free(temp2);
                break;
            }
            temp2 = temp2->next;
            temp = &((*temp)->next);
        }
    }
}

void reboot_graph(NodeLinkedList *l) {
    Node *node = l->head;
    while (node!=NULL) {
        Edge *edge = node->neighbors;
        while (edge != NULL) {
            Edge *next = edge->next;
            removeEdge(l, edge->src, edge->dest);
            edge = next;
        }
        Node *node1 = node->next;
        removeNode(l, node->id);
        node = node1;
    }
}

void print_graph(NodeLinkedList* l) {
    Node *node = l->head;
    while (node!=NULL) {
        Edge *edge = node->neighbors;
        while (edge != NULL) {
            printf("src: %d, dest: %d, weight: %f\n", edge->src, edge->dest, edge->weight);
            edge = edge->next;
        }
        node = node->next;
    }
}

//int main () {
//    int len = 100;
//    char *str = (char *) calloc(100, sizeof(char));
//    int i = 0;
//    int ch;
//    while (ch != -1 && ch != '\n') {
//        ch = getchar();
//        str[i] = ch;
//        i++;
//        if (i == 100) {
//            str = (char *) realloc(str, len * 2 * sizeof(char));
//            len *= 2;
//        }
//    }
//    int bool = 0;
//    struct NodeLinkedList node_list;
//    for (int j = 0; j < i; j += 2) {
//        if (str[j] == 'A') {
//            if (bool) {
//                reboot_graph(&node_list);
//            }
//            bool = 1;
//        } else {
//            if (str[j - 2] == 'A') {
//                // num of nodes
//                str[j] = str[j] - 48;
//                init_LinkedListbyNumber(&node_list, str[j]);
//            } else {
//                if (str[j] == 'n') {
//                    int src_index = j + 2;
//                    str[src_index] = str[src_index] - 48;
//                    j += 4; // src
//                    while (str[j] != 'n' && str[j] != 'B' && str[j] != 'S' && str[j] != 'T' && j < i - 1) {
//                        str[j] = str[j] - 48;
//                        str[j + 2] = str[j + 2] - 48;
//                        addEdge(&node_list, str[src_index], str[j], str[j + 2]);
//                        j += 4;
//                    }
//                    j -= 2;
//                } else {
//                    if (str[j] == 'B') {
//
//                    }
//                }
//            }
//        }
//    }
//    print_graph(&node_list);