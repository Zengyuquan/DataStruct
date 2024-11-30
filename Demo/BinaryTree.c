#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int DataType;
typedef struct tnode
{
    DataType data;
    struct tnode *lchild, *rchild;
}BNode, *BTree;

BNode nodePool[MAX];
int nodeCount = 0;

// 创建结点
BTree createNode(int x)
{
    if (nodeCount >= MAX) {
        printf("节点池已满，无法创建新节点\n");
        exit(1);
    }
    BTree newNode = &nodePool[nodeCount++];
    newNode->data = x;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// 打印结点数据
void PrintNodeData(BTree bt) {
    if (bt != NULL) {
        printf("节点数据: %d\n", bt->data);
    } else {
        printf("节点为空\n");
    }
}

// 先序遍历
void PreOrderTraverse(BTree bt)
{
    if(bt)
    {
        PrintNodeData(bt);
        PreOrderTraverse(bt->lchild);
        PreOrderTraverse(bt->rchild);
    }
}

// 中序遍历
void InOrderTraverse(BTree bt)
{
    if(bt)
    {
        InOrderTraverse(bt->lchild);
        PrintNodeData(bt);
        InOrderTraverse(bt->rchild);
    }
}

// 后序遍历
void PostOrderTraverse(BTree bt)
{
    if(bt)
    {
        PostOrderTraverse(bt->lchild);
        PostOrderTraverse(bt->rchild);
        PrintNodeData(bt);
    }
}

// 层序遍历
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

int main()
{
    // 创建根节点
    BTree root = createNode(10);

    // 创建左子节点
    root->lchild = createNode(5);

    // 创建右子节点
    root->rchild = createNode(15);

    // 创建左子节点的左子节点
    root->lchild->lchild = createNode(3);

    // 创建左子节点的右子节点
    root->lchild->rchild = createNode(7);

    // 创建右子节点的左子节点
    root->rchild->lchild = createNode(12);

    // 创建右子节点的右子节点
    root->rchild->rchild = createNode(18);

    // 先序遍历
    printf("先序遍历: \n");
    PreOrderTraverse(root);
    printf("\n");

    // 中序遍历
    printf("中序遍历: \n");
    InOrderTraverse(root);
    printf("\n");

    // 后序遍历
    printf("后序遍历: \n");
    PostOrderTraverse(root);
    printf("\n");

    // 层序遍历
    printf("层序遍历: \n");
    ArraOrderTraverse(root);
    printf("\n");

    return 0;
}