class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack = []
        for i, x in enumerate(nums):
            if not stack or nums[stack[-1]] > x:
                stack.append(i)
        best = 0
        for j in range(len(nums)-1, -1, -1):
            while stack and nums[stack[-1]] <= nums[j]:
                i = stack.pop()
                best = max(best, j-i)
        return best
