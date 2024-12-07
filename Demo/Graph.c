#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef char VertexType;

typedef struct node
{
    int adjVex;
    struct node* next;
} EdgeNode;

typedef struct vexNode
{
    VertexType data;
    EdgeNode* firstEdge;
} VHeadNode;

typedef struct
{
    VHeadNode adjList[MAX];
    int vertex, edge;
} AdjList;

void CreateAGraph(AdjList* G, int flag)
{
    int i, j, k;
    EdgeNode* p;

    if (flag == 0)
    {
        printf("将建立一个无向图\n");
    }
    else
    {
        printf("将建立一个有向图\n");
    }

    printf("请输入图的顶点数:\n");
    scanf("%d", &G->vertex);

    printf("请输入图的边数:\n");
    scanf("%d", &G->edge);

    printf("请输入图的各顶点信息:\n");
    for (i = 0; i < G->vertex; i++)
    {
        while (getchar() != '\n');

        printf("请输入第%d个顶点的信息:\n", i + 1);
        scanf("%c", &(G->adjList[i].data));
        G->adjList[i].firstEdge = NULL;
    }

    printf("请输入边的信息,输入格式为:序号1,序号2(号依次为0,1,2,3...):\n");
    for (k = 0; k < G->edge; k++)
    {
        printf("请输入第%d条边的信息:\n", k + 1);
        scanf("%d,%d", &i, &j);
        p = (EdgeNode*)malloc(sizeof(EdgeNode));
        p->adjVex = j;
        p->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = p;

        if (flag == 0)
        {
            p = (EdgeNode*)malloc(sizeof(EdgeNode));
            p->adjVex = i;
            p->next = G->adjList[j].firstEdge;
            G->adjList[j].firstEdge = p;
        }
    }
}

void DisplayAGraph(AdjList* G)
{
    int i;
    EdgeNode* p;

    printf("图的邻接表如下:\n");
    for (i = 0; i < G->vertex; i++)
    {
        printf("%d[%c]", i, G->adjList[i].data);
        p = G->adjList[i].firstEdge;
        while (p != NULL)
        {
            printf("-->[%d]", p->adjVex);
            p = p->next;
        }
        printf("\n");
    }
}

void DFS(AdjList* G, int Vi)
{
    static int visited[MAX] = { 0 };
    EdgeNode* p;

    printf("%d[%c] ", Vi, G->adjList[Vi].data);
    visited[Vi] = 1;
    p = G->adjList[Vi].firstEdge;

    while (p)
    {
        if (!visited[p->adjVex])
        {
            DFS(G, p->adjVex);
        }
        p = p->next;
    }
}

void BFS(AdjList* G, int Vi)
{
    static int visited[MAX] = { 0 };
    int qu[MAX], front = 0, rear = 0;
    EdgeNode* p;

    printf("%d[%c] ", Vi, G->adjList[Vi].data);
    visited[Vi] = 1;
    rear = (rear + 1) % MAX;
    qu[rear] = Vi;

    while (front != rear)
    {
        front = (front + 1) % MAX;
        int v = qu[front];
        p = G->adjList[v].firstEdge;
        while (p)
        {
            if (visited[p->adjVex] == 0)
            {
                visited[p->adjVex] = 1;
                printf("%d[%c] ", p->adjVex, G->adjList[p->adjVex].data);
                rear = (rear + 1) % MAX;
                qu[rear] = p->adjVex;
            }
            p = p->next;
        }
    }
}


int main()
{

    AdjList G;
    int flag;

    printf("请选择图的类型(0:无向图, 1:有向图):\n");
    scanf("%d", &flag);
    // 清除输入缓冲区
    while (getchar() != '\n');

    CreateAGraph(&G, flag);
    DisplayAGraph(&G);

    printf("\nDFS遍历（从顶点0开始）:\n");
    DFS(&G, 0);
    printf("\n");

    printf("\nBFS遍历（从顶点0开始）:\n");
    BFS(&G, 0);
    printf("\n");


    return 0;
}