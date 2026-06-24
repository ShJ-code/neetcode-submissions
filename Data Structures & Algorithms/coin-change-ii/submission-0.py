class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        combinations = {}
        def dfs(i, j):
            if i < 0 or j < 0 or i >= len(coins) or j > amount:
                return 0
            if (i, j) in combinations:
                return combinations[(i, j)]

            if j == 0:
                combinations[(i, j)] = 1
                return combinations[(i, j)]
            res = 0
            for m in range(i, len(coins)):
                if j - coins[m] >= 0:
                    res += dfs(m, j - coins[m])
            combinations[(i, j)] = res
            return res
            
            
        return dfs(0, amount)