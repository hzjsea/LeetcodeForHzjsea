// 删除排序链表中的重复元素
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL && current->next !=NULL)
    // while (current->next != NULL && current != NULL)
    {
        if (current->val == current->next->val)
        {
            struct ListNode *tmp = current->next;
            current->next = tmp->next;
            tmp->next = NULL;
            free(tmp);
        }else
        {
            current = current->next;
        }
    }
    return head;
}