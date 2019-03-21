//
// Created by longx on 2019/3/21.
//

#include "AdjListGraph.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

//打印邻接表
void PrintAdjListGraph(AdjListGraph * G)
{

    if(G->kind == UDG){
        printf("\n邻接表：\n");
        for (int i = 0; i < G->vexCount; ++i) {
            VNode vNode = G->vexes[i];
            printf("顶点: %s", vNode.vex);
            EdgeNode *eNode = vNode.firstEdge;
            while (eNode) {
                printf(" -> %s", G->vexes[eNode->adjVex].vex);
                eNode = eNode->nextEdge;
            }
            printf("\n");
        }
        printf("\n");

    } else if(G->kind == DG || G->kind == DN){
        printf("\n邻接表：\n");
        for (int i = 0; i < G->vexCount; ++i) {
            VNode vNode = G->vexes[i];
            ArcNode * arcNode = vNode.firstArc;
            printf("顶点: %s", vNode.vex);
            while (arcNode) {
                printf(" (%d)-> %s",
                       G->kind == DN ? arcNode->weight : 0,
                       G->vexes[arcNode->adjVex].vex);
                arcNode = arcNode->nextArc;
            }
            printf("\n");
        }
        printf("\n");

        printf("\n逆邻接表：\n");
        for (int i = 0; i < G->vexCount; ++i) {
            VNode vNode = G->vexes[i];
            ArcNode *arcNode = vNode.firstEdge;
            printf("顶点: %s", vNode.vex);
            while (arcNode) {
                printf(" <-(%d) %s",
                       G->kind == DN ? arcNode->weight : 0,
                       G->vexes[arcNode->adjVex].vex);
                arcNode = arcNode->nextEdge;
            }
            printf("\n");
        }
    }

}

//使用邻接表表示法创建有向网
Status CreateDN_AdjList(AdjListGraph * G)
{
    G->kind = DN;      //设置当前创建图的类型为无向图
    printf("请输入无向图的顶点数：");
    scanf("%d",&G->vexCount);
    printf("请输入弧的数量：");
    scanf("%d",&G->edgeCount);
    printf("依次输入顶点的信息\n");
    for (int i = 0; i < G->vexCount; ++i) {
        G->vexes[i].vex = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->vexes[i].vex != NULL);
        printf("顶点%d：",i + 1);
        scanf("%s",G->vexes[i].vex);
        //初始化邻接表，将边置空
        G->vexes[i].firstEdge = NULL;
        G->vexes[i].firstArc = NULL;
    }

    printf("请输入顶点和邻接点信息，构建邻接表\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->edgeCount; ++i) {

        int value = 0;
        printf("顶点：");
        scanf("%s",vex1);
        printf("邻接点：");
        scanf("%s",vex2);
        printf("权值：");
        scanf("%d",&value);

        //获得两个顶点在顶点数组中的坐标
        int x = LocateVex_AdjList(G,vex1);
        int y = LocateVex_AdjList(G,vex2);
        if(x == -1 || y == -1){
            free(vex1);
            free(vex2);
            return ERROR;
        }
        //生成边结点的邻接表（出边）
        ArcNode * arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        assert(arcNode != NULL);
        arcNode->adjVex = y;
        arcNode->nextArc = G->vexes[x].firstArc;
        arcNode->weight = value;
        G->vexes[x].firstArc = arcNode;

        //生成边结点的邻接表入边）
        EdgeNode * edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex = x;
        edgeNode->nextEdge = G->vexes[y].firstEdge;
        edgeNode->weight = value;
        G->vexes[y].firstEdge = edgeNode;

    }
    free(vex1);
    free(vex2);
    return SUCCESS;
}

//创建无向图_邻接表示法
Status CreateUDG_AdjList(AdjListGraph * G)
{
    G->kind = UDG;      //设置当前创建图的类型为无向图
    printf("请输入无向图的顶点数：");
    scanf("%d",&G->vexCount);
    printf("请输入边的数量：");
    scanf("%d",&G->edgeCount);
    printf("依次输入顶点的信息\n");
    for (int i = 0; i < G->vexCount; ++i) {
        G->vexes[i].vex = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->vexes[i].vex != NULL);
        printf("顶点%d：",i + 1);
        scanf("%s",G->vexes[i].vex);
        //初始化邻接表，将边置空
        G->vexes[i].firstEdge = NULL;
        G->vexes[i].firstArc = NULL;
    }

    printf("请输入顶点和邻接点信息，构建邻接表\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->edgeCount; ++i) {

        printf("顶点：");
        scanf("%s",vex1);
        printf("邻接点：");
        scanf("%s",vex2);

        //获得两个顶点在顶点数组中的坐标
        int x = LocateVex_AdjList(G,vex1);
        int y = LocateVex_AdjList(G,vex2);
        if(x == -1 || y == -1){
            free(vex1);
            free(vex2);
            return ERROR;
        }

        EdgeNode * edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        assert(edgeNode != NULL);
        edgeNode->adjVex = x;
        edgeNode->nextEdge = G->vexes[y].firstEdge;
        edgeNode->weight = 0;
        G->vexes[y].firstEdge = edgeNode;

        //对称性
        edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex = y;
        edgeNode->nextEdge = G->vexes[x].firstEdge;
        edgeNode->weight = 0;
        G->vexes[x].firstEdge = edgeNode;

    }
    free(vex1);
    free(vex2);
    return SUCCESS;
}

//创建有向图_邻接表示法
Status CreateDG_AdjList(AdjListGraph * G)
{
    G->kind = DG;      //设置当前创建图的类型为无向图
    printf("请输入无向图的顶点数：");
    scanf("%d",&G->vexCount);
    printf("请输入弧的数量：");
    scanf("%d",&G->edgeCount);
    printf("依次输入顶点的信息\n");
    for (int i = 0; i < G->vexCount; ++i) {
        G->vexes[i].vex = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->vexes[i].vex != NULL);
        printf("顶点%d：",i + 1);
        scanf("%s",G->vexes[i].vex);
        //初始化邻接表，将边置空
        G->vexes[i].firstEdge = NULL;
        G->vexes[i].firstArc = NULL;
    }

    printf("请输入顶点和邻接点信息，构建邻接表\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->edgeCount; ++i) {

        printf("顶点：");
        scanf("%s",vex1);
        printf("邻接点：");
        scanf("%s",vex2);

        //获得两个顶点在顶点数组中的坐标
        int x = LocateVex_AdjList(G,vex1);
        int y = LocateVex_AdjList(G,vex2);
        if(x == -1 || y == -1){
            free(vex1);
            free(vex2);
            return ERROR;
        }
        //生成边结点的邻接表（出边）
        ArcNode * arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        assert(arcNode != NULL);
        arcNode->adjVex = y;
        arcNode->nextArc = G->vexes[x].firstArc;
        arcNode->weight = 0;
        G->vexes[x].firstArc = arcNode;

        //生成边结点的邻接表入边）
        EdgeNode * edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode->adjVex = x;
        edgeNode->nextEdge = G->vexes[y].firstEdge;
        edgeNode->weight = 0;
        G->vexes[y].firstEdge = edgeNode;

    }
    free(vex1);
    free(vex2);
    return SUCCESS;
}

//返回某个顶点在顶点数组中的下标
int LocateVex_AdjList(AdjListGraph * G,VerTexType vex) {
    int index = -1;
    for (int i = 0; i < G->vexCount; ++i) {
        if (strcmp(vex, G->vexes[i].vex) == 0) {
            index = i;
            break;
        }
    }
    return index;
}