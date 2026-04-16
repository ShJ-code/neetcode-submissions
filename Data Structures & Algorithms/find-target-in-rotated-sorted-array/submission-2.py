class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            middle = (left + right) // 2
            if nums[middle] == target:
                return middle
            elif nums[left] <= target <= nums[middle] or nums[middle] < nums[left] <= target or target < nums[middle] < nums[left]:
                right = middle - 1
            else:
                left = middle + 1
        return -1