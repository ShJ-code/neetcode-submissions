class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]

        for n in nums:
            l = len(res)
            for i in range(l):
                res.append(res[i] + [n])

        return res