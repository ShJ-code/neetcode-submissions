class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for x, y in points:
            if len(heap) < k:
                heapq.heappush(heap, (-math.sqrt(x**2+y**2), x, y))
            else:
                max_dist, _, _ = heap[0]
                max_dist = -max_dist
                dist = math.sqrt(x**2+y**2)
                if dist < max_dist:
                    heapq.heappop(heap)
                    heapq.heappush(heap, (-dist, x, y))
        return [[heap[i][1], heap[i][2]] for i in range(k)]