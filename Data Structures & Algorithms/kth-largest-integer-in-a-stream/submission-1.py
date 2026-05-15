class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.topk, self.other, self.k = [], [], k
        for x in nums:
            self.add(x)


    def add(self, val: int) -> int:
        if len(self.topk) < self.k:
            heapq.heappush(self.topk, val)
        else:
            if self.topk[0] < val:
                heapq.heappush(self.other, -heapq.heappop(self.topk))
                heapq.heappush(self.topk, val)
            else:
                heapq.heappush(self.other, -val)
        return self.topk[0]
