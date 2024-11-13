#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100
typedef int DataType;
typedef struct {
    DataType data[MAXLEN];
    int front, rear;
}CirQueue;

void InitCirQueue(CirQueue *CQ)
{
    CQ->front = CQ->rear = 0;
}

int EmptyCirQueue(CirQueue *CQ)
{
    return CQ->front == CQ->rear;
}

int FullCirQueue(CirQueue *CQ)
{
    return (CQ->rear + 1) % MAXLEN == CQ->front;
}

void InsertCirQueue(CirQueue *CQ, DataType x)
{
    if((CQ->rear + 1) % MAXLEN == CQ->front)
    {
        printf("队列已满，无法入队！\n");
        exit(1);
    }
    else
    {
        CQ->rear = (CQ->rear + 1) % MAXLEN;
        CQ->data[CQ->rear] = x;
    }
}

DataType DeleteCirQueue(CirQueue *CQ, DataType x)
{
    if((CQ->front + 1) % MAXLEN == CQ->rear)
    {
        printf("队列为空，无法出队！\n");
        exit(1);
    }
    else
    {
        CQ->front = (CQ->front + 1) % MAXLEN;
        x = CQ->data[CQ->front];
        return x;
    }
}

void PrintCirQueue(CirQueue *CQ)
{
    int i = CQ->front;
    if((CQ->front + 1) % MAXLEN == CQ->rear)
    {
        printf("队列为空，无法读取！\n");
        exit(1);
    }
    else
    {
        while(i != CQ->rear)
        {
            i = (i + 1) % MAXLEN;
            printf("%d\t", CQ->data[i]);
        }
    }
}

int main()
{
    CirQueue NUM;
    InitCirQueue(&NUM);

    DataType nums[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        InsertCirQueue(&NUM, nums[i]);
    }

    PrintCirQueue(&NUM);

    return 0;
}