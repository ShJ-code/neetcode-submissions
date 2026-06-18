class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INF = 2147483647

        frontier = deque()
        visited = set()
        frontier_set = set()

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    frontier.append((i, j, 0))
                    frontier_set.add((i, j))

        while frontier:
            x, y, dist = frontier.popleft()
            frontier_set.remove((x, y))
            visited.add((x, y))
            grid[x][y] = dist

            if x-1 >= 0 and grid[x-1][y] != -1 and (x-1, y) not in visited and (x-1, y) not in frontier_set:
                frontier.append((x-1, y, dist+1))
                frontier_set.add((x-1, y))

            if x+1 < len(grid) and grid[x+1][y] != -1 and (x+1, y) not in visited and (x+1, y) not in frontier_set:
                frontier.append((x+1, y, dist+1))
                frontier_set.add((x+1, y))
            
            if y-1 >= 0 and grid[x][y-1] != -1 and (x, y-1) not in visited and (x, y-1) not in frontier_set:
                frontier.append((x, y-1, dist+1))
                frontier_set.add((x, y-1))

            if y+1 < len(grid[0]) and grid[x][y+1] != -1 and (x, y+1) not in visited and (x, y+1) not in frontier_set:
                frontier.append((x, y+1, dist+1))
                frontier_set.add((x, y+1))