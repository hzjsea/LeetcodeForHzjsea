// 需求
// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
// 返回删除后的链表的头节点。


#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};



// struct ListNode* deleteNode(struct ListNode* head, int val){
//     if (!head || !(head->next)){
//         return head;
//     }

//     struct ListNode *current = head;
//     struct ListNode *last = head->next;
//     // 判断头部
//     if (current->val == val){
//         current = current->next;
//         last = last->next;
//     }
    
//     while(last->next != NULL){
//         if (last->val == val){
//             current->next = current ->next->next;
//             last  = last -> next;
//         }else{
//             current = current -> next;
//             last = last ->next;
//         }
    
//     }
//     return head;
// }



struct ListNode* deleteNode(struct ListNode* head, int val){
    if (!head || !(head->next)){
        return head;
    }

    struct ListNode *current = head;
    struct ListNode *pre = NULL;
    struct ListNode *last = head->next;

    while(last->next != NULL){
        if (last->val == val){
            current->next = current ->next->next;
            last  = last -> next;
        }else{
            current = current -> next;
            last = last ->next;
        }
    
    }
    return head;
}
