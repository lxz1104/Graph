#include "MatrixGraph.h"

#include <stdio.h>

int main() {
    MatrixGraph mGraph;
    if (CreateUDG(&mGraph) == ERROR)
    {
        printf("创建图失败，请检查后重试！\n");
    }
    printf("打印邻接矩阵:\n");
    printf("\t");
    for (int i = 0; i < mGraph.verTexCount; i++)
    {
        printf("\t%s", mGraph.verTexs[i]);
    }
    printf("\n");
    for (int i = 0; i < mGraph.verTexCount ; ++i)
    {
        printf("\t%s", mGraph.verTexs[i]);
        for (int j = 0; j < mGraph.verTexCount;++j)
        {
            printf("\t%d", mGraph.arcs[i][j]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}