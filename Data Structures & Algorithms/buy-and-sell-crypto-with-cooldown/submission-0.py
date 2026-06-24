class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        memoizer = {}

        def dfs(i, holding):
            nonlocal memoizer
            if i >= len(prices):
                return 0
            if (i, holding) in memoizer:
                return memoizer[(i, holding)]

            cooldown = dfs(i+1, holding)
            if holding:
                sell = dfs(i+2, False) + prices[i]
                memoizer[(i, holding)] = max(sell, cooldown)
                return memoizer[(i, holding)]
            else:
                buy = dfs(i+1, True) - prices[i]
                memoizer[(i, holding)] = max(buy, cooldown)
                return memoizer[(i, holding)]

        return dfs(0, False)