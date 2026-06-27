class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        memo = [[0] * (n+1) for _ in range(m+1)]

        for i in range(m+1):
            memo[i][0] = i
        for j in range(1, n+1):
            memo[0][j] = j

        for i in range(2, m+n+1): # From x+y=2 to x+y=m+n
            for x in range(min(i-1, m), max(0, i-n-1), -1): # 0 <= y <= n => i-n <= x <= i
                y = i - x
                if not 0 <= y <= n:
                    break
                if word1[x-1] == word2[y-1]:
                    memo[x][y] = memo[x-1][y-1]
                else:
                    memo[x][y] = min(memo[x-1][y], memo[x-1][y-1], memo[x][y-1]) + 1

        return memo[m][n]