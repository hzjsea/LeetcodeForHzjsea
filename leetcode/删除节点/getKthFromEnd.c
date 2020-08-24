

// 2020-07-21 23:50:40


// 解题要求
// 链表中倒数第k个节点
// 给定一个链表: 1->2->3->4->5, 和 k = 2.
// 返回链表 4->5.


// 解题思路
// 使用快慢指针，得出K的差距
// 当快指针的值=NULL的时候，慢指针所在节点就是倒数K的结点
// 需要返回的是慢指针所在节点的地址



#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;

};

// 为什么这里pre是不等于0
// 如果没有引入库的话,就是只能用0来做判断

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if(!head || k<=0){
        return NULL;
    }

    // 创建两个节点
    struct ListNode *pre = head;
    struct ListNode *last = head;

    // 创建快慢指针的差距
    while(k){
        last = last->next;
        // 判断是否只有一个节点
        if (!last && k !=1){
            return NULL;
        }
        k--;
    }
    // 让快慢指针不断向后跳，直到快指针=NUll
    while(last!=0){
        pre = pre->next;
        last = last->next;
    }
    return pre;

    // while (pre!=NULL){
    //     pre = pre->next;
    //     last = last->next;
    // }
    // return pre;


}