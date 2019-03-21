#include "MatrixGraph.h"
#include "AdjListGraph.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
//    MatrixGraph mGraph;
//    if (CreateUDG(&mGraph) == ERROR)
//    {
//        printf("创建图失败，请检查后重试！\n");
//    return EXIT_FAILURE;
//    }
//    PrintMatGraph(&mGraph);
//    getchar();
    AdjListGraph G;
    if(CreateDN_AdjList(&G) == ERROR){
        printf("创建图失败，请检查后重试！\n");
        return EXIT_FAILURE;
    }
    PrintAdjListGraph(&G);
    return 0;
}