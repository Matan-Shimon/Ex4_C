#include <stdio.h>
#include "Priority_Queue.h"
#include "Graph.h"
#include "Graph_Algo.h"
#include <stdlib.h>
#include <limits.h>

int main() {
//    int bool_row = 0;
    char ch;
    ch = getchar();
    int bool = 0;


    struct NodeLinkedList node_list;
    while (ch != -1 && ch != '\n') {
        if (ch == 'A') {
            if (bool) {
                reboot_graph(&node_list);
                ch = getchar();
                ch = getchar();
                init_LinkedListbyNumber(&node_list, ch-48);
            }else {
                ch = getchar();
                ch = getchar();
                init_LinkedListbyNumber(&node_list, ch - 48);
                bool = 1;
            }
        } else if (ch == 'n') {
            int firstbool = 1;
            int secondbool = 1;
            int thirdbool = 1;
            int src;
            int dest;
            double weight;
            int i = 0;
            ch = getchar();
            while (ch != -1 && ch != '\n' && ch != 'B' && ch != 'D' && ch != 'S' && ch != 'T' && ch != 'n') {
                if (ch != ' ' && firstbool) {
                    src = ch - 48;
                    firstbool = 0;
                    ch = getchar();
                }
                if (ch != ' ' && secondbool) {
                    dest = ch - 48;
                    secondbool = 0;
                    thirdbool = 1;
                    ch = getchar();
                    i++;
                }
                if (ch != ' ' && thirdbool) {
                    weight = ch - 48;
                    thirdbool = 0;
                    secondbool = 1;
                    ch = getchar();
                    i++;
                }
                if (i != 0 && i % 2 == 0) {
                  addEdge(&node_list, src, dest, weight);

                }
                ch = getchar();

            }

        }else if(ch=='B') {
            int firstbool = 1;
            int secondbool = 1;
            int thirdbool = 1;
            int src;
            int dest;
            double weight;
            int i = 0;
            ch = getchar();
            while (ch != -1 && ch != '\n' && ch != 'B' && ch != 'D' && ch != 'S' && ch != 'T' && ch != 'n') {
                if (ch != ' ' && firstbool) {
                    src = ch - 48;
                    firstbool = 0;
                    addNode(&node_list,src);
                    ch = getchar();
                }
                if (ch != ' ' && secondbool) {
                    dest = ch - 48;
                    secondbool = 0;
                    thirdbool = 1;
                    ch = getchar();
                    i++;
                }
                if (ch != ' ' && thirdbool) {
                    weight = ch - 48;
                    thirdbool = 0;
                    secondbool = 1;
                    ch = getchar();
                    i++;
                }
                if (i != 0 && i % 2 == 0) {
                    addEdge(&node_list, src, dest, weight);
                }
                ch = getchar();

            }

        }else if(ch=='D') {
            int nodeNum;
            ch= getchar();
            ch =getchar();
            nodeNum= ch-48;
            removeNode(&node_list,nodeNum);
        }else if(ch =='T') {
            ch = getchar();
            ch = getchar();
            int munofNodes = ch - 48;
            int *arr = (int *) malloc(sizeof(int) * munofNodes);
            int i = 0;
            if (arr != NULL){
                while (ch != -1 && ch != '\n' && ch != 'B' && ch != 'D' && ch != 'S' && ch != 'T' && ch != 'n'&&i<munofNodes) {
                    ch = getchar();
                    if (ch != ' ' && ch != -1 && ch != '\n' && ch != 'B' && ch != 'D' && ch != 'S' && ch != 'T' &&
                        ch != 'n') {
                        ch = ch - 48;
                        arr[i] = ch;
                        i++;
                    }
                }
                int min = INT_MAX;
                TSP(&node_list, arr, munofNodes, 0, munofNodes - 1, &min);
//            if (bool_row) {
//                printf("\n");
//            }
                if (min == INT_MAX) {
                    printf("TSP shortest path: -1 \n");
                } else {
                    printf("TSP shortest path: %d \n", min);
                }
                free(arr);
//            bool_row = 1;
            }
        }
        else if(ch=='S'){
            int src ;
            int dest;
            ch =getchar();
            ch = getchar();
            src = ch-48;
            ch =getchar();
            ch = getchar();
            dest = ch-48;
            int shortDist = Dijkstra(src,dest,&node_list);
//            if (bool_row) {
//                printf("\n");
//            }
//            bool_row = 1;
            printf("Dijsktra shortest path: %d \n", shortDist);
        }else if (ch!='A'&&ch!='n'&&ch!='B'&&ch!='S'&&ch!='D'){
            ch = getchar();

        }

    }
    reboot_graph(&node_list);



}
