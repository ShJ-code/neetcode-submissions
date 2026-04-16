class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        maxLen, maxLeft, maxRight = 0, -1, -1

        for i in range(n):
            # Odd length substrings
            left, right = i, i
            while left >= 0 and right < n:
                thisLen = right - left + 1
                if s[left] == s[right]:
                    if thisLen > maxLen:
                        maxLeft, maxRight = left, right
                        maxLen = thisLen
                    left -= 1
                    right += 1
                else:
                    break
        
            # Even length substrings
            left, right = i, i+1
            while left >= 0 and right < n:
                thisLen = right - left + 1
                if s[left] == s[right]:
                    if thisLen > maxLen:
                        maxLeft, maxRight = left, right
                        maxLen = thisLen
                    left -= 1
                    right += 1
                else:
                    break
        
        return s[maxLeft:maxRight+1]