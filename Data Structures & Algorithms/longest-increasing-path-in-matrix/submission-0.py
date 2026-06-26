class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        shortest = [[-1] * n for _ in range(m)]

        def dfs(x, y):
            nonlocal shortest, m, n
            if shortest[x][y] != -1:
                return shortest[x][y]
            
            directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
            res = 0
            for dx, dy in directions:
                if x+dx >= 0 and x+dx < m and y+dy >= 0 and y+dy < n and matrix[x+dx][y+dy] < matrix[x][y]:
                    res = max(res, dfs(x+dx, y+dy) + 1)
            shortest[x][y] = res
            return res

        longest_path = 0
        for i in range(m):
            for j in range(n):
                longest_path = max(longest_path, dfs(i, j))
        return longest_path + 1