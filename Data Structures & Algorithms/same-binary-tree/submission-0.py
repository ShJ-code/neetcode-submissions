# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if (p or q) and (not p or not q):
            return False
        if not p and not q:
            return True
        stack_p, stack_q = [p], [q]
        while stack_p and stack_q:
            p_top, q_top = stack_p.pop(), stack_q.pop()
            # if p_top is None and q_top is None:
            #     continue
            # if (p_top or q_top) and (not p_top or not q_top):
            #     return False
            if p_top.val != q_top.val:
                return False
            p_top_left, p_top_right = p_top.left, p_top.right
            q_top_left, q_top_right = q_top.left, q_top.right
            if (p_top_left or q_top_left) and (not p_top_left or not q_top_left):
                return False
            if (p_top_right or q_top_right) and (not p_top_right or not q_top_right):
                return False
            if p_top_left is not None and q_top_left is not None:
                stack_p.append(p_top_left)
                stack_q.append(q_top_left)
            if p_top_right is not None and q_top_right is not None:
                stack_p.append(p_top_right)
                stack_q.append(q_top_right)
        if stack_p or stack_q:
            return False
        return True