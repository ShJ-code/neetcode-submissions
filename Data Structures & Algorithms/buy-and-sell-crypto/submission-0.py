class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        curr_min, res = prices[0], 0
        for i in range(1, len(prices)):
            curr_min = min(curr_min, prices[i])
            res = max(res, prices[i] - curr_min)
        return res