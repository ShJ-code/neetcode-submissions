class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        memo = {}

        def dfs(idx, t):
            nonlocal nums
            if (idx, t) in memo:
                return memo[(idx, t)]
            if idx == 0:
                if t == 0:
                    return 1
                return 0
            
            return dfs(idx-1, t+nums[idx-1]) + dfs(idx-1, t-nums[idx-1])

        return dfs(len(nums), target)