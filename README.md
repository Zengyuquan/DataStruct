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

2、typedef定义DataType为int型，为int起别名，这种做法增强了代码的可读性和可维护性。

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

1、typedef定义DataType为int型，为int起别名，这种做法增强了代码的可读性和可维护性。

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

5、将q指向的下一个结点，即希望删除结点的指针赋值给p；再将希望删除结点的下一个结点地址赋值给的删除结点的上一个结点指针域(q->next)。

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



## Sequence_Stack（顺序栈）

### 顺序栈的定义

```c
#define MAXLEN 100
typedef int DataType;
typedef struct{
    DataType data[MAXLEN];
    int top;
} SeqStack;
SeqStack SS;
```

1、首先定义一个顺序栈最大长度的常量——MAXLEN为100。

2、typedef定义DataType为int型，为int起别名，这种做法增强了代码的可读性和可维护性。

3、定义顺序栈的结构体，并起别名为SeqStack；定义顺序栈采用静态分配内存空间，其类型为DataType（int）型的数组，数组长度为MAXLEN；同时也定义一个int型的变量——top来记录顺序栈的栈顶。

4、定义了一个顺序栈——SS。



### 顺序栈的初始化

```c
void InitSeqStack(SeqStack *SS)
{
    SS->top = 0;
}
```

1、定义一个InitSeqStack()函数，其形参是SeqStack类型的指针。

2、将栈顶置为0，表示为空栈。



### 判断顺序栈是否为空

```c
int EmptySeqStack(SeqStack *SS)
{
    if(SS->top == 0)
        return 1;
    else
        return 0;
}
```

1、定义一个EmptySeqStack()函数，其形参是SeqStack类型的指针，返回1表示顺序栈为空，若0不为空。

2、利用if判断该顺序栈SS的栈顶是否等于0，若为等于0返回1，表示顺序栈为空，不为空则返回0。



### 判断顺序栈是否为满

```c
int FullSeqStack(SeqStack *SS)
{
    if(SS->top == MAXLEN - 1)
        return 1;
    else
        return 0;
}
```

1、定义一个FullSeqStack()函数，其形参是SeqStack类型的指针，返回1表示顺序栈为满，若0不为满。

2、利用if判断该顺序栈SS的栈顶是否等于顺序栈最大长度MAXLEN -1（下标从0开始）；若符合判断条件返回1，表示顺序栈为满，不为满则返回0。



### 进栈

```c
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
```

1、定义一个PushSeqStack()函数，其形参是SeqStack类型的指针和将要进栈的元素。

2、利用if判断顺序栈是否为满，若为满则无法进栈；判断条件与上面判断是否为满栈一样，该顺序栈SS的栈顶是否等于顺序栈最大长度MAXLEN -1（下标从0开始）；若满栈打印“栈已满，无法进栈！”，exit(1)退出程序。

3、若不未满，先将SS的栈顶top自增加一，再将元素赋值给栈顶。

注：假设插入到空栈中，空栈的栈顶是第一个元素的位置，由于先移动栈顶，再插入元素；所以第一个有意义的数据是在栈的第二个位置上。这样的好处是方便判断该栈是否为空。



### 出栈

```c
DataType PopSeqStack(SeqStack *SS)
{
    DataType x;
    if(SS->top == 0)
    {
        printf("栈为空，无法出栈！\n");
        exit(1);
    }
    else
    {
        x = SS->data[SS->top];
        SS->top--;
        return x;
    }
}
```

1、定义一个PopSeqStack()函数，其形参是SeqStack类型的指针，返回出栈的元素x。

2、利用if判断顺序栈是否为空，若为空则无法进栈；判断条件与上面判断是否为空栈一样，该顺序栈SS的栈顶是否等于0；若空栈打印“栈已空，无法出栈！”，exit(1)退出程序。

3、若不未空，先将栈顶元素赋值给x，再将栈顶top自减减一；最后将x返回。



### 读取栈顶元素

```c
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
```

1、定义一个getStack()函数，其形参是SeqStack类型的指针。

2、利用if判断顺序栈是否为空，若为空则无法进栈；判断条件与上面判断是否为空栈一样，该顺序栈SS的栈顶是否等于0；若满栈打印“栈已空，无法出栈！”，exit(1)退出程序。

3、若不为空栈，则返回栈顶元素SS->data[SS->top]。





## Link_Stack（链栈）

### 链栈的定义

```c
typedef int DataType;
typedef struct stacknode{
    DataType data;
    struct stacknode* next;
}StackNode, *LinkStack;
```

1、‘typedef’定义‘DataType’为‘int’型，为’int‘起别名，这种做法增强了代码的可读性和可维护性。

2、定义链栈的结构体’stacknode‘，并起别名为’StackNode‘和’StackList‘的结构体指针；结构体中定义了两个变量，其中’DataType data ‘为链栈的数据域，用来存储结点的数据；而’struct node* next‘;为链栈的指针域，存储指向下一个’StackNode‘。



### 链栈的初始化

```c
LinkStack InitLinkStack()
{
    LinkStack top = NULL;
    return top;
}
```

1、定义一个‘InitLinkStack()’函数，用于初始化链栈并返回栈顶指针。

2、定义一个’LinkStack‘类型的变量‘top’，表示栈顶指针；并将其赋值为’NULL‘（指针为空）。

3、最后将其栈顶指针’top‘返回。



### 判断链栈是否为空

```c
int EmptyLinkStack(LinkStack top)
{
    if(top == NULL)
        return 1;
    else
        return 0;
}
```

1、定义一个’EmptyLinkStack()‘函数，用于判断链栈是否为空；传入’LinkStack top‘栈顶指针；返回1表示链栈为空，若0不为空。

2、利用if判断栈顶指针top是否为NULL，若符合判断条件返回1，表示链栈为空，不为空则返回0。



### 进栈

```c
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
```

1、定义一个’PushLinkStack()‘函数，用于使元素进栈；传入’LinkStack top‘栈顶指针和将进栈的元素‘DataType x’；最后返回栈顶指针。

2、定义一个‘StackNode *p’来接收malloc申请的地址空间指针。申请的地址空间大小为‘StackNode‘变量的大小，类型强转为’StackNode *‘的指针变量。

3、利用if判断，判断p是否为空，若为空，则说明malloc申请的地址空间指针失败；打印“结点空间申请失败！”并执行exit(1)退出程序。

4、若malloc申请成功，则将x赋值给p的数据域；再将p的指针域指向当前的栈顶结点，即插入新结点到栈中；最后让新插入结点的指针赋值给栈顶指针（top）。

5、返回栈顶指针（top）。



### 出栈

```c
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
```

1、定义一个’PopLinkStack()‘函数，用于使元素出栈；传入’LinkStack top‘栈顶指针；最后返回栈顶指针。

2、定义一个‘StackNode* p’类型的指针变量top，用来表示栈顶指针。

3、利用if判断，判断p是否为空，若为空，则说明栈为空，无法出栈元素，打印“栈为空！”并执行exit(1)退出程序。

4、若栈不为空，则先将栈顶元素赋值给定义的‘DataType x’保存元素；再将栈顶的下一个元素的地址指针赋值给top，表示栈顶指针移动到删除元素的下一个元素位置；再通过‘free(p)’释放删除元素的地址空间。

5、最后打印出栈的元素值，返回栈顶指针top。



### 获取栈顶元素

```c
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
```

1、定义一个’GetTopLinkStack()‘函数，用于返回栈顶的元素；传入’LinkStack top‘栈顶指针；最后返回栈顶元素。

2、利用if判断，判断top是否为空，若为空，则说明栈为空，无法出栈元素，打印“栈为空！”并执行exit(1)退出程序。

3、若栈不为空，则直接返回栈顶指针（top）的数据域data中的元素，即为栈顶元素。



### 输出链栈的元素

```c
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
```

1、定义一个’PrintLinkStack()‘函数，用于返回栈顶的元素；传入’LinkStack top‘栈顶指针。

2、定义一个‘LinkStack p’类型的指针变量top，用来指向当前栈顶指针。

3、利用if判断，判断top是否为空，若为空，则说明栈为空，无法出栈元素，打印“栈为空！”并执行exit(1)退出程序。

4、若栈不为空，则利用while循环，其判断条件为指针p不等于空；若不为空则打印指针p指向的结点数据域，最后指针p指向p的下一个结点地址指针，起到移动p指针作用，一直遍历到栈底。





## Seq_CirQueue（顺序循环队列）

### 顺序循环队列的定义

```c
#define MAXLEN 100
typedef int DataType;
typedef struct {
    DataType data[MAXLEN];
    int front, rear;
}CirQueue;
```

1、首先定义一个顺序栈最大长度的常量——‘MAXLEN’为100。

2、typedef定义‘DataType’为int型，为int起别名，这种做法增强了代码的可读性和可维护性。

3、定义顺序栈的结构体，并起别名为‘CirQueue’；定义顺序栈采用静态分配内存空间，其类型为‘DataType（int）’型的数组，数组长度为‘MAXLEN’；同时也定义两个int型的变量——front、rear来记录顺序循环队列的队头与队尾。



### 初始化循环队列

```c
void InitCirQueue(CirQueue *CQ)
{
    CQ->front = CQ->rear = 0;
}
```

1、定义一个‘InitCirQueue()’函数，其形参是‘CirQueue’类型的指针。

2、将对队头和队尾都置为0；



### 判断循环队列是否为空

```c
int EmptyCirQueue(CirQueue *CQ)
{
    return CQ->front == CQ->rear;
}
```

1、定义一个‘EmptyCirQueue()’函数，其形参是‘CirQueue’类型的指针，返回判断结果‘1’或者‘0’。

2、判断队尾是否等于队头；相等返回1，表示为空；不相等返回0，表示不为空。



### 判断循环队列是否为满

```c
int FullCirQueue(CirQueue *CQ)
{
    return (CQ->rear + 1) % MAXLEN == CQ->front;
}
```

1、定义一个‘FullCirQueue()’函数，其形参是‘CirQueue’类型的指针，返回判断结果‘1’或者‘0’。

2、判断队尾加1的和，再与‘MAXLEN’进行取余运算与队头是否相等；若相等，则返回1，表示队满；不等于队头返回0，表示队未满。

注：循环队列的起始下标是0，假设当前循环队列最大长度是100，‘CQ->front’指向的是0，‘CQ->rear’指向的是99，此时仅判断‘CQ->rear+1’是等于100的，超出了最大长度下标，从而我们需要进行取余的操作，使之变为0；取余操作‘%’可以确保指针在队列中循环移动。



### 入队

```c
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
```

1、定义一个‘InsertCirQueue()’函数，其形参是‘CirQueue’类型的指针和将入队的元素‘DataType x’。

2、利用if判断队列是否为满，判断条件与上面判断是否为满相同；若为满，则打印‘队列已满，无法入队！’，并执行‘exit(1)’退出程序。

3、若队不为满，则可正常入队；先移动‘CQ->rear'到下一个位置，与判断为满存在相同，也需要进行取余操作防止超过队列最大长度，确保rear在队列中。

4、再将x赋值给‘CQ->rear'移动后的位置的数作为’CQ->data[]‘下标的数组中。



### 出队

```c
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
```

1、定义一个‘DeleteCirQueue()’函数，其形参是‘CirQueue’类型的指针和将出队的元素‘DataType x’，最后返回出队元素x。

2、利用if判断队列是否为空，判断条件是’(CQ->front + 1) % MAXLEN == CQ->rear‘；因为入队操作只移动rear后为rear位置赋值，不移动front，则front位置是不存储数据的；所以需要将front加1，移动到有数据的位置再取余，防止超过队列最大长度，确保front在队列中；若为空，则打印‘队列为空，无法出队！’，并执行‘exit(1)’退出程序。

3、若队不为空，则可正常出队；先移动原本位置的‘CQ->front'到下一个位置，因为当前front位置是不存储数据的；也需要进行取余操作防止超过队列最大长度，确保front在队列中。

4、再将‘CQ->front'移动后的位置的数作为’CQ->data[]‘下标的数组中的数值赋值给x，并将x返回。



### 输出循环队列的元素

```c
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
```

1、定义一个‘PrintCirQueue()’函数，其形参是‘CirQueue’类型的指针。

2、定义一个‘int i’，用来接收’CQ->front‘的信息。

3、利用if判断队列是否为空，判断条件与出队判断是否为空相同；若为空，则打印‘队列为空，无法读取！’，并执行‘exit(1)’退出程序。

4、若队不为空，则可正常打印；利用while循环，循环条件是’i != CQ->rear‘，即’CQ->front != CQ->rear‘，front不等于rear；等于时则说明队列为空，不存在元素。

5、此时i表示是front，’i != CQ->rear’等同于‘CQ->front = (CQ->front + 1) % MAXLEN’；与出队的操作类似，在while循环中不断移动front的位置。

6、最后将front逐步移动过程中位置数作为’CQ->data[]‘下标，把该数组对应的下标元素打印出来。



## Link_Queue（链队）

### 链队的定义

```c
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
```

1、‘typedef’定义‘DataType’为‘int’型，为’int‘起别名，这种做法增强了代码的可读性和可维护性。

2、定义链队的结构体’qnode‘，并起别名为’QNode‘的结构体变量；结构体中定义了两个变量，其中’DataType data ‘为链队的数据域，用来存储结点的数据；而’struct qnode* next‘;为链队的指针域，存储指向下一个’qnode‘。

3、不仅需要定义链队的结构体，还需要定义一个结构体存储头指针和尾指针；在这个结构体内，定义两个‘QNode’类型的指针变量，*front（头指针）和\*rear（尾指针）；并取别名为‘Queue’的结构体变量和‘\*QueueList’的结构体指针。



### 初始化链队

```c
QueueList InitNode()
{
    QNode *QN = (QNode *)malloc(sizeof(QNode));
    QueueList LQ = (Queue *)malloc(sizeof(Queue));
    QN->next = NULL;
    LQ->front = QN;
    LQ->rear = QN;
    return LQ;
}
```

1、定义一个‘InitNode()’函数，用于初始化链队并返回链队指针结构体的指针；初始化过程包括分配内存、设置初始结点以及设置头尾指针。

2、定义一个‘QNode *QN’的指针变量来接收malloc函数分配地址空间的指针，分配的地址空间大小为‘sizeof(QNode)’。

3、定义一个‘QueueList LQ’的指针变量来接收malloc函数分配地址空间的指针，分配的地址空间大小为‘sizeof(Queue)’。

4、将‘QN->next’赋值为NULL，即表示链队中仅存在一个结点，且该结点在后续的操作不会存入数据。

5、将‘LQ->front’与‘LQ->rear’都指向’QN‘，表示初始化了该链队且队列为空。

6、最后将链队指针结构体的指针’LQ‘返回。



### 判断链队是否为空

```c
int EmptyLinkQueue(QueueList LQ)
{
    return LQ->front == LQ->rear;
}
```

1、定义一个‘EmptyLinkQueue()’函数，用于判断链队是否为空并返回判断的结果；形参是链队指针结构体的指针‘QueueList LQ’。

2、返回‘return LQ->front == LQ->rear’判断的结果，当队头指针等于队尾指针时，链队即为空，返回1；不相等，则不为空，返回0。



### 入队

```c
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
```

1、定义一个‘InsertLinkQueue()’函数，用于将元素入队；形参是链队指针结构体的指针‘QueueList LQ’和将入队的元素‘DataType x’，返回值是链队指针结构体的指针‘QueueList’。

2、定义一个‘QNode *p’的指针变量来接收malloc函数分配地址空间的指针，分配的地址空间大小为‘sizeof(QNode)’。

3、利用if判断，判断p是否为空，若为空，则说明malloc申请的地址空间指针失败；打印“结点空间分配失败！”并执行exit(1)退出程序。

4、若p不为空，则将x赋值给p所指向结点的数据域；再将p所指向结点的指针域赋值为NULL，表示该链队为最后一个结点。

5、将原本的队尾结点’LQ->rear‘的指针域’next‘指向p所指向结点，使得p指向结点与计划入队的链队链接起来；再移动’LQ->rear‘到p，因为此时的p指向结点才为队尾。

6、最后将链队指针结构体的指针’LQ‘返回。



### 出队

```c
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
```

1、定义一个‘DeleteLinkQueue()’函数，用于将元素出队；形参是链队指针结构体的指针‘QueueList LQ’，返回值是链队指针结构体的指针‘QueueList’。

2、定义一个‘QNode’类型的变量‘*p’；一个‘DataType’类型的变量’x‘。

3、利用if判断，判断链队是否为空，判断条件是’LQ->front == LQ->rear‘，若为空，则无法出队元素，打印“队列为空！”并执行’exit(1)‘退出程序。

4、若不为空，则正常出队；先将队头结点’LQ->front->next‘赋值给p，便于后续操作；再将队头结点’LQ->front->next‘的数据域'data'，此时也就是’p->data‘赋值给’x‘。

5、后移’LQ->front‘，即为后移次队头的位置到p指向结点的下一个结点’p->next‘；p指向结点将出队，p的下一个结点（原本的次队头）将作为队头。

6、假设出队最后一个结点时，此时链队则为空，要将队头指针指向队尾指针；所以需要利用if判断p指向结点的指针域是否为空，若为空则说明p指向结点是队尾结点。

7、最后释放p指向结点的地址空间；并返回链队指针结构体的指针’LQ‘。



### 获取队头元素

```c
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
```

1、定义一个‘ GetHeadLinkQueue()’函数，用于获取队头元素；形参是链队指针结构体的指针‘QueueList LQ’，返回值是获取到的元素，类型为’DataType‘。

2、利用if判断，判断链队是否为空，判断条件是’LQ->front == LQ->rear‘，若为空，则无法出队元素，打印“队列为空！”并执行’exit(1)‘退出程序。

3、若不为空，则可正常获取元素；对’LQ->front->next‘，即为队头结点，再将该结点的数据域’data’返回。



### 输出链队元素

```c
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
```

1、定义一个‘PrintLinkQueue()’函数，用于将元素输出打印；形参是链队指针结构体的指针‘QueueList LQ’。

2、定义一个‘QNode’类型的变量‘*p’。

3、利用if判断，判断链队是否为空，判断条件是’LQ->front == LQ->rear‘，若为空，则无法出队元素，打印“队列为空！”并执行’exit(1)‘退出程序。

4、若不为空，则正常输出；将队头结点’LQ->front->next‘赋值给p；利用while循环判断p是否等于队尾‘LQ->rear->next’；若等于则说明链队为空，无元素可输出打印；否则输出打印p指向结点的数据域‘p->data’；最后将p指向结点的下一个结点指针赋值给p，后移p指针。



## Seq_String（字符串）

### 字符串的定义

```c
#define MaxLen 100
typedef struct
{
    char str[MaxLen];
    int curlen;
}SString;
```

1、首先定义一个字符串最大长度的常量——‘MAXLen’为100。

2、定义字符串的结构体，并起别名为‘SString’；定义字符串采用静态分配内存空间，其类型为‘str’型的数组，数组长度为‘MAXLen’；同时也定义一个int型的变量’curlen‘来统计字符串的长度。



### 赋值

```c
void StrAssign(SString *S, char chars[])
{
    for (int i = 0; i < strlen(chars); i++)
    {
        S->str[i] = chars[i];
    }
    S->curlen = strlen(chars);
    S->str[S->curlen] = '\0';
}
```

1、定义一个‘StrAssign()’函数，用于为字符串赋值；形参是字符串结构体指针’SString *S‘和将赋值给字符串的数组‘char chars[]’。

2、利用‘for’循环，遍历‘chars[]’数组中的元素赋值到字符串S中，循环的次数是‘chars[]’数组的长度。

3、利用‘strlen()’求出‘chars[]’数组的长度，并赋值给’curlen‘记录字符串中的元素个数。

4、最后将字符串中的最后一个元素的下一个位置，下标巧合是‘chars[]’数组的长度；将该位置的值赋值为‘\0’表示字符串的结束。



### 复制

```c
void StrCopy(SString *S, SString *T)
{
    for (int i = 0; i < T->curlen; i++)
    {
        S->str[i] = T->str[i];
    }
    S->curlen = T->curlen;
    S->str[S->curlen] = '\0';
}
```

1、定义一个‘StrCopy()’函数，用于字符串的复制；形参是复制到字符串结构体指针’SString *S‘和将复制的字符串结构体指针’SString *T‘。

2、利用‘for’循环，遍历字符串T的元素，并将其复制到字符串S中，循环的次数是字符串T的长度。

3、将字符串T的长度并赋值给字符串S的’curlen‘来记录字符串中的元素个数。

4、最后将字符串S中的最后一个元素的下一个位置，下标巧合是字符串S的长度；将该位置的值赋值为‘\0’表示字符串的结束。



### 比较

```c
int StrEqual(SString *S, SString *T) {
    if(S->curlen != T->curlen) return 0;

    for (int i = 0; i < S->curlen; i++) {
        if(S->str[i] != T->str[i]) return 0;
    }
    return 1;
}
```

1、定义一个‘StrEqual()’函数，用于字符串的比较；形参是将比较的字符串结构体指针’SString *S‘和’SString *T‘；返回值是‘int’型，若相等返回1；不相等，返回0。

2、利用‘if’判断字符串S的长度是否与字符串T相等，若不相等则返回0。

3、利用‘for’循环，遍历字符串S和字符串T的元素进行比较，循环的次数是字符串S的长度。

4、在循环体中利用‘if’判断字符串S与字符串T，两者中的元素是否相等，若不相等则返回0。

5、若两字符串的长度与元素都相等，则返回1。



### 长度

```c
int Length(SString *S)
{
    return S->curlen;
}
```

1、定义一个‘Length()’函数，用于求字符串的长度；形参是将求长度的字符串结构体指针’SString *S‘。

2、直接返回‘S->curlen’即字符串的长度。



### 链接

```c
void StrCat(SString *CH, SString *S, SString *T)
{
    int i;
    CH->curlen = S->curlen + T->curlen;
    for (i = 0; i < S->curlen; i++)
    {
        CH->str[i] = S->str[i];
    }

    for (i = 0; i < T->curlen; i++)
    {
        CH->str[S->curlen + i] = T->str[i];
    }
    
    CH->str[CH->curlen] = '\0';
}
```

1、定义一个‘StrCat()’函数，用于字符串的链接；形参是将链接的字符串结构体指针’SString *S‘和’SString *T‘和链接目的的字符串结构体指针’SString *CH‘。

2、字符串CH的长度为字符串S与字符串T的和，即为两个字符串链接后的元素个数。

注：优先链接字符串S再链接字符串T，所以先遍历字符串S再遍历字符串T到字符串CH。

3、利用‘for’循环，先后遍历字符串S与字符串T的元素到字符串CH中；在字符串T的‘for’循环中，字符串CH已有‘S->curlen’个，下标是‘S->curlen’-1；所以开始复制的位置是’S->curlen + i‘。

4、最后将字符串CH中的最后一个元素的下一个位置，下标巧合是字符串CH的长度；将该位置的值赋值为‘\0’表示字符串的结束。



### 求子串

```c
void SubString(SString *Sub, SString *S, int pos, int len)
{
    int i, j = 0;
    if((pos >= 1 && pos <= S->curlen) && (len > 0 && len <= S->curlen - pos + 1))
    {
        for (i = pos - 1; i < len + pos - 1; i++)
        {
            Sub->str[j++] = S->str[i];
        }
        Sub->curlen = len;
        Sub->str[Sub->curlen] = '\0';
    }
    else
    {
        printf("\nerror!\n");
    }
}
```

1、定义一个‘SubString()’函数，用于求字符串的子串；形参是子串存储到的字符串结构体指针’SString *Sub‘和求子串目标字符串结构体指针’SString *S‘和起始位置’pos‘和子串的长度’len‘。

2、利用’if‘判断起始位置’pos‘是否大于或等于1且是否小于等于字符串S的长度；且长度大于0，也不能大于字符串S的总个数减去起始位置’pos‘加一的值；如果子串大于该值，则会超过字符串S的长度。

3、若符合条件，利用‘for’循环；遍历字符串S，’int i‘的初始值是起始位置’pos‘减一（字符串S对应的下标值），终止条件是i大于或等于子串的长度’len‘加上起始位置’pos的值减一，减一是因为需要匹配字符串S对应的下标值。将遍历字符串对应位置的值赋值给字符串Sub，赋值的位置为’int j = 0‘的自增。

3、字符串Sub的’curlen‘即为子串的长度’len‘。

4、最后将字符串Sub中的最后一个元素的下一个位置，下标巧合是字符串Sub的长度；将该位置的值赋值为‘\0’表示字符串的结束。

5、若不符合条件，输出打印’error!‘。



### 判断串空

```c
int Empty(SString *S)
{
    return (S->curlen == 0);
}
```

1、定义一个‘Empty()’函数，用于判断字符串是否为空；形参是判断的字符串结构体指针’SString *S‘。

2、直接返回字符串S的长度是否为0的结果。



### 插入

```c
int StrInsert(SString *S, int pos, SString *T)
{
    int i, k;
    if(pos < 1 || pos > S->curlen + 1)
    {
        return 0;
    }
    if(S->curlen + T->curlen <= MaxLen)
    {
        for (i = S->curlen - 1; i >= pos - 1; i--)
        {
            S->str[i + T->curlen] = S->str[i];
        }
        for (i = pos - 1, k = 0; i < pos + T->curlen - 1; i++, k++)
        {
            S->str[i] = T->str[k];
        }
        S->curlen = S->curlen + T->curlen;
        S->str[S->curlen] = '\0';
        return 1;
    }
    else
    {
        for(i = MaxLen - 1; i >= pos; i--)
        {
            S->str[i] = S->str[i - T->curlen];
        }
        for(i = pos - 1; i < pos - 1 + T->curlen; i++)
        {
            S->str[i] = T->str[i - pos + 1];
        }
        S->curlen = MaxLen;
        S->str[S->curlen] = '\0';
        return 0;
    }
}
```

1、定义一个‘StrInsert()’函数，用于插入字符串；形参是被插入到的字符串结构体指针’SString *S‘和将插入的字符串结构体指针’SString *T‘和插入位置’pos‘，结果返回1或者0，表示插入成功或者失败。

2、利用‘if’判断插入位置‘pos’是否小于1或者大于字符串S的长度加一（对应字符串S的最后一个的下一个元素下标值），若符合判断条件则说明插入位置‘pos’插入的位置为非法位置；返回0表示插入失败。

3、利用‘if’判断被插入到的字符串S长度与插入的字符串T的长度和是否小于等于结构体中数组最大长度为‘MAXLen’。

4_1、若小于等于结构体中数组最大长度为‘MAXLen’；首先利用‘for’循环，‘int i’的初始位置是‘S->curlen’为字符串S的长度，终止条件是i小于插入位置‘pos’减一，此处的i采用自减；将字符串S中i对应的下标的元素移动到i加字符串T长度之和的位置；第一次循环将字符串S最后的元素的下一个位置，此位置的元素可能是‘\0’，移动到字符串S长度加字符串T长度之和的位置，第二次循环将字符串S最后的元素移动到字符串S长度加字符串T长度之和减一的位置，依次循环，最后将插入位置‘pos’减一对应的字符串S下标元素移动到插入位置‘pos’加字符串T之和减一对应的下标位置，最终在字符串S中腾出字符串T长度等同的空位。

4_2、再次利用‘for’循环，‘int i’的初始值是插入位置‘pos‘减一，’int k‘的初始值是0，终止条件是i大于等于插入位置‘pos’加字符串T长度之和的位置减一，i与k都自增；将字符串T的元素填充到字符串S中腾出的空位中。

4_3、插入后字符串S的’curlen‘即为原本的长度加上字符串T的长度。

4_4、最后将字符串S中的最后一个元素的下一个位置，下标巧合是字符串S的长度；将该位置的值赋值为‘\0’表示字符串的结束；并返回1表示插入成功。

5_1、若大于结构体中数组最大长度为‘MAXLen’；首先利用‘for’循环，‘int i’的初始位置是‘S->curlen’为最大长度为‘MAXLen’减一，终止条件是i大于插入位置‘pos’，此处的i采用自减；将字符串S中最后的元素移动到最大长度为‘MAXLen’的位置；第一次循环将字符串S最后的元素，移动到最大长度为‘MAXLen’的位置，第二次循环将字符串S倒数第二的元素移动到最大长度为‘MAXLen’的位置减一的位置，依次循环，最终在字符串S中腾出字符串T长度等同的空位。

5_2、再次利用‘for’循环，‘int i’的初始值是插入位置‘pos‘减一，终止条件是i大于等于插入位置‘pos’加字符串T长度之和的位置减一，i自增；将字符串T的元素填充到字符串S中腾出的空位中。

5_3、插入后字符串S的’curlen‘即为最大长度为‘MAXLen’。

5_4、最后将字符串S中的最后一个元素的下一个位置，下标巧合是字符串S的长度；将该位置的值赋值为‘\0’表示字符串的结束；并返回0表示插入失败（此插入方法，会导致元素的丢失，故插入失败）。



### 删除

```c
int Delete(SString *S, int pos, int len)
{
    int i;
    if(pos < 1 || pos > S->curlen - len + 1 || len < 0)
    {
        return 0;
    }
    for (i = pos + len - 1; i < S->curlen; i++)
    {
        S->str[i - len] = S->str[i];
    }
    S->curlen = S->curlen - len;
    S->str[S->curlen] = '\0';
    return 1;
}
```

1、定义一个‘Delete()’函数，用于使字符串的删除；形参是将删除的字符串结构体指针’SString *S‘和删除位置’pos‘和删除的长度’len‘。

2、利用‘if’判断删除位置‘pos’是否小于1或者大于字符串S的长度减去删除的长度’len‘加一，若符合判断条件则说明删除位置‘pos’删除的位置为非法位置；返回0表示删除失败。

3、若删除位置为合法位置；则利用利用‘for’循环，‘int i’的初始位置是删除位置’pos‘与删除的长度’len‘之和减一，终止条件是i大于等于字符串S的长度，此处的i采用自增；将字符串S中最后一个元素（非‘\0’）移动到删除位置’pos‘减一的下标位置，依次循环，将字符串S中‘pos’与‘len’之和的位置后面的元素移动到，删除出现的空位上。

4、字符串S的’curlen‘即为此时字符串自己的长度减去删除的长度’len‘。

5、最后将字符串S中的最后一个元素的下一个位置，下标巧合是字符串S的长度；将该位置的值赋值为‘\0’表示字符串的结束。

6、返回1表示删除成功。



### 替换

```c
void Replace(SString *S, int pos, int len, SString *T)
{
    int k, l, n, m, p;
    l = pos + len;
    if(len == T->curlen)
    {
        for(k = 0; k < T->curlen; k++)
        {
            S->str[pos - 1] = T->str[k];
            pos++;
        }
        S->curlen = S->curlen + T->curlen - len;
        S->str[S->curlen] = '\0';
    }
    else
    {
        if(len > T->curlen)
        {
            while(S->str[l - 1] != '\0')
            {
                m = len - T->curlen;
                S->str[l - m - 1] = S->str[l - 1];
                l++;
            }
            for (k = 0; k < T->curlen; k++)
            {
                S->str[pos - 1] = T->str[k];
                pos++;
            }
            S->curlen = S->curlen + T->curlen - len;
            S->str[S->curlen] = '\0';
        }
        else
        {
            if(len < T->curlen){
                p = n = S->curlen;
                while(n >= pos + len)
                {
                    m = T->curlen - len;
                    S->str[n + m - 1] = S->str[n - 1];
                    n--;
                }
                for(k = 0; k < T->curlen; k++)
                {
                    S->str[pos - 1] = T->str[k];
                    pos++;
                }
            }
            S->curlen = S->curlen + T->curlen - len;
            S->str[S->curlen] = '\0';
        }
    }
}
```

### 定位

```c
int StrIndex(SString *S, SString *T)
{
    int i = 0;
    int j = 0;
    while(i < S->curlen && j < T->curlen)
    {
        if(S->str[i] == T->str[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == T->curlen)
    {
        return i - T->curlen + 1;
    }
    else
    {
        return 0;
    }
}
```





### 输出

```c
void StrPrint(SString *S)
{
    int i;
    for (i = 0; i < S->curlen; i++) {
        printf("%c", S->str[i]);
    }
    printf("\n");
}
```



## BinaryTree（二叉树）

###  二叉树的定义

```c
#define MAX 100

typedef int DataType;
typedef struct tnode
{
    DataType data;
    struct tnode *lchild, *rchild;
}BNode, *BTree;

BNode nodePool[MAX];
int nodeCount = 0;
```

1、首先定义一个二叉树结构体内最大的数组长度常量——‘MAX’为100。

2、‘typedef’定义‘DataType’为‘int’型，为’int‘起别名，这种做法增强了代码的可读性和可维护性。

3、定义二叉树的结构体‘tnode’；定义顺序栈采用静态分配内存空间，其类型为‘DataType（int）’型的数组，数组长度为‘MAX’；同时也定义两个‘tnode’型的指针变量——‘lchild’、‘rchild’来记录二叉树的左孩子与右孩子；并结构体起别名BNode、结构体指针BTree。

4、定义一个‘BNode’类型的数组‘nodePool’，意为结点池，存储二叉树的结点，最大长度为‘MAX’。

5、定义一个‘int’型的变量‘nodeCount’，记录结点和个数。



### 创建结点

```c
BTree createNode(int x)
{
    if (nodeCount >= MAX) {
        printf("结点池已满，无法创建新结点\n");
        exit(1);
    }
    BTree newNode = &nodePool[nodeCount++];
    newNode->data = x;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}
```

1、定义一个‘createNode()’函数，用于创建二叉树的结点；形参是将创建的整型元素‘x’。

2、利用if判断‘nodeCoun’是否大于等于最大的数组长度‘MAX’；若大于，则打印‘结点池已满，无法创建新结点’；执行‘exit(1)’退出程序。

3、若小于，则正常创建结点；先取当前结点池数组中结点个数的下标地址，赋值给创建的’BTree newNode‘新结点地址中。

4、令新结点中的’data‘等于将创建的元素’x‘；新结点左孩子和右孩子都赋值为’NULL‘。

5、最后将新结点地址’BTree newNode‘返回。



### 打印结点数据

```c
void PrintNodeData(BTree bt) {
    if (bt != NULL) {
        printf("结点数据: %d\n", bt->data);
    } else {
        printf("结点为空\n");
    }
}
```

1、定义一个‘PrintNodeData()’函数，用于打印二叉树的结点数据；形参是将打印的二叉树地址’BTree bt‘。

2、利用if判断该地址是否为空；若不为空，打印出该结点的数据；为空则打印‘结点为空’。





### 先序遍历

```c
void PreOrderTraverse(BTree bt)
{
    if(bt)
    {
        PrintNodeData(bt);
        PreOrderTraverse(bt->lchild);
        PreOrderTraverse(bt->rchild);
    }
}
```

1、定义一个‘PreOrderTraverse()’函数，该函数先序遍历二叉树的结点数据；形参是将遍历的二叉树地址’BTree bt‘。

2、利用if判断当前二叉树结点指针是否为空；若不为空：则先调用‘PrintNodeData()’函数打印遍历到的结点数据；再一次调用本函数，但此时的形参是当前结点的左孩子地址，遍历左孩子结点及左孩子的孩子结点，遍历完当前结点的左孩子后，仍然调用本函数，但此时的形参是当前结点的右孩子地址，遍历右孩子结点及右孩子的孩子结点；采用递归的思想遍历二叉树，先序遍历的顺序是根结点、左孩子结点、右孩子结点。



### 中序遍历

```c
void InOrderTraverse(BTree bt)
{
    if(bt)
    {
        InOrderTraverse(bt->lchild);
        PrintNodeData(bt);
        InOrderTraverse(bt->rchild);
    }
}
```

1、定义一个‘InOrderTraverse()’函数，该函数中序遍历二叉树的结点数据；形参是将遍历的二叉树地址’BTree bt‘。

2、利用if判断当前二叉树结点指针是否为空；若不为空：首先再次调用本函数，但此时的形参是当前结点的左孩子地址，遍历左孩子结点及左孩子的孩子结点，调用‘PrintNodeData()’函数打印遍历到的结点数据；遍历完当前结点的左孩子后，仍然调用本函数，但此时的形参是当前结点的右孩子地址，遍历右孩子结点及右孩子的孩子结点；采用递归的思想遍历二叉树，中序遍历的顺序是左孩子结点、根结点、右孩子结点。



### 后序遍历

```c
void PostOrderTraverse(BTree bt)
{
    if(bt)
    {
        PostOrderTraverse(bt->lchild);
        PostOrderTraverse(bt->rchild);
        PrintNodeData(bt);
    }
}
```

1、定义一个‘PostOrderTraverse()’函数，该函数后序遍历二叉树的结点数据；形参是将遍历的二叉树地址’BTree bt‘。

2、利用if判断当前二叉树结点指针是否为空；若不为空：首先调用本函数，但此时的形参是当前结点的左孩子地址，遍历左孩子结点及左孩子的孩子结点，遍历完当前结点的左孩子后，仍然调用本函数，但此时的形参是当前结点的右孩子地址，遍历右孩子结点及右孩子的孩子结点，调用‘PrintNodeData()’函数打印遍历到的结点数据；采用递归的思想遍历二叉树，后序遍历的顺序是左孩子结点、右孩子结点、根结点。



### 层序遍历

```c
void ArraOrderTraverse(BTree bt)
{
    int f,r;
    BNode *p, *q[MAX];
    p = bt;
    if(p)
    {
        f=1;
        q[f] = p;
        r=2;
    }
    while (f != r)
    {
        p = q[f];
        printf("%d ", p->data);
        if(p->lchild != NULL)
        {
            q[r] = p->lchild;
            r = (r + 1) % MAX;
        }
        if(p->rchild != NULL)
        {
            q[r] = p->rchild;
            r = (r + 1) % MAX;
        }
        f = (f + 1) % MAX;
    }
}
```

1、定义一个‘ArraOrderTraverse()’函数，该函数层序遍历二叉树的结点数据；形参是将遍历的二叉树地址’BTree bt‘。

2、定义以下变量：‘int f’和‘int r’作为队列的前端与尾端；‘BNode *p’指针变量用于遍历结点，‘BNode *q[MAX]’指针数组存储结点指针，最大长度为‘MAX’；并将bt赋值给p。

3、利用if判断p不为空，即bt指针不为空；则将f初始化为1，将p地址存储到‘q[f]’中，r初始化为2。

4_1、利用while循环，判断条件为f不等于r时执行循环体；将‘q[f]’赋值给p，并打印出当前p结点数据。

4_2、利用if判断，判断当前结点p的左孩子是否为空；若不为空，则将左孩子地址存储到当前r值下标的数组q中，并将r加1的和与‘MAX’做模运算，此操作是防止r溢出队列。

4_3、再次利用if判断，判断当前结点p的右孩子是否为空；若不为空，则将右孩子地址存储到当前r值下标的数组q中，并将r加1的和与‘MAX’做模运算，此操作是防止r溢出队列。

4_4、将f加1的和与‘MAX’做模运算，此操作是防止f溢出队列。

5、当遍历到叶子结点的时，r不做增加操作，而f还将继续增加，等到叶子结点都遍历完后，f将等于r，退出循环。
