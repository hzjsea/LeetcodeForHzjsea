//2020-07-17 16:22:18
#include <stdio.h>
#include <stdlib.h>

// 双向链表
// 提供前驱和后驱

struct Node
{
    int val;
    struct Node *prev; // 提供前驱
    struct Node *next; // 提供后驱
};

// 结点
typedef struct Node node;
// 返回结点地址
typedef struct Node *nodeAdress;
// 返回头指针
typedef struct nodeAdress *head;

// 初始化双链表
int initLinkList(nodeAdress *head, int val)
{
    // 创建头结点
    nodeAdress first = (nodeAdress)malloc(sizeof(struct Node));
    (*head)->next = first;
    // 提供双链表里面的前驱指向null还是指向头指针
    first->prev = (*head);
    first->next = NULL;
    first->val = val;
    printf("已初始化链表~\n");
    return 1;
}

// 双链表遍历
void TrasLinkLisk(nodeAdress head)
{
    printf("遍历链表：\n");
    if (head == NULL || head->next == NULL)
    {
        printf("这是一个空链表\n");
        return;
    }
    // 创建游标
    nodeAdress current;
    // 游标的初始位置为头结点
    current = head;
    printf("根据next从前往后遍历：");
    while (current->next)
    {
        printf("%d ", current->next->val);
        current = current->next;
    }
    printf("\n");
    // 这时候已经到了尾节点，在遍历上来
    while (current != head)
    {
        printf("%d ", current->val);
        current = current->prev;
    }
    printf("\n");
}