#include "stdio.h"
#include "stdlib.h"

#define MAXLEN 100
typedef int DataType;
typedef struct{
    DataType data[MAXLEN];
    int top;
} SeqStack;
SeqStack SS;

void InitSeqStack(SeqStack *SS)
{
    SS->top = 0;
}

int EmptySeqStack(SeqStack *SS)
{
    if(SS->top == 0)
        return 1;
    else
        return 0;
}

int FullSeqStack(SeqStack *SS)
{
    if(SS->top == MAXLEN - 1)
        return 1;
    else
        return 0;
}

void PushSeqStack(SeqStack *SS, DataType  x)
{
    if(SS->top == MAXLEN - 1)
    {
        printf("栈已满，无法进栈！\n");
        exit(1);
    }
    else
    {
        SS->top++;
        SS->data[SS->top] = x;
    }
}

void PopSeqStack(SeqStack *SS, DataType *x)
{
    if(SS->top == 0)
    {
        printf("栈为空，无法出栈！\n");
        exit(1);
    }
    else
    {
        x = SS->data[SS->top];
        SS->top--;
    }
}

DataType getStack(SeqStack *SS)
{
    if(SS->top == 0)
    {
        printf("栈为空，不存在元素！\n");
        exit(1);
    }
    else
    {
        return SS->data[SS->top];
    }
}

int main()
{

    return 0;
}