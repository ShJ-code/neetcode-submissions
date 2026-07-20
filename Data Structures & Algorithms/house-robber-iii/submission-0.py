# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        memo = {}

        def dp(node, is_rob):
            nonlocal memo
            if (node, is_rob) in memo:
                return memo[(node, is_rob)]
            
            if not node.left:
                if not node.right:
                    if is_rob:
                        memo[(node, True)] = node.val
                    else:
                        memo[(node, False)] = 0
                else:
                    if is_rob:
                        memo[(node, True)] = node.val + dp(node.right, False)
                    else:
                        memo[(node, False)] = max(dp(node.right, True), dp(node.right, False))
            else:
                if not node.right:
                    if is_rob:
                        memo[(node, True)] = node.val + dp(node.left, False)
                    else:
                        memo[(node, False)] = max(dp(node.left, True), dp(node.left, False))
                else:
                    if is_rob:
                        memo[(node, True)] = node.val + dp(node.left, False) + dp(node.right, False)
                    else:
                        memo[(node, False)] = max(dp(node.left, True), dp(node.left, False)) + max(dp(node.right, True), dp(node.right, False))
            
            return memo[(node, is_rob)]
        
        return max(dp(root, True), dp(root, False))