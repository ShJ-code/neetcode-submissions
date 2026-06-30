class Solution:
    def isHappy(self, n: int) -> bool:
        def cal(num):
            res = 0
            while num:
                res += (num % 10) ** 2
                num //= 10
            return res

        seen = set()
        next = cal(n)
        while next not in seen:
            if next == 1:
                return True
            seen.add(next)
            next = cal(next)
        return False