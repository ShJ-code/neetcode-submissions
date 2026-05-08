class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()
        for i in range(9):
            seen.clear()
            for j in range(9):
                if board[i][j] != '.' and board[i][j] in seen:
                    return False
                seen.add(board[i][j])
        
        for j in range(9):
            seen.clear()
            for i in range(9):
                if board[i][j] != '.' and board[i][j] in seen:
                    return False
                seen.add(board[i][j])
        
        for i in range(3):
            for j in range(3):
                seen.clear()
                for k in range(9):
                    num = board[i*3+k//3][j*3+k%3]
                    if num != '.' and num in seen:
                        return False
                    seen.add(num)

        return True