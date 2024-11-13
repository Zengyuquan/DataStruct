#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct qnode
{
    DataType data;
    struct qnode *next;
}QNode;

typedef struct
{
    QNode *front;
    QNode *rear;
}Queue, *QueueList;

QueueList InitNode()
{
    QNode *QN = (QNode *)malloc(sizeof(QNode));
    QueueList LQ = (Queue *)malloc(sizeof(Queue));
    QN->next = NULL;
    LQ->front = QN;
    LQ->rear = QN;
    return LQ;
}

int EmptyLinkQueue(QueueList LQ)
{
    return LQ->front == LQ->rear;
}

QueueList InsertLinkQueue(QueueList LQ, DataType x)
{
    QNode *p = (QNode *) malloc(sizeof(QNode));
    if(p == NULL)
    {
        printf("结点空间分配失败！\n");
        exit(1);
    }
    else
    {
        p->data = x;
        p->next = NULL;
        LQ->rear->next = p;
        LQ->rear = p;
        return LQ;
    }
}

QueueList DeleteLinkQueue(QueueList LQ)
{
    QNode *p;
    DataType x;
    if(LQ->front == LQ->rear)
    {
        printf("队列为空！\n");
        exit(1);
    }
    else
    {
        p = LQ->front->next;
        x = p->data;
        LQ->front->next = p->next;
        if(p->next == NULL)
            LQ->rear = LQ->front;
        free(p);
    }
    return LQ;
}

DataType GetHeadLinkQueue(QueueList LQ)
{
    if(LQ->front == LQ->rear)
    {
        printf("队列为空！\n");
        exit(1);
    }
    else
        return LQ->front->next->data;
}

void PrintLinkQueue(QueueList LQ)
{
    QNode *p;
    if(LQ->front == LQ->rear)
    {
        printf("队列为空！\n");
        exit(1);
    }
    else
    {
        p = LQ->front->next;
        while(p != LQ->rear->next)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    QueueList Num  = InitNode();

    Num = InsertLinkQueue(Num, 10);
    Num = InsertLinkQueue(Num, 20);
    Num = InsertLinkQueue(Num, 30);

    PrintLinkQueue(Num);

    return 0;
}