class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0
        negative = n < 0
        n = abs(n)
        stack = []
        res = x
        while n > 1:
            rem = n % 2
            n //= 2
            if rem:
                stack.append(res)
            res *= res
        while stack:
            res *= stack.pop()
        return 1/res if negative else res