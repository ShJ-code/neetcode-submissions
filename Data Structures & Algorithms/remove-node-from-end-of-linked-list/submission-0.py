# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length, curr = 0, head
        while curr:
            length += 1
            curr = curr.next
        if n == length:
            return head.next
        curr = head
        for i in range(length - 1 - n):
            curr = curr.next
        curr.next = curr.next.next
        return head