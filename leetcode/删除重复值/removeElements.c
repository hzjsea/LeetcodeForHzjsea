// 2020-07-21 23:53:11


// 要求
// 删除链表中等于给定值 val 的所有节点。
// 示例:
// 输入: 1->2->6->3->4->5->6, val = 6
// 输出: 1->2->3->4->5

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

struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head == NULL) {
        return NULL;
    }
    if(head->val == val) {
        return head->next;
    } 
    
    // 创建一个游标
    struct ListNode *current = head;
    while((current->next!=NULL && current->next->val !=val)){
        current = current->next;
    }
    if (current->next !=NULL){
        current -> next = current->next->next;
    }
    return head;

}