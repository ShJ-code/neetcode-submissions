class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        maxl, maxr, water = [0] * n, [0] * n, [0] * n
        res = 0
        for i in range(1, n):
            maxl[i] = max(maxl[i-1], height[i-1])
            maxr[n-i-1] = max(maxr[n-i], height[n-i])
        
        for i in range(n):
            water[i] = max(min(maxl[i], maxr[i]) - height[i], 0)
            res += water[i]

        return res