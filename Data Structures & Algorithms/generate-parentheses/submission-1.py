class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        curr_str = []
        cumul = 0
        res = []

        def backtrack(i):
            nonlocal cumul
            if i >= n * 2 and cumul == 0:
                res.append(''.join(curr_str))
                return

            if cumul + 1 <= 2 * n - i - 1:
                curr_str.append('(')
                cumul += 1
                backtrack(i+1)
                curr_str.pop()
                cumul -= 1

            if cumul > 0:
                curr_str.append(')')
                cumul -= 1
                backtrack(i+1)
                curr_str.pop()
                cumul += 1

        backtrack(0)
        return res