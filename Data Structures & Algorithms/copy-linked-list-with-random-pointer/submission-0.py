"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head == None:
            return None
        dummy = Node(0)
        curr = head
        nodeDict = {}
        idx = 0;
        while curr != None:
            nodeDict[curr] = idx
            # else:
            #     nodeDict.get(curr.random, []).append(idx)
            idx += 1
            curr = curr.next
        
        n = idx
        newHead = Node(head.val)
        nodeIdxDict = {0: newHead}
        curr = head.next
        newCurr = newHead
        idx = 0
        while curr != None:
            idx += 1
            newCurr.next = Node(curr.val)
            curr = curr.next
            newCurr = newCurr.next
            nodeIdxDict[idx] = newCurr
        
        curr = head
        newCurr = newHead
        idx = 0
        while curr != None:
            thisRandom = curr.random
            if thisRandom is not None:
                newCurr.random = nodeIdxDict[nodeDict[thisRandom]]
            curr = curr.next
            newCurr = newCurr.next
        return newHead