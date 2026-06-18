class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        grid_copy = [x.copy() for x in grid]

        frontier = deque()
        frontier_set = set()
        max_time = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    frontier.append((i, j, 0))
                    frontier_set.add((i, j))

        while frontier:
            x, y, time = frontier.popleft()
            max_time = max(max_time, time)
            grid_copy[x][y] = 2
            frontier_set.remove((x, y))

            if x-1 >= 0 and grid_copy[x-1][y] == 1 and (x-1, y) not in frontier_set:
                frontier.append((x-1, y, time+1))
                frontier_set.add((x-1, y))
            
            if x+1 < len(grid) and grid_copy[x+1][y] == 1 and (x+1, y) not in frontier_set:
                frontier.append((x+1, y, time+1))
                frontier_set.add((x+1, y))

            if y-1 >= 0 and grid_copy[x][y-1] == 1 and (x, y-1) not in frontier_set:
                frontier.append((x, y-1, time+1))
                frontier_set.add((x, y-1))

            if y+1 < len(grid[0]) and grid_copy[x][y+1] == 1 and (x, y+1) not in frontier_set:
                frontier.append((x, y+1, time+1))
                frontier_set.add((x, y+1))
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid_copy[i][j] == 1:
                    return -1

        return max_time