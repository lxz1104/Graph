//
// Created by longx on 2019/3/21.
//

#ifndef GRAPH001_ADJLISTGRAPH_H
#define GRAPH001_ADJLISTGRAPH_H

#include "GraphModel.h"

/** 边/弧的结点 */
typedef struct node{
    int adjVex;                     //该边指向这条边邻接点的下标
    struct node * nextEdge;         //指向下一条边结点的指针
    struct node * nextArc;          //指向下一个弧结点的指针
    ArcType weight;                 //权重
}EdgeNode,ArcNode;

/** 顶点结点 */
typedef struct vexNode{
    VerTexType vex;             //顶点值
    EdgeNode * firstEdge;       //指向第一条边的指针
    ArcNode * firstArc;         //指向第一条弧的指针
}VNode,AdjList[MAX_VERTEX];


typedef struct adjGraph{
    AdjList vexes;              //邻接表数组
    int vexCount;               //顶点数量
    int edgeCount;          //图的边数
    int arcCount;           //图的弧数
    GraphKind kind;             //图的类型
}AdjListGraph;

/**
 * 创建无向图_邻接表示法
 * @param G 要操作的无向图指针
 * @return 创建成功，返回SUCCESS；创建失败，返回ERROR
 */
Status CreateUDG_AdjList(AdjListGraph * G);

/**
 * 创建有向图_邻接表示法
 * @param G 要操作的无向图指针
 * @return 创建成功，返回SUCCESS；创建失败，返回ERROR
 */
Status CreateDG_AdjList(AdjListGraph * G);

/**
 * 使用邻接表表示法创建有向网
 * @param G
 * @return
 */
Status CreateDN_AdjList(AdjListGraph * G);

/**
 * 返回某个顶点在顶点数组中的下标
 * @param G 要操作的无向图指针
 * @param vex 要定位的顶点
 * @return 存在，返回下标（从0开始）；不存在，返回-1
 */
int LocateVex_AdjList(AdjListGraph * G,VerTexType vex);

/**
 * 打印邻接表
 * @param G 要操作的无向图指针
 */
void PrintAdjListGraph(AdjListGraph * G);
#endif //GRAPH001_ADJLISTGRAPH_H
