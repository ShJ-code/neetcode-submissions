# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        num_of_lists = len(lists)
        if num_of_lists == 0:
            return None
        none_cnt = 0
        for head in lists:
            if head is None:
                none_cnt += 1
        head = None
        while none_cnt < num_of_lists:
            min_idx = None
            for i in range(num_of_lists):
                if lists[i] is not None:
                    if min_idx is None or lists[i].val < lists[min_idx].val:
                        min_idx = i
            if head is None:
                head = lists[min_idx]
                lists[min_idx] = lists[min_idx].next
                curr = head
            else:
                curr.next = lists[min_idx]
                lists[min_idx] = lists[min_idx].next
                curr = curr.next
            if lists[min_idx] is None:
                none_cnt += 1
        return head