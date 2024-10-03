## Sequence_List（顺序表）

### 顺序表的定义

```c
#define MAXLEN 100
typedef int DataType;
typedef struct {
    DataType data[MAXLEN];
    int length;
}SeqList;
```

1、首先定义一个顺序表最大长度的常量——MAXLEN为100。

2、typedef定义DataType为int型，为int起别名。

3、定义顺序表的结构体，并起别名为SeqList；定义顺序表采用静态分配内存空间，其类型为DataType（int）型的数组，数组长度为MAXLEN；同时也定义一个int型的变量——length来记录顺序表的实际表长。



### 顺序表的初始化

```c
void InitSeqList(SeqList* L)       //构造一个空的顺序表L
    {
    L->length = 0;                  //空表长度为0
}
```

1、定义一个InitSeqList()函数，形参是SeqList类型的指针L。

2、把顺序表的长度设置为0，表示顺序表存在，但目前没有参数，为空。



### 顺序表的建立

```c
void CreateSeqList(SeqList* L, int n)
{
    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]);
    }
    L->length = n;
}
```

1、定义一个CreateSeqList()函数，形参是SeqList类型的指针L和顺序表的长度n。

2、利用for循环，从键盘输入数据到顺序表；利用i的自增，从0开始到n-1结束，添加到顺序表中。

3、将输入的长度n赋值给length，来记录顺序表实时的长度。



### 顺序表的查找

#### 按元素位置查找

```c
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
```

1、定义一个GetElem()函数，形参是SeqList类型的指针L和希望查找的位置i。

2、利用if判断查找的位置是否合法，其合法范围是i大于或等于1且1小于或等于length，即顺序表实时的长度。所以if的判断条件是

```c
if(i<1 || i > L->length)
```

若查找的位置在范围内。则打印“位置错误！“，并执行exit(0)退出程序。

3、如果查找的位置合法，则返回i-1位置的元素；因为下标位置是从0开始的，所以i要减一才能准确表示出该位置的元素。



#### 按值查找

```c
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
```

1、定义一个LocalSeqList()函数，形参是SeqList类型的指针L和希望在顺序表中查找的值x。

2、定义一个int型变量i，利用while找出期望的值与顺序表中值的匹配情况；其查找的范围是i小于顺序表实时的长度，且判断顺序表中的元素是否匹配希望查找的值。若不匹配顺序表中的元素，则i++自增。

3、利用if判断i的情况，若i == L->length，则表示while循环到顺序表实时的长度，即顺序表中并没有匹配的值；打印”要定位的元素不存在！“返回-1，表示该元素不存在。

4、若在while循环中匹配到元素，则返回i+1的值；因为i为顺序表中的下标，而下标从0开始，要加一才能表示该数据元素所在的位置。



###  顺序表元素的插入

```c
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
```

1、定义一个InsertSeqList()函数，形参是SeqList类型的指针L和希望插入的值x，希望插入的位置i。

2、利用if判断插入的位置是否合法，其合法范围是i大于或等于1且1小于或等于length+1，即顺序表实时的长度。所以if的判断条件是

```c
if(i<1 || i > L->length + 1)
```

若插入的位置在范围内。则打印“position error“，并执行exit(1)退出程序。

3、第二个if判断顺序表实时的长度是否为MAXLEN顺序表最大长度，若为顺序表最大长度，则无法在插入元素（溢出），打印“overflow“，并执行exit(1)退出程序。

4、定义一个类型为int的变量j，并赋值为L -> length（顺序表实时的长度）- 1,表示最后一个元素的下标；利用for循环，判断条件是j >= i - 1，即到希望插入的位置的下标，j--自减。从顺序表实时的长度最后一个元素到希望插入的位置i的元素，依次往后移动一位：L->data[j + 1] = L->data[j];后，空出i-1的下标为插入元素x： L->data[i - 1] = x;

5、最后顺序表实时的长度自增加一。



### 顺序表元素的删除

```c
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
```

1、定义一个DeleteSeqList()函数，形参是SeqList类型的指针L和希望删除的位置i。

2、利用if循环判断顺序表实时的长度是否等于0，若等于0；则表示线性表为空，不能进行删除存操作；打印”线性表L为空！“返回-1，表示删除失败。

3、else if再判断删除的位置是否合法，其合法范围是i大于或等于1且1小于或等于length，即顺序表实时的长度。所以if的判断条件是

```c
if(i<1 || i > L->length)
```

若插入的位置在范围内。则打印“要删除的数据元素不存在！“，并返回-1，表示删除失败。

4、定义一个类型为int的变量x来存储删除的元素值。

5、如都不为非法条件则，定义一个类型为int的变量k，并赋值为i，即i为删除元素位置的下一个元素，利用for循环，判断条件是：

k < L->length，即到顺序表实时的长度最后一个元素，k++自增。从k开始，即删除元素位置的下一个元素，往前移动，覆盖删除元素的位置，以此类推到顺序表实时的长度最后一个元素：L->data[k - 1] = L->data[k];

6、5、最后顺序表实时的长度自减减一。

7、返回x，删除的元素值。



### 顺序表元素的输出打印

```c
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
```

1、定义一个DeleteSeqList()函数，形参是SeqList类型的指针L。

2、利用if判断顺序表是否为空，若为空，则无法输出打印元素，打印”线性表L为空！“。

3、若顺序表不为空，则用for循环遍历出顺序表中的值。









## Link_List（单链表）

### 链表的定义

```c
typedef int DataType;
typedef struct node{        // 结点类型定义
    DataType data;          // 结点的数据域
    struct node* next;      // 结点的指针域
}LinkNode, *LinkList;
```

1、typedef定义DataType为int型，为int起别名。

2、定义链表的结构体node，并起别名为LinkNode和LinkList的结构体指针；结构体中定义了两个变量，其中DataType data; 为链表的数据域，来存储结点的数据；而struct node* next;为链表的指针域，存储指向下一个结点的指针。



### 链表的初始化

为了操作的统一性，单链表的基本运算的实现都带头结点。

```c
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
```

1、定义一个InitLinkList()函数，无传入形参，返回L（头指针）。

2、定义一个LinkList类型的指针L，将作为头指针。

3、(LinkNode*) malloc(sizeof(LinkNode));	利用malloc函数分配，其大小为sizeof(LInkNode)，结构体的内存长度为16（64为操作系统中）；并用 (LinkNode\*)强转为LinkNode类型的指针，最后赋值给L。

4、利用if判断L是否为NULL；若为NULL，说明malloc内存地址分配失败，打印分配空间失败！，并执行exit(1)退出程序。

5、若malloc内存地址分配成功，则将头指针结点指针域设置为NULL，并将L返回。



### 链表的创建

#### 头插法

```c
LinkList CreateHeadLinkList(LinkList L)
{
    LinkNode* p;
    DataType x;
    scanf("%d", &x);
    while(x != 0)       // 0表示输入结束
    {
        p = (LinkNode*)malloc(sizeof(LinkNode));    // 为新结点申请空间并将地址存储在p中
        if(p == NULL)
        {
            printf("分配空间失败！\n");
            exit(1);
        }
        p->data = x;
        p->next = L->next;
        L->next = p;
        scanf("%d", &x);
    }
    return L;               // 返回单链表头指针
}
```









#### 尾插法

```c
LinkList CreateTailLinkList(LinkList L)         // 尾插法创建单链表
{
    DataType x;
    LinkNode *p, *t;
    t = L;
    scanf("%d", &x);
    while(x != 0)                           // 0表示输入结束
    {
        p = (LinkNode*)malloc(sizeof(LinkNode));    // 为新结点申请空间并将地址存储在p中
        if(p == NULL)
        {
            printf("分配空间失败！\n");
            exit(1);
        }
        p->data = x;                // 或者p->next = NULL;
        p->next = t->next;
        t->next = p;
        t = p;
        scanf("%d", &x);
    }
    return L;                       // 返回表头指针
}
```





