class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        original_x = x
        reversed = 0
        while x:
            reversed *= 10
            reversed += x % 10
            x //= 10
        return original_x == reversed