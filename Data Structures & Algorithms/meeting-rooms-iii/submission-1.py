class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        available = [i for i in range(n)]
        used = []
        count = [0] * n

        for start, end in meetings:
            while used and used[0][0] < start:
                end_time, room = heapq.heappop(used)
                heapq.heappush(available, room)
            
            if not available:
                end_time, room = heapq.heappop(used)
                new_end = end_time + end - start
                heapq.heappush(used, (new_end, room))
                count[room] += 1
            else:
                room = heapq.heappop(available)
                heapq.heappush(used, (end, room))
                count[room] += 1
        
        return count.index(max(count))