class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getKthFromEnd(self, head: ListNode, k: int):
        # 使用快慢指针举例来解决问题
        fast = head
        slow = head
        while k:
            fast = fast.next
            k -=1

        # 此时fast与slow相距k距离，两点向后平移
        while fast:
            fast = fast.next
            slow = slow.next
        return slow