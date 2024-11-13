#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct stacknode{
    DataType data;
    struct stacknode* next;
}StackNode, *LinkStack;

LinkStack InitLinkStack()
{
    LinkStack top = NULL;
    return top;
}

int EmptyLinkStack(LinkStack top)
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

LinkStack PushLinkStack(LinkStack top, DataType x)
{
    StackNode *p = (StackNode *) malloc(sizeof(StackNode));
    if (p == NULL)
    {
        printf("结点空间申请失败！\n");
        exit(1);
    }
    else
    {
        p->data = x;
        p->next = top;
        top = p;
        return top;
    }
}

LinkStack PopLinkStack(LinkStack top)
{
    StackNode* p = top;
    if(p == NULL)
    {
        printf("栈为空！\n");
        exit(1);
    }
    else
    {
        DataType x = p->data;
        top = top->next;
        free(p);
        printf("出栈的元素为：%d\n", x);
        return top;
    }
}

DataType GetTopLinkStack(LinkStack top)
{
    if(top == NULL)
    {
        printf("栈为空！\n");
        exit(1);
    }
    else
        return top->data;
}

void  PrintLinkStack(LinkStack top)
{
    LinkStack p = top;
    if(p == NULL)
    {
        printf("栈为空！\n");
        exit(1);
    }
    else
    {
        while (p != NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    LinkStack num;
    num = InitLinkStack();

    int i;
    i = EmptyLinkStack(num);

    int nums[10] = {1,2,3,4,5,6,7,8,9,0};
    for (int j = 0; j < 10; j++) {
        num = PushLinkStack(num, nums[j]);
    }

    PrintLinkStack(num);

    return 0;
}