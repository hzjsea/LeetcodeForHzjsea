

#include <stdio.h>
#include <stdlib.h>

// 创建一个节点
struct Node
{
    int data;
    struct Node *next;
};

//alias 分别给该节点的实例，以及该节点实例的地址
typedef struct Node node;
typedef struct Node *ptrSelf_node; // 也可以写成       typedef node *ptrSelf_node;

// 生成一个链表
ptrSelf_node create()
{
    ptrSelf_node head = NULL;
    ptrSelf_node second = NULL; // 初始化，让他们指向的地址都为空

    // 创建节点
    head = malloc(sizeof(node));
    second = malloc(sizeof(node)); // 初始化 动态分配内存地址


    head -> data = 1;
    head -> next = second;
    second -> data = 2;
    second -> next = NULL;
    return head;
}

// 建立只有一个节点的链表函数
// 传入一个值 生成一个节点，节点的下一个指向 返回一个节点的地址
ptrSelf_node NewLinkedList(int value)
{
    // 建立一个节点，指向空
    ptrSelf_node new_node = NULL;
    // 自动分配内存
    new_node = malloc(sizeof(node));

    // 分配值
    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

// 遍历链表
// 输入：链表的头节点
// 输出：链表的长度（节点个
// 获取链表的长度，需要1个计时变量  遍历链表到最后一个节点
int Len(ptrSelf_node head)
{
    int count = 0;
    ptrSelf_node current_node = head;
    while (current_node != NULL)
    {
        count++;
        current_node = current_node-> next;
    }
    return count;
}


// 遍历链表2 
// 利用for 循环来简化操作
int Len2(ptrSelf_node head)
{
    int count = 0;
    ptrSelf_node current_node;
    for (current_node = head; current_node != NULL ; current_node = current_node->next){count++;}
    return count    ;
}

// https://zhuanlan.zhihu.com/p/34636805


// 在链表结尾添加数据
// 传入链表的头结点。和添加的尾节点的值

void AppendNode(ptrSelf_node head){
    // 创建一个新的节点
    struct Node *new_node;
    // 动态分配内存
    new_node = malloc(sizeof(struct Node));
    // 将新的节点指向NULL
    new_node -> next = NULL;
    

    struct Node *current_node;
    // 找到最后一个节点
    for (current_node = head ; current_node -> next !=NULL ; current_node = current_node->next);
    
    // 因为之前尾部的结点是指向NULL的
    // 因此如果要在尾部添加，只要将老的尾部节点指向新建的结点就OK了
    current_node -> next = new_node;
}

// 表结尾删除链表
void DeleteNode(ptrSelf_node head){
    int value = 0;
    // 考虑链表长度为1的可能性
    if (head->next == NULL){
        value = head->data ;
        free(head);
        return ;

    }
    // 找到倒数第二个节点
    struct Node *current_node;
    for (current_node = head ; current_node -> next -> next !=NULL ;current_node = current_node->next);


    free(current_node->next);
    current_node->next = NULL;
    return ;
}

