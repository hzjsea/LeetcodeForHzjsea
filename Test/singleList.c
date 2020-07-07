#include<stdio.h>
#include<stdlib.h>

// 空链表的形式
// -->NUll 
// head

// 多个节点的链表形式
// ---->[p1]---->[p2]...---->[pn]---->[NULL]
// head p1->next p2->next  pn->next --> NUll


// 创建节点
// 一个节点包括 【数据内容，指向下一个节点的指针】
struct Node
{
    int data;
    struct Node *next;   // 指向下一个节点的指针  或者说这一个节点的地址 叫做next 类型是Node
};

typedef struct Node LinkList; // 创建一个别名   


// 创建一个节点类型
struct  Node *a; // 节点名字叫做a 节点类型是Node
LinkList *a; // 节点名字叫做a  节点类型是Node



// 创建一个n个节点的链表

LinkList *create(int n){
    LinkList *head, *node,*end; // 定义头结点，普通节点，尾节点指向的位置
    head = (LinkList *)malloc(sizeof(struct Node));  //做一个强转  == > head = (LinkList *)malloc(sizeof(LinkList)); // 动态分配内存
    end = head;  // 初始化头结点和尾节点指向的位置为空；
    for (int i = 0; i < n; i++)
    {
        node =  (LinkList *)malloc(sizeof(LinkList));
        scanf("%d", &node->data);
        end->next = node ; // 每次添加一个几点，都让end的指针往后移动一位 也就是
        end = node ; // 结束之后，让end变成最后一个节点   在这里end相当于一个游标
    }
    end->next = NULL;
    return head;
}

// 修改链表节点值
void change(LinkList *list,int n) { // n为节点 list为类型为Node的值
    LinkList *t = list;
    int i = 0;
    while (i< n && t != NULL) {
        t = t->next;
        i++;
    }
    if (t != NULL) {
		puts("输入要修改的值");
		scanf("%d", &t->data);
	}
	else {
		puts("节点不存在");
	}
}

// 删除链表的结点
void delete(LinkList *list ,int n){
    LinkList *t  = list,*in;


    int i = 0;
	while (i < n && t != NULL) {
		in = t;
		t = t->next;                    // 跳转到需要删除的结点
		i++;
	}

    if (t != NULL) {
        in->next = t->next;
        free(t);
    }
    else
    {
        puts("结点不存在");
    }

}

// 插入链表节点

// 输出链表
int main(){
    LinkList *h ;
    while(h->next != NULL){
        h = h -> next;
        printf("%d ",h->data);
    }
    return 0;
}


