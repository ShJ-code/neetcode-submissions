class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        count = {}

        for x in nums:
            count[x] = count.get(x, 0) + 1

        for i, a in enumerate(nums):
            count[a] -= 1
            if i and nums[i] == nums[i-1]:
                continue
            
            for j in range(i+1, len(nums)):
                count[nums[j]] -= 1
                if j-1>i and nums[j] == nums[j-1]:
                    continue
                target = -a - nums[j]
                if count.get(target, 0) != 0:
                    res.append([a, nums[j], target])
            
            for j in range(i+1, len(nums)):
                count[nums[j]] += 1

        return res