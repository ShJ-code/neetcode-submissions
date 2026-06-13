# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0

        # ancestor_stack = []
        # ancestor_max = {root: root.val}
        # curr, prev = root, dummy
        # ancestor = dummy
        # res = 0

        dummy = TreeNode(-101, root, None)
        ancestor_stack = [dummy]
        ancestor_max = {dummy: -101}
        curr = root
        ancestor = dummy
        res = 0

        while ancestor_stack or curr:
            if curr is not None:
                if curr.val >= ancestor_max[ancestor_stack[-1]]:
                    res += 1
                ancestor_max[curr] = max(ancestor_max[ancestor_stack[-1]], curr.val)
                ancestor_stack.append(curr)
                curr = curr.left
            else:
                curr = ancestor_stack[-1]
                if not curr.right or curr.right in ancestor_max:
                    ancestor_stack.pop()
                    curr = None
                else:
                    curr = curr.right

        return res