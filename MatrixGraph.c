//
// Created by longx on 2019/3/20.
//

#include "MatrixGraph.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//创建无向图
Status CreateUDG(MatrixGraph * G)
{
    G->kind = UDG;      //设置当前创建图的类型为无向图
    printf("请输入无向图的顶点数：");
    scanf("%d",&G->verTexCount);
    printf("请输入边的数量：");
    scanf("%d",&G->arcCount);
    printf("依次输入顶点的信息\n");
    for (int i = 0; i < G->verTexCount; ++i) {
        G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->verTexs[i] != NULL);
        printf("顶点%d：",i + 1);
        scanf("%s",G->verTexs[i]);
    }

    //初始化邻接矩阵，所有边的权值设置为0
    for (int i = 0; i < G->verTexCount; ++i) {
        for (int j = 0; j < G->verTexCount; ++j) {
            G->arcs[i][j] = 0;
        }
    }
    printf("请输入顶点和邻接点信息，构建邻接矩阵\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->arcCount; ++i) {

        printf("顶点：");
        scanf("%s",vex1);
        printf("邻接点：");
        scanf("%s",vex2);

        //获得两个顶点在顶点数组中的坐标
        int x = LocateVex(G,vex1);
        int y = LocateVex(G,vex2);
        if(x == -1 || y == -1){
            return ERROR;
        }

        G->arcs[x][y] = 1;
        //无向图邻接矩阵是对称的
        G->arcs[y][x] = G->arcs[x][y];
    }
    free(vex1);
    free(vex2);
    return SUCCESS;
}


//创建有向图
Status CreateDG(MatrixGraph * G)
{
    G->kind = DG;      //设置当前创建图的类型为无向图
    printf("请输入有向图的顶点数：");
    scanf("%d",&G->verTexCount);
    printf("请输入边的数量：");
    scanf("%d",&G->arcCount);
    printf("依次输入顶点的信息\n");
    for (int i = 0; i < G->verTexCount; ++i) {
        G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->verTexs[i] != NULL);
        printf("顶点%d：",i + 1);
        scanf("%s",G->verTexs[i]);
    }

    //初始化邻接矩阵，所有边的权值设置为0
    for (int i = 0; i < G->verTexCount; ++i) {
        for (int j = 0; j < G->verTexCount; ++j) {
            G->arcs[i][j] = 0;
        }
    }
    printf("请输入顶点和邻接点信息，构建邻接矩阵\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->arcCount; ++i) {

        printf("顶点：");
        scanf("%s",vex1);
        printf("邻接点：");
        scanf("%s",vex2);

        //获得两个顶点在顶点数组中的坐标
        int x = LocateVex(G,vex1);
        int y = LocateVex(G,vex2);
        if(x == -1 || y == -1){
            return ERROR;
        }
        //有向图邻接矩阵可能是不对称的
        G->arcs[x][y] = 1;
    }
    free(vex1);
    free(vex2);
    return SUCCESS;
}

//返回某个顶点在顶点集合中的下标
int LocateVex(MatrixGraph * G,VerTexType vex)
{
   int index = 0;
   while (index < G->verTexCount){
       if(strcmp(G->verTexs[index],vex) == 0)
       {
           break;
       }
       index++;
   }
   return index == G->verTexCount ? -1 : index;
}
