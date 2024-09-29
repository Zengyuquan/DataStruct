#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node{        // 结点类型定义
    DataType data;          // 结点的数据域
    struct node* next;      // 结点的指针域
}LinkNode, *LinkList;

LinkList InitLinkList()
{
    LinkList L;
    L = (LinkNode*) malloc(sizeof(LinkNode));       //
    if(L == NULL)
    {
        printf("分配空间失败！\n");
        exit(1);
    }
    L->next = NULL;                                 //
    return L;                                       //
}

int main()
{

    return 0;
}