# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if l1 is None and l2 is None:
            return None
        res = ListNode()
        curr = res
        carry = 0
        prev = None
        while l1 is not None or l2 is not None or carry:
            l1Val = l1.val if l1 else 0
            l2Val = l2.val if l2 else 0
            this = l1Val + l2Val + carry
            curr.val = this % 10
            carry = this // 10
            l1 = l1.next if l1 is not None else l1
            l2 = l2.next if l2 is not None else l2
            prev = curr
            curr.next = ListNode()
            curr = curr.next

        prev.next = None
        return res