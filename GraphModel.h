//
// Created by longx on 2019/3/20.
//

#ifndef GRAPH001_GRAPHMODEL_H
#define GRAPH001_GRAPHMODEL_H

#define SUCCESS 1
#define ERROR   0
#define MAX_VERTEX 100

/** 图的类型枚举 */
typedef enum {
    DG,     //有向图
    UDG,    //无向图
    DN,     //有向网
    UDN     //无向网
}GraphKind;

/** 设置顶点的数据类型为char* */
typedef char* VerTexType;

/** 设置权值为整数类型 */
typedef int ArcType;

typedef int Status;

#endif //GRAPH001_GRAPHMODEL_H
