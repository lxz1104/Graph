//
// Created by longx on 2019/3/20.
//

#include "MatrixGraph.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//��������ͼ
Status CreateUDG(MatrixGraph * G)
{
    G->kind = UDG;      //���õ�ǰ����ͼ������Ϊ����ͼ
    printf("����������ͼ�Ķ�������");
    scanf("%d",&G->verTexCount);
    printf("������ߵ�������");
    scanf("%d",&G->arcCount);
    printf("�������붥�����Ϣ\n");
    for (int i = 0; i < G->verTexCount; ++i) {
        G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->verTexs[i] != NULL);
        printf("����%d��",i + 1);
        scanf("%s",G->verTexs[i]);
    }

    //��ʼ���ڽӾ������бߵ�Ȩֵ����Ϊ0
    for (int i = 0; i < G->verTexCount; ++i) {
        for (int j = 0; j < G->verTexCount; ++j) {
            G->arcs[i][j] = 0;
        }
    }
    printf("�����붥����ڽӵ���Ϣ�������ڽӾ���\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->arcCount; ++i) {

        printf("���㣺");
        scanf("%s",vex1);
        printf("�ڽӵ㣺");
        scanf("%s",vex2);

        //������������ڶ��������е�����
        int x = LocateVex(G,vex1);
        int y = LocateVex(G,vex2);
        if(x == -1 || y == -1){
            return ERROR;
        }

        G->arcs[x][y] = 1;
        //����ͼ�ڽӾ����ǶԳƵ�
        G->arcs[y][x] = G->arcs[x][y];
    }
    free(vex1);
    free(vex2);
    return SUCCESS;
}


//��������ͼ
Status CreateDG(MatrixGraph * G)
{
    G->kind = DG;      //���õ�ǰ����ͼ������Ϊ����ͼ
    printf("����������ͼ�Ķ�������");
    scanf("%d",&G->verTexCount);
    printf("������ߵ�������");
    scanf("%d",&G->arcCount);
    printf("�������붥�����Ϣ\n");
    for (int i = 0; i < G->verTexCount; ++i) {
        G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
        assert(G->verTexs[i] != NULL);
        printf("����%d��",i + 1);
        scanf("%s",G->verTexs[i]);
    }

    //��ʼ���ڽӾ������бߵ�Ȩֵ����Ϊ0
    for (int i = 0; i < G->verTexCount; ++i) {
        for (int j = 0; j < G->verTexCount; ++j) {
            G->arcs[i][j] = 0;
        }
    }
    printf("�����붥����ڽӵ���Ϣ�������ڽӾ���\n");
    VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
    VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
    assert(vex1 != NULL && vex2 != NULL);
    for (int i = 0; i < G->arcCount; ++i) {

        printf("���㣺");
        scanf("%s",vex1);
        printf("�ڽӵ㣺");
        scanf("%s",vex2);

        //������������ڶ��������е�����
        int x = LocateVex(G,vex1);
        int y = LocateVex(G,vex2);
        if(x == -1 || y == -1){
            return ERROR;
        }
        //����ͼ�ڽӾ�������ǲ��ԳƵ�
        G->arcs[x][y] = 1;
    }
    free(vex1);
    free(vex2);
    return SUCCESS;
}

//����ĳ�������ڶ��㼯���е��±�
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
