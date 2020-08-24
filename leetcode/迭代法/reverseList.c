#include<stdio.h>
#include<stdlib.h>

// 这里用反转链表来介绍迭代法
// 反转一个单链表。
// 示例:
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL

// 迭代法关键点就是游标指针的平移来标记当前位置
// 使用三指针来完成前后节点的替换

// 1. 先判断终止条件 (头节点不存在或者头结点的下一跳为空则都返回头结点)


struct Node{
    int val;
    struct Node *next;
};


struct ListNode* reverseList(struct ListNode* head){

}