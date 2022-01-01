#include <stdio.h>
#include "Priority_Queue.h"
#include "Graph.h"
#include "Graph_Algo.h"
#include <stdlib.h>
#include <limits.h>

int main() {
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
        }else if(ch =='T'){
            ch =getchar();
            ch = getchar();
            int munofNodes = ch-48;
            int * arr = (int*) malloc(sizeof(int)*munofNodes);
            int i=0;
            while (ch != -1 && ch != '\n' && ch != 'B' && ch != 'D' && ch != 'S' && ch != 'T' && ch != 'n') {
                ch =getchar();
                if(ch!=' '&& ch != -1 && ch != '\n' && ch != 'B' && ch != 'D' && ch != 'S' && ch != 'T' && ch != 'n') {
                    ch = ch - 48;
                    arr[i] = ch;
                    i++;
                }
            }
            int min = INT_MAX;
            TSP(&node_list,arr,munofNodes,0,munofNodes-1,&min);
            if (min==INT_MAX){
                printf("TSP shortest path: -1\n");
            }else {
                printf("TSP shortest path: %d\n", min);
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
            double  shortDist = Dijkstra(src,dest,&node_list);
            printf("Dijsktra shortest path: %d\n", shortDist);
        }else if (ch!='A'&&ch!='n'&&ch!='B'&&ch!='S'&&ch!='D'){
            ch = getchar();

        }

    }

//    print_graph(&node_list);
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
//                    while (str[j] != 'n' && str[j] != 'B' && str[j] != 'S' && str[j] != 'T' && j < i) {
//                        str[j] = str[j] - 48;
//                        str[j + 2] = str[j + 2] - 48;
//                        addEdge(&node_list, str[src_index], str[j], str[j + 2]);
//                        j += 4;
//                    }
//                    j -= 2;
//                }
//            }
//        }
//    }
//    print_graph(&node_list);
//}