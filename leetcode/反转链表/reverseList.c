
// 2020-07-21 23:53:11

// 要求
// 反转一个单链表。
// 示例:
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 进阶:
// 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

// 解题思路 
// 使用三指针 + 哨兵节点来解决
// 哨兵节点主要是在头结点前面放置一个节点
// 三指针分别表示  当前节点current 上一节点 pre  下一临时节点tmp(过渡使用)
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){

    // 创建一个哨兵节点 指向null
    struct ListNode *pre = NULL;
    // 创建一个游标节点 初始位置为head
    struct ListNode *current = head;

    // 创建一个tmp节点
    struct ListNode *tmp = NULL;

    // 判断，如果链表为空链表或者只有一个节点，则返回头结点
    if (!head || head->next == NULL){
        return head;
    }

    // 利用迭代来解决问题
    // 迭代停止的终止条件为current->next = NULL or 0
    while(current){
        tmp =   current->next;
        current -> next  = pre;
        pre = current;
        current = tmp;
    }
    return head;
}



