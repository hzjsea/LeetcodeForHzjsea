#include <stdio.h>
#include <stdlib.h>


// 单链表的操作
// 增删改查


// 创建一个节点模板
struct Node
{
    int val;
    struct Node *next;
};

typedef  struct Node newNode;  // 定义一个新的节点
typedef  struct Node *nodeAddress; // 返回一个节点的地址
typedef  nodeAddress *firstNode; // 定义一个头节点

// 声明一个节点的流程
// 1. 传入一个节点的地址 nodeAddress node
// 2. 给这个节点动态分配内存 并且强转 node = (nodeAddress)malloc(sizeof(strcut Node))
// 3. 给这个节点分配内容 node -> value = 1
// 4. 给这个节点分配指针 node -> next = NULL
int InitNode(){
    nodeAddress node;
    node = (nodeAddress)malloc(sizeof(struct Node));
    node -> val = 1;
    node -> next = NULL; 
    return 0;
}

// 初始化链表
// 头节点 -> NULL

int InitSingList(nodeAddress *firstNode){
    *firstNode = (nodeAddress)malloc(sizeof(struct Node));
    (*firstNode) -> next = NULL;
    (*firstNode) -> val = 100;
    return 0;
}

// 从链表尾部插入
int AddSingListLast(nodeAddress head,int val){
    // 需要遍历得到最后一个节点
    nodeAddress current;
    current = head;
    while(current-> next != NULL){
        current = current -> next;
    }
    
    nodeAddress node;
    node = (nodeAddress)malloc(sizeof(struct Node));
    node -> val = val;
    node -> next = NULL;
    current -> next = node;
    return 0;
}

// 从链表头部插入数据 
int AddSingListHead(nodeAddress *head,int val){
    nodeAddress current = *head;
    nodeAddress node;
    node = (nodeAddress)malloc(sizeof(struct Node));
    node -> val = val;
    // 先考虑单节点的可能
    if (current -> next == NULL){
        current -> next = node;
        node -> next = NULL;
    }else{
        // current -> next = node;
        // node -> next = current -> next -> next; 
        // current -> next -> next = NULL;
        node -> next = current -> next;
        current -> next = node;
    }
    return 0;
} 

// 从尾部删除
int DeleteSingListLast(nodeAddress head){
   nodeAddress current;
    current = head;
    while(current-> next -> next != NULL){
        current = current -> next;
    } 
    current -> next = NULL;
    free(current->next);
    return 0;
}

// 遍历节点
int TraverseSingList(nodeAddress head){
    nodeAddress current = head -> next;
    while (current->next != NULL)
    {
        printf("%d\n",current->val);
        current = current -> next;
    }
    return 0;
}

// 输出链表长度
int LengthSingList(nodeAddress head){
    nodeAddress current = head;
    int count = 0;
    while (current->next != NULL)
    {
        current = current -> next;
        count ++;
    }
    printf("%d\n",count);
    return count;
}


int main(){
    //  创建一个头节点
    nodeAddress first;
    InitSingList(&first); 
    AddSingListHead(&first,1);
    AddSingListHead(&first,1);
    AddSingListHead(&first,1);
    AddSingListHead(&first,1);
    AddSingListHead(&first,1);

    TraverseSingList(first);

    LengthSingList(first);

    return 0;
}
