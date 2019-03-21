//
// Created by longx on 2019/3/21.
//

#include "AdjListGraph.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

//��ӡ�ڽӱ�
void PrintAdjListGraph(AdjListGraph * G)
{

    if(G->kind == UDG){
        printf("\n�ڽӱ�\n");
        for (int i = 0; i < G->vexCount; ++i) {
            VNode vNode = G->vexes[i];
            printf("����: %s", vNode.vex);
            EdgeNode *eNode = vNode.firstEdge;
            while (eNode) {
                printf(" -> %s", G->vexes[eNode->adjVex].vex);
                eNode = eNode->nextEdge;
            }
            printf("\n");
        }
        printf("\n");

    } else if(G->kind == DG || G->kind == DN){
        printf("\n�ڽӱ�\n");
        for (int i = 0; i < G->vexCount; ++i) {
            VNode vNode = G->vexes[i];
            ArcNode * arcNode = vNode.firstArc;
            printf("����: %s", vNode.vex);
            while (arcNode) {
                printf(" (%d)-> %s",
                       G->kind == DN ? arcNode->weight : 0,
                       G->vexes[arcNode->adjVex].vex);
                arcNode = arcNode->nextArc;
            }
            printf("\n");
        }
        printf("\n");

        printf("\n���ڽӱ�\n");
        for (int i = 0; i < G->vexCount; ++i) {
            VNode vNode = G->vexes[i];
            ArcNode *arcNode = vNode.firstEdge;
            printf("����: %s", vNode.vex);
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

//ʹ���ڽӱ��ʾ������������
Status CreateDN_AdjList(AdjListGraph * G)
{
    G->kind = DN;      //���õ�ǰ����ͼ������Ϊ����ͼ
    printf("����������ͼ�Ķ�������");
    scanf("%d",&G->vexCount);
    printf("�����뻡��������");
    scanf("%d",&G->edgeCount);
    printf("�������붥�����Ϣ\n");
    for (int i = 0; i < G->vexCount; ++i) {
        G->vexes[i].vex = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->vexes[i].vex != NULL);
        printf("����%d��",i + 1);
        scanf("%s",G->vexes[i].vex);
        //��ʼ���ڽӱ������ÿ�
        G->vexes[i].firstEdge = NULL;
        G->vexes[i].firstArc = NULL;
    }

    printf("�����붥����ڽӵ���Ϣ�������ڽӱ�\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->edgeCount; ++i) {

        int value = 0;
        printf("���㣺");
        scanf("%s",vex1);
        printf("�ڽӵ㣺");
        scanf("%s",vex2);
        printf("Ȩֵ��");
        scanf("%d",&value);

        //������������ڶ��������е�����
        int x = LocateVex_AdjList(G,vex1);
        int y = LocateVex_AdjList(G,vex2);
        if(x == -1 || y == -1){
            free(vex1);
            free(vex2);
            return ERROR;
        }
        //���ɱ߽����ڽӱ����ߣ�
        ArcNode * arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        assert(arcNode != NULL);
        arcNode->adjVex = y;
        arcNode->nextArc = G->vexes[x].firstArc;
        arcNode->weight = value;
        G->vexes[x].firstArc = arcNode;

        //���ɱ߽����ڽӱ���ߣ�
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

//��������ͼ_�ڽӱ�ʾ��
Status CreateUDG_AdjList(AdjListGraph * G)
{
    G->kind = UDG;      //���õ�ǰ����ͼ������Ϊ����ͼ
    printf("����������ͼ�Ķ�������");
    scanf("%d",&G->vexCount);
    printf("������ߵ�������");
    scanf("%d",&G->edgeCount);
    printf("�������붥�����Ϣ\n");
    for (int i = 0; i < G->vexCount; ++i) {
        G->vexes[i].vex = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->vexes[i].vex != NULL);
        printf("����%d��",i + 1);
        scanf("%s",G->vexes[i].vex);
        //��ʼ���ڽӱ������ÿ�
        G->vexes[i].firstEdge = NULL;
        G->vexes[i].firstArc = NULL;
    }

    printf("�����붥����ڽӵ���Ϣ�������ڽӱ�\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->edgeCount; ++i) {

        printf("���㣺");
        scanf("%s",vex1);
        printf("�ڽӵ㣺");
        scanf("%s",vex2);

        //������������ڶ��������е�����
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

        //�Գ���
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

//��������ͼ_�ڽӱ�ʾ��
Status CreateDG_AdjList(AdjListGraph * G)
{
    G->kind = DG;      //���õ�ǰ����ͼ������Ϊ����ͼ
    printf("����������ͼ�Ķ�������");
    scanf("%d",&G->vexCount);
    printf("�����뻡��������");
    scanf("%d",&G->edgeCount);
    printf("�������붥�����Ϣ\n");
    for (int i = 0; i < G->vexCount; ++i) {
        G->vexes[i].vex = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->vexes[i].vex != NULL);
        printf("����%d��",i + 1);
        scanf("%s",G->vexes[i].vex);
        //��ʼ���ڽӱ������ÿ�
        G->vexes[i].firstEdge = NULL;
        G->vexes[i].firstArc = NULL;
    }

    printf("�����붥����ڽӵ���Ϣ�������ڽӱ�\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->edgeCount; ++i) {

        printf("���㣺");
        scanf("%s",vex1);
        printf("�ڽӵ㣺");
        scanf("%s",vex2);

        //������������ڶ��������е�����
        int x = LocateVex_AdjList(G,vex1);
        int y = LocateVex_AdjList(G,vex2);
        if(x == -1 || y == -1){
            free(vex1);
            free(vex2);
            return ERROR;
        }
        //���ɱ߽����ڽӱ����ߣ�
        ArcNode * arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        assert(arcNode != NULL);
        arcNode->adjVex = y;
        arcNode->nextArc = G->vexes[x].firstArc;
        arcNode->weight = 0;
        G->vexes[x].firstArc = arcNode;

        //���ɱ߽����ڽӱ���ߣ�
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

//����ĳ�������ڶ��������е��±�
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