#include "stdlib.h"
#include "stdio.h"

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
DataType GetElem(SeqList* L,int i)
{
    if(i<1 || i > L->length)
    {
        printf("位置错误！\n");
        exit(0);
    }
    else
        return L->data[i-1];
}

// 按值查找
int LocalSeqList(SeqList* L, DataType x)
{
    int i = 0;
    while(i < L->length && L->data[i] != x)
        i++;
    if(i == L->length)
    {
        printf("要定位的元素不存在！\n");
        return -1;
    }else
    {
        return i + 1;
    }
}

// 元素的插入
void InsertSeqList(SeqList* L, DataType x, int i)
{
    int j;
    if(i < 1 || i > L->length + 1)
    {
        printf("position error");
        exit(1);
    }
    if(L->length == MAXLEN)
    {
        printf("overflow");
        exit(1);
    }
    for (j = L->length-1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = x;
    L->length++;
}

// 元素的删除
int DeleteSeqList(SeqList* L, int i)
{
    int k;
    int x;
    if(L->length == 0)
    {
        printf("线性表L为空！\n");
        return -1;
    }
    else if(i < 1 || i > L->length)
    {
        printf("要删除的数据元素不存在！\n");
        return -1;
    }
    else{
        x = L->data[i - 1];
        for (k = i; k < L->length; k++) {
            L->data[k - 1] = L->data[k];
        }
        L->length--;
    return x;
    }
}

// 打印输出
void PrintSeqList(SeqList* L)
{
    int i;
    if(L->length == 0)
        printf("线性表L为空！\n");
    else
        for (i = 0; i < L->length; i++) {
            printf("%d\t", L->data[i]);
        }
    printf("\n");
}


int main()
{


    return 0;
}