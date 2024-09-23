#include <process.h>
#include "stdio.h"

void PrintList(int data[],int length);

#define MAXLEN 100
typedef int DataType;
typedef struct {
    DataType data[MAXLEN];
    int length;
}SeqList;

// 初始化
void InitSeqList( SeqList* L)       //构造一个空的顺序表L
{
    L->length = 0;                  //空表长度为0
}

// 顺序表的建立
void CreateSeqList(SeqList* L, int n)
{
    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]);
    }
    L->length = n;
}

// 按元素位置查找
DataType CetElem(SeqList* L,int i)
{
    if(i<1 || i > L->length)
    {
        printf("位置错误！\n");
        exit(0);
    }
    else
        return L->data[i-1];
}


int main()
{

    SeqList list;
    int n = 0;

    InitSeqList(&list);

    scanf("%d", &n);

    CreateSeqList(&list, n);

//    PrintList(list.data, n);



    return 0;
}

void PrintList(int data[],int length)
{
    printf("列表为：");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
}