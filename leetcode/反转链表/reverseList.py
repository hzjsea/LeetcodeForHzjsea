class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head: ListNode):
        if head is None or head.next is None :
            return head
        cur = head
        pre = None

        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre