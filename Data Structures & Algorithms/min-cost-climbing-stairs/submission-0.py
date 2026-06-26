class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        res = [0] * (len(cost) + 2)

        for i in range(0, len(cost)):
            res[i+2] = min(res[i+1], res[i]) + cost[i]

        return min(res[-1], res[-2])