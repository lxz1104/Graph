//
// Created by longx on 2019/3/20.
//

#ifndef GRAPH001_MATRIXGRAPH_H
#define GRAPH001_MATRIXGRAPH_H

#include "GraphModel.h"

/** 图的临接矩阵存储表示 */
typedef struct {
    VerTexType verTexs[MAX_VERTEX];             //顶点数字
    ArcType arcs[MAX_VERTEX][MAX_VERTEX];       //邻接矩阵（权数组）
    int verTexCount;                            //图的顶点数
    int arcCount;                               //图的边/弧数
    GraphKind kind;                             //图的类型
}MatrixGraph;

/**
 * 创建无向图
 * @param G 要操作的无向图指针
 * @return 创建成功，返回SUCCESS；创建失败，返回ERROR
 */
Status CreateUDG(MatrixGraph * G);

/**
 * 创建有向图
 * @param G 要操作的无向图指针
 * @return 创建成功，返回SUCCESS；创建失败，返回ERROR
 */
Status CreateDG(MatrixGraph * G);

/**
 * 返回某个顶点在顶点集合中的下标
 * @param G 要操作的无向图指针
 * @param vex 要定位的顶点
 * @return 存在，返回下标（从0开始）；不存在，返回-1
 */
int LocateVex(MatrixGraph * G,VerTexType vex);

/**
 *  打印邻接矩阵
 * @param G 要操作的无向图指针
 */
void PrintMatGraph(MatrixGraph * G);

#endif //GRAPH001_MATRIXGRAPH_H
