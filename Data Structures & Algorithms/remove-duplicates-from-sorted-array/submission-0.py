class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        res=1
        last_num=nums[0]
        curr_ptr=1
        for i in range(1, len(nums)):
            if nums[i]==last_num:
                continue
            last_num=nums[i]
            nums[curr_ptr]=nums[i]
            curr_ptr += 1
            res += 1
        return res