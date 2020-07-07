#include <stdio.h>
#include <stdlib.h>

// 线性表的链式存储
// 创建一个节点模板
struct Node
{
    int val;
    struct Node *next;
};

// 定义别名，方便操作
// 创建节点
typedef struct Node NewNode;
// 创建节点的地址(指针)
typedef struct Node *NodeAddress;

// 线性表的链式存储
// (data=null)头节点 -> 首节点 -> 普通节点 *n -> 尾部节点 -----> 指向null

// 初始化一个链表 
// 要获取首节点的地址，往里面动态分配数据，并且强制转换类型 
// 这里*L表示的就是首节点的地址
int InitSingleList(NodeAddress *head){
    *head = (NodeAddress)(malloc(sizeof(NewNode)));
    // 让首节点的指针指向NULL
    (*head) -> next = NULL;
    return 1;
}

// 获取链表长度
// 传入首节点地址，遍历循环 count++
int GetSingleLength(NodeAddress head){
    int count = 0;
    // 创建游标
    NodeAddress current = head;
    while (current -> next != NULL){
        count ++;
        current  = current -> next;
    }
    return count;
     
}

// 判断链表是否为空链表
int IsEmpty(NodeAddress head){
    // 创建游标
    NodeAddress current = head;
    if (current -> next != NULL){
        return 1;
    }else{
        return 0;
    }
}


// 清空链表
// 从头删除
// 传入头结点，从首节点开始删除
int ClearSingleList(NodeAddress *head){
    // 传入的头结点，需要获取首节点
    NodeAddress link_head = (*head) -> next;
    // 只要头结点一直存在，就一直删除头结点
    NodeAddress current = link_head; // 指向首节点
    while(link_head){
        // 指向首节点的下一位
        current = link_head -> next;
        // 释放首节点
        free(link_head);
        // 将游标重新赋值给首节点
        link_head = current;
    }
    // 全部删除完毕后 将头结点指向NULL
    (*head) -> next = NULL;
    return 1;
}

// 获取链表中的元素
// 传入头结点和序号index
int getElement(NodeAddress head,int index){
    // 创建游标
    NodeAddress current = head;
    // 创建计数器 
    int count = 0;
    
    while(count < index){
        current = current->next;
        count++;
    }
    return current->val;
}

// 遍历链表中的元素
int ListTraverse(NodeAddress head){
    // 创建游标
    NodeAddress current = head;
    
    while (current->next != NULL)
    {
        current = current -> next;
        printf("%d",current->val);
    }
    print("\n");
    return 1;
}

// 链表的插入
int ListInsert(NodeAddress head,int index,int value){
    // 创建游标
    NodeAddress current = head;
    
    // 遍历节点到指定index
    // 创建计数器
    for ( int count = 0; count < index; count++)
    {
        current = current -> next;
    }

    // 判断index是否过大溢出
    if (current->next == NULL){
        return 0;
    }else{
        // 创建要插入的结点
        NodeAddress InsertNode;
        // 动态分配内存
        InsertNode = (NodeAddress)malloc(sizeof(struct Node));
        // 赋值
        InsertNode -> val = value;
        // 将新插入的结点指向下一个节点
        InsertNode -> next = current -> next;
        // 将遍历到的结点指向当前节点
        current -> next = InsertNode;

    }

}

// 链表的删除  ???? 这里有问题
int ListDelete(NodeAddress head,int index){
    NodeAddress current = head;
    for ( int count = 0; count < index; count++)
    {
        current = current -> next;
    }
    if (current->next == NULL){
        return 0;
    }else{
        current  = current -> next ->next;
        free(current->next);
        return 1;
    }

}


