//2020-07-17 16:22:18
#include <stdio.h>
#include <stdlib.h>

// 单链表无头指针
// 链表中，节点与节点之间都是使用节点的地址来进行连接的

// 节点模板   [data,next] -> [data,next] ->null
struct Node
{
    int data;
    struct Node *next;
};

// 使用typedef 定义别名

typedef struct Node node;         // 普通节点
typedef struct Node *nodeAddress; // 返回一个节点地址
typedef struct nodeAddress *head; // 返回一个头指针的地址 也就是 **head

// 节点创建
// 传入一个头指针， 头指针指向头结点，头指针可以没有任何值
int createNode(nodeAddress *head)
{
    // 创建一个节点，返回节点的地址
    nodeAddress newnode;
    // 给节点分配内存地址,并且进行变量的强制转换
    newnode = (nodeAddress)malloc(sizeof(struct Node));
    // 给节点分配内容
    newnode->data = 1;
    newnode->next = NULL;
    return 0;
}

// 初始化节点 [data=null,next] -> [data=0;next] -> null
// 创建一个节点， 设置变量
// 头指针->头结点->null
// 返回头指针地址
// 有个问题 看到请回答 返回的到底是头结点的地址还是头指针的地址
int InitList(nodeAddress *head, int val)
{
    nodeAddress newnode;
    newnode = (nodeAddress)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    // 这里传入的只是一个节点的地址  **head 才表示头指针
    (*head)->next = newnode;
    return 0;
}

// 接下来是增删改查

// 插入节点
// 传入一个初始化后的链表的头指针地址
// 从后插入一个值
nodeAddress InsertListTail(nodeAddress head, int val)
{
    // 创建一个游标  确定位置
    nodeAddress current = head;
    nodeAddress newnode;
    newnode = (nodeAddress)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    // 确定尾结点的位置
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;

    return head; // 返回头结点
}

// 从尾部删除节点
// 获得倒数第二个节点
// 将倒数第一个节点指向NULL
// 为了防止内存溢出，还要释放掉分配的内存
nodeAddress DeleteListTail(nodeAddress head)
{
    nodeAddress current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    current->next = NULL;
    free(current->next);
    return head;
}

// 从尾部修改节点
nodeAddress UpdateListTail(nodeAddress head, int val)
{
    nodeAddress current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->data = val;
    return head;
}

// 查看最后一个节点的值
void LookListTail(nodeAddress head)
{
    nodeAddress current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    printf("%d", current->data);
}

// 从头部插入节点 用有指针来操作
// 插入头指针
// 创建节点
// 新头结点指向老的头结点
// 头指针指向新头结点

int InsertListHead(nodeAddress *head, int val)
{
    nodeAddress newnode = (nodeAddress)malloc(sizeof(struct Node)); // 创建新的节点
    newnode->data = val;
    newnode->next = NULL;

    nodeAddress first = (*head)->next;

    newnode->next = first;
    (*head)->next = newnode;
    return 0;
}

// 从头部删除节点
// 找到头结点(node1)的下一个节点为node2
// 头指针指向noint
// node1 指向null 并且释放掉内存
// 疑问 需要指向null嘛 可不可以直接释放内存

int DeleteListHead(nodeAddress *head)
{
    // 判断是否为空链表
    if ((*head)->next == NULL)
    {
        return 0;
    }

    // 否则
    nodeAddress current = (*head)->next;
    (*head)->next = current->next;
    current->next = NULL;
    free(current);

    return 1;
}

// 修改头部结点
int UpdateListHead(nodeAddress *head, int val)
{
    nodeAddress first = (*head)->next;
    first->data = val;
    return 1;
}

// 查找头结点
int LookListHead(nodeAddress *head, int val)
{
    nodeAddress first = (*head)->next;
    printf("%d", first->data);
    return 0;
}

//  接下来是全局

// 计算链表的长度
// 返回int长度
int ListLength(nodeAddress head, int val)
{
    nodeAddress current = head;
    int count = 0;
    while (current->next != NULL)
    {
        current = current->next;
        count++;
    }
    return count;
}

// 遍历所有的结点
void TraverseList(nodeAddress *head)
{
    // 判断链表是否为空
    if ((*head)->next == NULL)
    {
        printf("NULL");
    }
    nodeAddress current = (*head)->next;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// 判断是否为空链表，即 头指针的下一跳为空 [data=null,next] -> null
int isEmpty(nodeAddress *head)
{
    if ((*head)->next != NULL)
    {
        return 1; // 不为空
    }
    else
    {
        return 0; // 为空
    }
}

// 在指定index下添加节点
int InsertListIndex(nodeAddress head, int index, int val)
{
    int current_id = 1;
    nodeAddress current = head;
    for (current_id = 1; current_id < index; current_id++)
    {
        current = current->next;
    }
    nodeAddress newnode = (nodeAddress)malloc(sizeof(struct Node));
    newnode->next = current->next;
    newnode->data = val;
    current->next = newnode;
    return 1;
}

// 在指定index下删除节点
int DeleteListIndex(nodeAddress head, int index)
{
    int current_id = 1;
    nodeAddress current = head;
    for (current_id = 1; current_id < index; current_id++)
    {
        current = current->next;
    }
    current->next = current->next->next;
    nodeAddress deleteNode = current->next;
    deleteNode = NULL;
    free(deleteNode);
    return 1;
}

// 在指定index下查找值
int LookLinkListIndex(nodeAddress head, int index)
{
    int current_id = 1;
    nodeAddress current = head;
    for (current_id = 1; current_id < index; current_id++)
    {
        current = current->next;
    }
    printf("%d", current->data);
    return 1;
}

// 修改指定index下的值
int UpdateLinkListIndex(nodeAddress head, int index, int val)
{
    int current_id = 1;
    nodeAddress current = head;
    for (current_id = 1; current_id < index; current_id++)
    {
        current = current->next;
    }
    current->data = val;
    return 1;
}

// 清空链表
// 保留头部
int ClearLinkList(nodeAddress head)
{
    nodeAddress current = head;
    // 双指针
    nodeAddress current_backup = head;
    while (current->next != NULL)
    {
        current_backup = current->next->next;

        free(current->next);
        current->next = current_backup;
    }
    head->next = NULL;
    return 1;
}

// 摧毁链表
// 先销毁了链表的头，然后接着一个一个的把后面的销毁了，这样这个链表就不能再使用了，即把包括头的所有节点全部释放。
int DestoryLinkList(nodeAddress *head)
{
    nodeAddress first = (*head)->next;
    nodeAddress current = first;
    while (first)
    {
        (*head)->next = current->next;
        free(current);
    }
    return 0;
}
int main()
{
    // 创建一个节点
    nodeAddress head;
    InitList(&head, 20);
    head = InsertListTail(head, 30);
    InsertListHead(&head, 200);

    InsertListIndex(head, 2, 3);
    TraverseList(&head);
    DeleteListIndex(head, 2);
    // TraverseList(&head);
    ClearLinkList(head);
    TraverseList(&head);
    DestoryLinkList(&head);
    TraverseList(&head);
    return 0;
}