class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq = {}
        for x in s1:
            freq[x] = freq.get(x, 0) + 1
        n_reqs = len(freq)
        sat = 0
        if len(s1) > len(s2):
            return False
        window = {}
        for i in range(len(s1)):
            window[s2[i]] = window.get(s2[i], 0) + 1
            if window.get(s2[i], 0) == freq.get(s2[i], 0):
                sat += 1
            elif window.get(s2[i], 0) == freq.get(s2[i], 0) + 1:
                sat -= 1
            if sat == n_reqs:
                return True

        for i in range(len(s2)-len(s1)):
            window[s2[i]] -= 1
            if window.get(s2[i], 0) == freq.get(s2[i], 0):
                sat += 1
            elif window.get(s2[i], 0) == freq.get(s2[i], 0) - 1:
                sat -= 1
            window[s2[i+len(s1)]] = window.get(s2[i+len(s1)], 0) + 1
            if window.get(s2[i+len(s1)], 0) == freq.get(s2[i+len(s1)], 0):
                sat += 1
            elif window.get(s2[i+len(s1)], 0) == freq.get(s2[i+len(s1)], 0) + 1:
                sat -= 1
            if sat == n_reqs:
                return True

        return False