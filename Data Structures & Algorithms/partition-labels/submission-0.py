class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        c = Counter(s)
        substr = set()
        currIdx = 0
        res = []
        next = 0

        while currIdx < len(s):
            c[s[currIdx]] -= 1
            if s[currIdx] not in substr:
                substr.add(s[currIdx])
            next += 1
            if c[s[currIdx]] == 0 and s[currIdx] in substr:
                substr.remove(s[currIdx])
                if not substr:
                    res.append(next)
                    next = 0
            currIdx += 1

        return res