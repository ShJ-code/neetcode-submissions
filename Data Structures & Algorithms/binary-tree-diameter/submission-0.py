# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dHelper(root):
            if root == None:
                return 0, 0
            elif root.left == None and root.right == None:
                return 1, 1
            else:
                hl, ml = dHelper(root.left)
                hr, mr = dHelper(root.right)
                h = max(hl, hr) + 1
                return h, max(ml, mr, hl + hr + 1)
        
        _, m = dHelper(root)
        return m - 1