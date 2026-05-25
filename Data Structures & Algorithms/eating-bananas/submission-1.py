class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def cal_time(banana, speed):
            return (banana - 1) // speed + 1

        max_banana = max(piles)
        left, right = 1, max_banana + 1
        while left < right:
            mid = (left + right) // 2
            time_needed = sum(cal_time(x, mid) for x in piles)
            if time_needed <= h:
                right = mid
            else:
                left = mid + 1
        return left