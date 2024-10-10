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

2、利用if判断查找的位置是否合法，其合法范围是i大于或等于1且i小于或等于length，即顺序表实时的长度。所以if的判断条件是

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

3、利用if判断i的情况，若i == L->length，则表示while循环到顺序表实时的长度，即顺序表中并没有匹配的值；打印“要定位的元素不存在！”返回-1，表示该元素不存在。

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

2、利用if判断插入的位置是否合法，其合法范围是i大于或等于1且i小于或等于length+1，即顺序表实时的长度。所以if的判断条件是

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

3、else if再判断删除的位置是否合法，其合法范围是i大于或等于1且i小于或等于length，即顺序表实时的长度。所以if的判断条件是

```c
if(i<1 || i > L->length)
```

若删除的位置在范围内。则打印“要删除的数据元素不存在！“，并返回-1，表示删除失败。

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

1、定义一个PrintSeqList()函数，形参是SeqList类型的指针L。

2、利用if判断顺序表是否为空，若为空，则无法输出打印元素，打印”线性表L为空！“。

3、若顺序表不为空，则用for循环遍历出顺序表中的值。









## Link_List（单链表）

### 单链表的定义

```c
typedef int DataType;
typedef struct node{        // 结点类型定义
    DataType data;          // 结点的数据域
    struct node* next;      // 结点的指针域
}LinkNode, *LinkList;
```

1、typedef定义DataType为int型，为int起别名。

2、定义链表的结构体node，并起别名为LinkNode和LinkList的结构体指针（通常用于表示链表的头指针）；结构体中定义了两个变量，其中DataType data 为链表的数据域，用来存储结点的数据；而struct node* next;为链表的指针域，存储指向下一个结点的指针。



### 单链表的初始化

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

3、(LinkNode*) malloc(sizeof(LinkNode));	利用malloc函数分配地址空间，其大小为sizeof(LInkNode)，结构体的内存长度为16（64为操作系统中）；并用 (LinkNode\*)强转为LinkNode类型的指针，最后赋值给L。

4、利用if判断L是否为NULL；若为NULL，说明malloc内存地址分配失败，打印“分配空间失败！"，并执行exit(1)退出程序。

5、若malloc内存地址分配成功，则将头指针结点指针域设置为NULL，并将L返回。



### 单链表的创建

#### 头插法

```c
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
```

1、定义一个CreateHeadLinkList()函数，形参是LinkList L（链表的头指针地址），最终返回头指针LinkList L。

2、定义一个LinkNode* p指针变量用来指向新开辟的地址空间，定义DataType x来存储从键盘输入的数据，int n接收来着键盘输入希望插入接点个数的值。

3、利用while循环n次为单链表的数据域赋值；(LinkNode*)malloc(sizeof(LinkNode))分配一片地址空间，并把指针地址赋值给p指针变量。if判断地址分配是否成功，若不成功，则打印“分配空间失败！”，并执行exit(1) 退出程序。

4、如果分配成功内存地址，则将x的值赋值给该结点的数据域；将L->next原本所指向的下一个结点指针域赋值给p的指向的下一个结点指针域；再将p指针赋值给L->next向的下一个结点的指针域；如此循环完成头插法插入。

5、最后i自减，返回L头指针。





#### 尾插法

```c
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
        p->next = t->next;			// 或者p->next = NULL;
        t->next = p;
        t = p;
        n--;
    }
    return L;                       // 返回表头指针
}
```

1、定义一个CreateTailLinkList()函数，形参是LinkList L（链表的头指针地址），最终返回头指针LinkList L。

2、定义一个LinkNode* p指针变量用来指向新开辟的地址空间；一个LinkNode* t 指针变量来记录头指针地址；定义DataType x来存储从键盘输入的数据，int n接收来着键盘输入希望插入接点个数的值。

3、利用while循环n次为单链表的数据域赋值；(LinkNode*)malloc(sizeof(LinkNode))分配一片地址空间，并把指针地址赋值给p指针变量。if判断地址分配是否成功，若不成功，则打印“分配空间失败！”，并执行exit(1) 退出程序。

4、如果分配成功内存地址，则将x的值赋值给该结点的数据域；将t->next赋值给p的指向的下一个结点指针域，也等同于或者p->next = NULL；再将p指针赋值给t->next指向的下一个结点的指针域；最后将p指针赋值给t指针，t指针又指向最后一个结点；如此循环完成尾插法插入。

5、最后i自减，返回L头指针。



### 求单链表长度

```c
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
```

1、定义一个getLinkListLength()函数，形参是LinkList L（链表的头指针地址），最终返回求得的单链表长度length。

2、定义一个int length变量并赋值为0，负责接收所求单链表长度；LinkList p指针变量接收L头指针指向的下一个结点指针。

3、利用while循环，判断条件是p指针是否为0，为0则退出循环。不为0执行循环体内的语句，length++自增，并把p指向的下一个指针赋值给p，起到移动p指针的作用。

4、最后将得到的length返回。



### 获取单链表第i个元素指针

```c
LinkList getLinkNode_1(LinkList L, int i)
{
    int j = 1;
    LinkNode* p;
    if(i < 1 || i > getLinkListLength(L))
    {
        printf("获取位置不正确！");
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
```

1、定义一个getLinkNode_1()函数，形参是LinkList L（链表的头指针地址），int i希望获取的第i个结点的元素指针，返回p指针。

2、定义int j = 1，作为一个计数器，初始值为1，用于统计单链表中的结点数；LinkNode* p被赋值L头指针的下一个结点指针。

3、利用if判断i获取的位置是否合法，其合法范围是i大于或等于1且i小于或等于getLinkListLength(L)，调取getLinkListLength()函数得到单链表的长度；所以if的判断条件是

```c
if(i < 1 || i > getLinkListLength(L))
```

若获取的位置在范围内。则打印“查找位置不正确！”，并执行exit(1)退出程序。

4、将L头指针指向的下一个结点指针赋值给p。

5、利用while循环，移动p指针指向的地址，并执行j++统计单链表结点数量；其判断条件是p所指向的指针不为空，若为空，则到链表的尾结点；且j的值小于i，即找到i结点。

6、最终将找到的该结点地址返回。



### 获取单链表中值为e的第一个元素指针

```c
LinkList getLinkNode_2(LinkList L, DataType e)
{
    LinkNode * p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
```

1、定义一个getLinkNode_2()函数；形参是LinkList L（链表的头指针地址），希望获取的结点元素DataType e的地址。

2、定义一个LinkNode * p指针变量，并被L头指针所指向的下一个结点地址所赋值。

3、利用while循环，执行条件是p所指向的指针不为空，且p指向结点的数据域不等于e；若满足条件则执行p = p->next，移动p指针指向的地址；直到p指向结点的数据域等于e。

4、最后将p的地址指针返回。



### 删除单链表中第i个元素

```c
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
```

1、定义一个deleteLinkNode()函数，形参是LinkList L（链表的头指针地址），int i希望删除的第i个结点的元素位置。

2、LinkNode* p将被赋值指向要删除的结点；q指针变量用于指向要删除结点的前一个结点。；定义int j = 1，作为一个计数器，初始值为1，用于统计单链表中的结点数。

3、利用if判断i删除的位置是否合法，其合法范围是i大于或等于1且i小于或等于getLinkListLength(L)，调取getLinkListLength()函数得到单链表的长度；所以if的判断条件是

```c
if(i < 1 || i > getLinkListLength(L))
```

若获取的位置在范围内。则打印“删除位置不正确！”，并执行exit(1)退出程序。

4、利用while循环，条件是(j < i)，通过j计数器的自增和将q的下一个结点指针赋值给q，来实现移动p指针的作用；循环到希望删除的位置的上一个结点。

5、将q指向的下一个结点，即希望删除结点的指针赋值给p；再将希望删除结点的下一个结点地址赋值给的删除结点的上一个节点指针域(q->next)。

6、最后free(p)释放p指向结点(希望删除的结点)的地址空间。



### 输出单链表中的元素

```c
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
```

1、定义一个printLinkList()函数，形参是LinkList L（链表的头指针地址）。

2、定义一个LinkNode* p指针变量，并赋值为L的指向的下一个结点。

3、利用while循环判断p指针指向的地址是否为空；若不为空，则打印出该指针p的结点数据域data。

4、将p指针指向的下一个结点指针赋值给p，起到移动p指针的作用。
