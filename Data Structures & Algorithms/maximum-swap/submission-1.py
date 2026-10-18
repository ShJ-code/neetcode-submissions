class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = list(str(num))
        last = {digit: i for i, digit in enumerate(digits)}
        for i, digit in enumerate(digits):
            for larger in range(9, int(digit), -1):
                j = last.get(str(larger), -1)
                if j > i:
                    digits[i], digits[j] = digits[j], digits[i]
                    return int(''.join(digits))
        return num