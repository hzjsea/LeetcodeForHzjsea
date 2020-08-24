#include <stdio.h>
#include <stdlib.h>

// 双链循环链表

// 节点
struct Node
{
    int val;
    struct Node *prior; // 指向上一个节点的地址
    struct Node *next;  // 指向下一个节点的地址
};

// 返回一个节点
typedef struct Node newnode;
// 返回一个节点的地址
typedef struct Node *nodeAddress;

// 空链表
nodeAddress InitList(int val, nodeAddress *head)
{
    // 创建一个新的节点
    nodeAddress newnode = (nodeAddress)malloc(sizeof(struct Node));
    (*head)->next = newnode;
    newnode->next = newnode;
    newnode->val = val;
    // newnode -> next = NULL;
    newnode->prior = newnode;
    return newnode;
}

// 从指定位置处插入节点
int InsertListBylocation(int val, nodeAddress head, int index)
{
    // 新增节点
    nodeAddress newnode = (nodeAddress)malloc(sizeof(struct Node));
    newnode->val = val;
    newnode->next = NULL;
    newnode->prior = NULL;

    // 判断终止条件
    if (head == NULL || index < 0)
    {
        return 0;
    }

    // 插入表头
    if (index == 1)
    {
       
        newnode->next = head;
        head->prior = newnode;
    }
    // 创建游标
    nodeAddress current = head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    // 判断节点位置
    if (current->next == NULL)
    {
        // 说明是尾节点
        current->next = newnode;
        newnode->prior = current;
    }
    else
    {
        // 说明是中间节点
        newnode->prior = current;
        newnode->next = current->next;
        current->next->prior = newnode;
        current->next = newnode;
    }

    return 1;
}

// 遍历输出
int TraverseList(nodeAddress head)
{
    if (head == NULL)
    {
        return 0;
    }
    nodeAddress current = head;
    while (current)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
    return 0;
}


int main()
{
    struct Node *L;
    L = InitList(2, &L);
    // AddListTaril(3,L);
    InsertListBylocation(3, L, 1);
    InsertListBylocation(3, L, 2);
    TraverseList(L);
    return 0;
}
