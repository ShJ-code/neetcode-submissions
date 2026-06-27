class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        memo = [[-1] * (n+1) for _ in range(m+1)]

        def dp(x, y):
            nonlocal m, n, memo
            res = 0
            if y == n:
                memo[x][y] = 1
                return 1
            if x == m:
                memo[x][y] = 0
                return 0
            if memo[x][y] != -1:
                return memo[x][y]

            if s[x] == t[y]:
                memo[x][y] = dp(x+1, y+1) + dp(x+1, y)
                return memo[x][y]
            else:
                memo[x][y] = dp(x+1, y)
                return memo[x][y]

        return dp(0, 0)