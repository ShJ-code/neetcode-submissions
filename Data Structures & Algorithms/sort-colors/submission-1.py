class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left, midd, right = 0, 0, len(nums)
        while midd < right:
            if nums[midd] == 0:
                nums[left], nums[midd] = nums[midd], nums[left]
                left += 1
                midd += 1
            elif nums[midd] == 1:
                midd += 1
            else:
                right -= 1
                nums[midd], nums[right] = nums[right], nums[midd]