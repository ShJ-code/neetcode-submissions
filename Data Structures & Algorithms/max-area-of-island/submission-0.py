class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        maxArea, area = 0, 0

        def dfs(i, j):
            nonlocal maxArea, area
            if i < 0 or i >= m or j < 0 or j >= n:
                return
            else:
                if grid[i][j] == 1:
                    area += 1
                    grid[i][j] = 0
                    dfs(i-1, j)
                    dfs(i+1, j)
                    dfs(i, j+1)
                    dfs(i, j-1)


        for i in range(m):
            for j in range(n):
                dfs(i, j)
                maxArea = max(maxArea, area)
                area = 0

        return maxArea