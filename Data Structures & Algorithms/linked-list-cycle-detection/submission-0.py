# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast, slow = head, head
        while fast is not None and fast.next is not None:
            if slow == fast.next or slow == fast.next.next:
                return True
            fast = fast.next.next
            slow = slow.next
        return False