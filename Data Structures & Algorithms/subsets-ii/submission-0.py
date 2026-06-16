class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        freq_nums = Counter(nums)
        freq_keys = list(freq_nums)
        subsets = []
        subset = []

        def backtrack(i):
            nonlocal subset
            if i >= len(freq_keys):
                subsets.append(subset.copy())
                return
            
            for j in range(freq_nums[freq_keys[i]] + 1):
                added = [freq_keys[i]] * j
                subset += added
                backtrack(i+1)
                if j > 0:
                    subset = subset[:-j]

        backtrack(0)
        return subsets