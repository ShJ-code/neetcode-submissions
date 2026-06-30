class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0
        negative = n < 0
        n = abs(n)
        res = 1.0
        acc = x
        while n > 0:
            if n % 2:
                res *= acc
            n //= 2
            acc *= acc
        return 1/res if negative else res