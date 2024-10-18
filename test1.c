#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct Node {
    int data;
    struct Node* next;
};

// 初始化单链表
struct Node* head = NULL;

// 头插法创建单链表
void insertAtHead(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// 尾插法创建单链表
void insertAtTail(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 求单链表长度
int getLength() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 获取元素指针
struct Node* getElement(int position) {
    struct Node* temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    return temp;
}

// 删除数据元素
void deleteElement(int position) {
    if (head == NULL) return;

    struct Node* temp = head;
    if (position == 0) {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// 打印单链表
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // 初始化单链表
    head = NULL;

    // 头插法创建单链表
    insertAtHead(3);
    insertAtHead(2);
    insertAtHead(1);

    // 打印单链表
    printf("After inserting at head: ");
    printList();

    // 尾插法创建单链表
    insertAtTail(4);
    insertAtTail(5);
    insertAtTail(6);

    // 打印单链表
    printf("After inserting at tail: ");
    printList();

    // 求单链表长度
    printf("Length of the list: %d\n", getLength());

    // 获取元素指针
    struct Node* element = getElement(2);
    if (element != NULL) {
        printf("Element at position 2: %d\n", element->data);
    } else {
        printf("Element not found at position 2\n");
    }

    // 删除数据元素
    deleteElement(3);
    printf("After deleting element at position 3: ");
    printList();

    return 0;
}