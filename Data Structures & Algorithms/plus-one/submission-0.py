class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 2
        digits[-1] += 1
        carry = 1 if digits[-1] >= 10 else 0
        if digits[-1] >= 10:
            digits[-1] %= 10
        while i >= 0 and carry:
            digits[i] += carry
            carry = 1 if digits[i] >= 10 else 0
            digits[i] %= 10
            i -= 1
        if carry:
            digits = [1] + digits
        return digits