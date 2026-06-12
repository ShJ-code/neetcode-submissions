# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        curr = dummy
        while True:
            # Record starting node
            start = curr

            # Step k nodes to see if we reach the end
            for i in range(k):
                if curr.next is None:
                    # No need to modify tails
                    return dummy.next
                curr = curr.next
            
            # We are at the end of the next k nodes
            last, last_next = curr, curr.next
            start_next = start.next
            curr, prev = start_next.next, start_next

            # Now reverse the k-1 nodes starting at second
            for i in range(k-1):
                next_curr = curr.next
                curr.next = prev
                curr, prev = next_curr, curr
            
            # We still need to reset the pointers at the start
            # and the end
            start_next.next = last_next
            start.next = last

            # Set curr to the last node of the current list
            curr = start_next