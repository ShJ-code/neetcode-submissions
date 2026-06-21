import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        times_map = {}
        for u, v, t in times:
            if u in times_map:
                times_map[u][v] = t
            else:
                times_map[u] = {v : t}
        
        frontier = []
        heapq.heappush(frontier, (0, k))
        # frontier_set = {k: 0}
        # visited = set()
        min_time = {}
        
        while frontier:
            t, u = heapq.heappop(frontier)
            if u not in min_time:
                min_time[u] = t
                if u in times_map:
                    for v in times_map[u]:
                        if v not in min_time or min_time[v] > t + times_map[u][v]:
                            heapq.heappush(frontier, (t + times_map[u][v], v))

        print(len(min_time))
        if len(min_time) == n:
            return max(min_time.values())
        return -1