#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node{        // 结点类型定义
    DataType data;          // 结点的数据域
    struct node* next;      // 结点的指针域
}LinkNode, *LinkList;

// 初始化单链表
LinkList InitLinkList()
{
    LinkList L;
    L = (LinkNode*) malloc(sizeof(LinkNode));       // 为单链表头指针申请表头指针结点空间
    if(L == NULL)
    {
        printf("分配空间失败！\n");
        exit(1);
    }
    L->next = NULL;                                 // 头指针结点指针域设置为空
    return L;                                       // 返回单链表头指针
}

// 创建一个单链表(头插法)
LinkList CreateHeadLinkList(LinkList L)
{
    LinkNode* p;
    DataType x;
    int n;
    scanf("%d", &n);
    while(n)       // 当n为0时表示输入结束
    {
        scanf("%d", &x);
        p = (LinkNode*)malloc(sizeof(LinkNode));    // 为新结点申请空间并将地址存储在p中
        if(p == NULL)
        {
            printf("分配空间失败！\n");
            exit(1);
        }
        p->data = x;
        p->next = L->next;
        L->next = p;
        n--;
    }
    return L;               // 返回单链表头指针
}

// 创建一个单链表(尾插法)
LinkList CreateTailLinkList(LinkList L)         // 尾插法创建单链表
{
    DataType x;
    LinkNode *p, *t;
    t = L;
    int n;
    scanf("%d", &n);
    while(n)                           // 当n为0时表示输入结束
    {
        scanf("%d", &x);
        p = (LinkNode*)malloc(sizeof(LinkNode));    // 为新结点申请空间并将地址存储在p中
        if(p == NULL)
        {
            printf("分配空间失败！\n");
            exit(1);
        }
        p->data = x;
        p->next = t->next;          // 或者p->next = NULL;
        t->next = p;
        t = p;
        n--;
    }
    return L;                       // 返回表头指针
}

// 求单链表长度
int getLinkListLength(LinkList  L)
{
    int length = 0;
    LinkList p;
    p = L->next;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

// 获取单链表第i个元素指针
LinkList getLinkNode_1(LinkList L, int i)
{
    int j = 1;
    LinkNode* p;
    if(i < 1 || i > getLinkListLength(L))
    {
        printf("获取位置不正确！\n");
        exit(1);
    }
    p = L->next;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 获取单链表中值为e的第一个元素指针
LinkList getLinkNode_2(LinkList L, DataType e)
{
    LinkNode * p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 删除单链表中第i个元素
void deleteLinkNode(LinkList L, int i)
{
    LinkNode *p, *q;
    int j = 1;
    q = L;
    if(i < 1 || i > getLinkListLength(L))
    {
        printf("删除位置不正确！");
        exit(1);
    }
    while(j < i)
    {
        q = q->next;
        j++;
    }
    p = q->next;
    q->next = p->next;
    free(p);

}

// 输出单链表中的元素
void printLinkList(LinkList L)
{
    LinkNode* p;
    p = L->next;
    while(p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");

}


int main()
{

    LinkList num;
    num = InitLinkList();


    return 0;
}