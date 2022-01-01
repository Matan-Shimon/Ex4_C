//
// Created by orian on 30/12/2021.
//

#ifndef EX4_2_GRAPH_H
#define EX4_2_GRAPH_H

typedef struct Node {
    int id;
    int weight;
    int tag;
    struct Node * next;
    struct Edge *neighbors;
    int neighborsSize;
}Node;

typedef struct Edge{
    int  weight;
    int tag;
    int src;
    int dest;
    struct Edge * next;
}Edge;

typedef struct NodeLinkedList {
    Node *head;
}NodeLinkedList;
int addNode(struct NodeLinkedList *q, int id);
void init_LinkedList( struct NodeLinkedList *l);
void init_LinkedListbyNumber(struct NodeLinkedList *l,int num);
struct Node * getNode ( struct NodeLinkedList *l, int id);
int addEdge(struct NodeLinkedList *q,int src, int dest,int weight);
struct Edge  * getEdge  ( struct NodeLinkedList *l,int src,int dest);
struct Edge * getallEdgesOut( struct NodeLinkedList *l,int id);
void removeEdge(struct NodeLinkedList *l,int src,int dest);
void removeNode(struct NodeLinkedList *l,int id);
void reboot_graph(NodeLinkedList *l);
void print_graph(NodeLinkedList* l);


#endif //EX4_2_GRAPH_H