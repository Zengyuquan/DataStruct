#include "stdio.h"

void PrintList(int data[], int length);

#define MAXLEN 100
typedef int DataType;
typedef struct {
    DataType data[MAXLEN];
    int length;
} SeqList;

// 初始化
void InitSeqList(SeqList* L) {
    L->length = 0;  // 空表长度为0
}

// 顺序表的建立
void CreateSeqList(SeqList* L, int n) {
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个元素: ", i + 1);
        scanf("%d", &L->data[i]);
    }
    L->length = n;
}

int main() {
    SeqList list;
    int n = 0;

    InitSeqList(&list);

    printf("请输入列表长度：");
    scanf("%d", &n);

    CreateSeqList(&list, n);

    PrintList(list.data, n);

    return 0;
}

void PrintList(int data[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}