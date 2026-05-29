class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        def clean_arr(ns):
            for i in range(len(ns)):
                ns[i] = abs(ns[i])

        for i in range(len(nums)):
            if nums[abs(nums[i])] < 0:
                clean_arr(nums)
                return abs(nums[i])
            else:
                nums[abs(nums[i])] *= -1
        
        return None