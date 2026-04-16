class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set(nums)
        longest_streak = 0
        for x in seen:
            if x-1 not in seen:
                count = 1
                while x+count in seen:
                    count += 1
                longest_streak = max(longest_streak, count)
        return longest_streak