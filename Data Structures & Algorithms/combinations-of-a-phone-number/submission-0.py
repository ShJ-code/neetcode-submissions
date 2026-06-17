class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        digitToChar = {
            '2': ('a', 'b', 'c'),
            '3': ('d', 'e', 'f'),
            '4': ('g', 'h', 'i'),
            '5': ('j', 'k', 'l'),
            '6': ('m', 'n', 'o'),
            '7': ('p', 'q', 'r', 's'),
            '8': ('t', 'u', 'v'),
            '9': ('w', 'x', 'y', 'z')
        }

        s = []
        res = []

        def backtrack(i):
            if i >= len(digits):
                res.append(''.join(s))
                return

            for c in digitToChar[digits[i]]:
                s.append(c)
                backtrack(i+1)
                s.pop()

        backtrack(0)
        return res