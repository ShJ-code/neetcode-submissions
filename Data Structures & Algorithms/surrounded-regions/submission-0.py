class Solution:
    def solve(self, board: List[List[str]]) -> None:
        m, n = len(board), len(board[0])
        frontier = deque()
        frontier_set = set()

        for i in range(m):
            if board[i][0] == "O":
                frontier.append((i, 0))
                frontier_set.add((i, 0))
            if board[i][-1] == "O":
                frontier.append((i, n-1))
                frontier_set.add((i, n-1))
        
        for j in range(1, n-1):
            if board[0][j] == "O":
                frontier.append((0, j))
                frontier_set.add((0, j))
            if board[-1][j] == "O":
                frontier.append((m-1, j))
                frontier_set.add((m-1, j))

        while frontier:
            x, y = frontier.popleft()
            frontier_set.remove((x, y))
            if x != 0 and x != m-1 and y != 0 and y != n-1:
                board[x][y] = "K"

            if x-1 > 0 and y != 0 and y != n-1 and (x-1, y) not in frontier_set and board[x-1][y] == "O":
                frontier.append((x-1, y))
                frontier_set.add((x-1, y))
            
            if x+1 < m-1 and y != 0 and y != n-1 and (x+1, y) not in frontier_set and board[x+1][y] == "O":
                frontier.append((x+1, y))
                frontier_set.add((x+1, y))

            if y-1 > 0 and x != 0 and x != m-1 and (x, y-1) not in frontier_set and board[x][y-1] == "O":
                frontier.append((x, y-1))
                frontier_set.add((x, y-1))
            
            if y+1 < n-1 and x != 0 and x != n-1 and (x, y+1) not in frontier_set and board[x][y+1] == "O":
                frontier.append((x, y+1))
                frontier_set.add((x, y+1))

        for i in range(1, m-1):
            for j in range(1, n-1):
                if board[i][j] == "O":
                    board[i][j] = "X"
                elif board[i][j] == "K":
                    board[i][j] = "O"