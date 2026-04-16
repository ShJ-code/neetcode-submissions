class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complement = {}
        for i in range(len(nums)):
            if nums[i] in complement:
                return [complement[nums[i]], i]
            if not target - nums[i] in complement:
                complement[target - nums[i]] = i