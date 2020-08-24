#include <stdio.h>
#include <stdlib.h>

// 没有表头的，初始节点就是head
// C语言描述里面是用的这种

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;
typedef struct Node *PointNode;



// 头结点  在单链表的第一个结点之前附加一个结点，称为头结点。头结点的Data域可以不设任何信息，也可以记录表长等相关信息。若链表是带有头结点的，则头指针指向头结点的存储位置
// 头指针   通常使用“头指针”来标识一个链表，如单链表L，头指针为NULL的时表示一个空链表。链表非空时，头指针指向的是第一个结点的存储位置


// 如何表示一个头指针
// struct Node *PointNode 


// ====== 初始化空链表  头指针 == NULL
// 不带头结点写法
// 初始化空链表 
// 1. 传入头指针  头指针代表的是指针指向的下一个结点的存储位置
// 2. 头指针为空 则为空表
PointNode InitList(PointNode headPoint)
{
    headPoint = NULL;
    return headPoint;
}


// ====== 初始化空链表  头指针——> 头结点 == NULL
// 带头结点写法
// 初始化空链表
// 1. 传入头指针   头指针代表的是指针指向的的下一个结点的存储位置
// 2. 头指针的下一跳为头节点 头结点的
PointNode InitList2(PointNode headPoint){
    headPoint  = (PointNode)malloc(sizeof(struct Node));
    headPoint -> next = NULL;
    return headPoint;
}


// 不带头结点写法
// 判断是否为空表 判断第一个普通节点是否为空
// 1. 传入头指针
// 2. 如果头指针为空，则表示为空表
// 空则返回0 ,不空则返回1
int IsEmpty(PointNode headPoint){
    if (headPoint == NULL){
        return 0;
    }else
    {
        return 1;
    }
    
}

// 带头结点写法
// 判断是否为空表  判断头结点是否为空
// 1. 传入头指针  头指针用来识别一个链表
// 2. 如果头结点是空的话，那该表为空链表
int IsEmpty2(PointNode headPoint){
    PointNode head = headPoint -> next;
    if (head == NULL){
        return 0;
    }else
    {
        return 1;
    }
    
}


// 没有头结点写法
// 创建一个单节点的表
// 1. 传入一个空链表，用头指针识别 以及 一个值
// 2. 创建一个新的节点 分配内存并且赋值
// 3. 让头指针指向新的节点，并且新的节点指向NULL
// 4. 返回一个头指针类型 
PointNode CreateNodeList(PointNode headPoint,int val){
    PointNode newNode = (PointNode)malloc(sizeof(struct Node));
    newNode -> next = NULL;
    newNode -> data = val;

    headPoint -> next = newNode;
    return headPoint ;
    
}

// 有头结点的写法
// 创建一个单节点的表
// 1. 传入一个空链表，用头指针识别以及一个值
// 2. 创建一个新的节点，分配内存并且赋值
// 3. 让头节点指向新的节点，并且新的节点指向NULL
// 返回一个指针类型
PointNode CreateNodeList2(PointNode headPoint,int val){
    // 根据头指针获取头结点
    PointNode head = headPoint -> next;
    // 创建新的结点
    PointNode newnode = (PointNode)malloc(sizeof(struct Node));
    newnode -> next  = NULL;
    newnode -> data = val;
    head -> next = newnode;

    return headPoint;
}




int main()
{
    // 创建一个头结点
    PointNode headPoint;
    PointNode hp = InitList(headPoint);
    int res = IsEmpty(hp);
    printf("%d",res);

    // 带头结点
    PointNode headPoint2;
    PointNode hp2 = InitList2(headPoint2);
    int res2 = IsEmpty2(hp2);
    printf("%d",res2);

}
