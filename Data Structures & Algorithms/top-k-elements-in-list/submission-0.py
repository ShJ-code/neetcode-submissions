class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        # Iterate through the nums list and update the dict count
        # Costs O(n)
        for num in nums:
            count[num] = 1 + count.get(num, 0)

        # Push the num and freq tuple into a heap, and pop smallest
        # elements when there is more than two different numbers
        heap = []
        for num in count.keys():
            heapq.heappush(heap, (count[num], num))
            if len(heap) > k:
                heapq.heappop(heap)

        # Push the number into the result list
        res = []
        for i in range(k):
            res.append(heapq.heappop(heap)[1])
        return res