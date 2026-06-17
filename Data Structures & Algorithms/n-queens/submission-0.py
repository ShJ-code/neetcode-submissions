class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        available = [[True] * n for _ in range(n)]
        res = []
        coordinates = []

        def toResult(cord):
            nonlocal n
            assert len(cord) == n
            result = []
            for _, j in cord:
                next = '.' * j + 'Q' + '.' * (n-j-1)
                result.append(next)
            return result

        def update(i, j) -> List[tuple[int, int]]:
            nonlocal available
            nonlocal n
            ulist = []
            for k in range(i+1, n):
                if available[k][j]:
                    ulist.append((k, j))
                    available[k][j] = False
                if j - (k - i) >= 0 and available[k][j-k+i]:
                    ulist.append((k, j-k+i))
                    available[k][j-k+i] = False
                if j + (k - i) < n and available[k][j+k-i]:
                    ulist.append((k, j+k-i))
                    available[k][j+k-i] = False
            return ulist
            
        def revert(ul):
            nonlocal available
            for i, j in ul:
                available[i][j] = True

        def backtrack(i):
            nonlocal available
            if i >= n:
                res.append(toResult(coordinates))
                return
            
            for j in range(n):
                if available[i][j]:
                    coordinates.append((i, j))
                    ulist = update(i, j)
                    backtrack(i+1)
                    revert(ulist)
                    coordinates.pop()

        backtrack(0)
        return res