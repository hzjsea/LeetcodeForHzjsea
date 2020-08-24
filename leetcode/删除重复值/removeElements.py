class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int):
        cur = head
        if head is None:
            return 0
        if head.val == val:
            return head.next
    
        while (cur.next is not None and cur.next.val != val):
            cur = cur.next
        
        # 判断是不是最后一位，如果cur是最后一位的话 就没有next了，也就是不存在重复值、
        if cur.next is not None:
            cur.next = cur.next.next
        # cur.next = cur.next.next # 但这样也能通过..
        return head