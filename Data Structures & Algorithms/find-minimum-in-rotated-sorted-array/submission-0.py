class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] <= nums[-1]:
            return nums[0]
        left, right = 0, len(nums) - 1
        while left < right - 1:
            middle = (left + right) // 2
            if nums[middle] > nums[left]:
                left = middle
            else:
                right = middle
        return nums[right]