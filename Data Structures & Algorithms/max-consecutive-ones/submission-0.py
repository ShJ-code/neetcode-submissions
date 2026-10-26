class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        res = 0
        curr_streak = 0
        for n in nums:
            if n == 1:
                curr_streak += 1
                res = max(res, curr_streak)
            else:
                curr_streak = 0
        return res