class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        memo = {}

        if len(s3) != len(s1) + len(s2):
            return False

        def dp(i1, i2, next_is_s1):
            nonlocal s1, s2, s3
            if i1 == len(s1) and i2 == len(s2):
                return i1+i2 == len(s3)
            if (i1 == len(s1) and next_is_s1) or (i2 == len(s2) and not next_is_s1):
                return False
            if (i1 + i2 >= len(s3)):
                return False
            if (i1, i2, next_is_s1) in memo:
                return memo[(i1, i2, next_is_s1)]
            if next_is_s1:
                if s1[i1] != s3[i1+i2]:
                    memo[(i1, i2, True)] = False
                    return False
                else:
                    res = dp(i1+1, i2, True) or dp(i1+1, i2, False)
                    memo[(i1, i2, True)] = res
                    return res
            else:
                if s2[i2] != s3[i1+i2]:
                    memo[(i1, i2, False)] = False
                    return False
                else:
                    res = dp(i1, i2+1, True) or dp(i1, i2+1, False)
                    memo[(i1, i2, False)] = res
                    return res
            
        return dp(0, 0, True) or dp(0, 0, False)