class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(string) -> bool:
            for i in range(len(string) // 2):
                if string[i] != string[-i-1]:
                    return False
            return True
        
        res = []
        isValid = True
        partitions = [0]

        def isValid() -> bool:
            nonlocal partitions
            for i in range(len(partitions)-1):
                if not isPalindrome(s[partitions[i]:partitions[i+1]]):
                    return False
            if not isPalindrome(s[partitions[-1]:]):
                return False
            return True

        def buildResult() -> List[str]:
            nonlocal partitions
            result = []
            for i in range(len(partitions)-1):
                result.append(s[partitions[i]:partitions[i+1]])
            result.append(s[partitions[-1]:])
            return result

        def backtrack(i):
            nonlocal partitions
            if i >= len(s):
                if isValid():
                    res.append(buildResult())
                return
            
            partitions.append(i)
            backtrack(i+1)
            partitions.pop()
            backtrack(i+1)

        backtrack(1)
        return res