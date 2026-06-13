# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        ancestor_stack = []
        prev_max_height, curr_height = 0, 1
        curr, prev = root, None
        res = []
        
        while ancestor_stack or curr:
            if curr is not None:
                if curr_height > prev_max_height:
                    prev_max_height = curr_height
                    res.append(curr.val)
                ancestor_stack.append(curr)
                curr = curr.right
                curr_height += 1
            else:
                curr = ancestor_stack[-1]
                if not curr.left or prev == curr.left:
                    ancestor_stack.pop()
                    prev = curr
                    curr = None
                    curr_height -= 1
                else:
                    curr = curr.left

        return res