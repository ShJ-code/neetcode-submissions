class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        incoming = {i: [] for i in range(n)}
        for s, d, price in flights:
            incoming[d].append((s, price))
        
        shortest_dist = {i: 100000 for i in range(n)}
        shortest_dist[src] = 0
        changed = True
        iteration = 0
        while changed:
            changed = False
            new_shortest_dist = {i: 100000 for i in range(n)}
            for node in range(n):
                original_shortest = shortest_dist[node]
                new_shortest = min(original_shortest, min((shortest_dist[i] + prc for i, prc in incoming[node]), default=float('inf')))
                new_shortest_dist[node] = new_shortest
                if not changed and new_shortest != original_shortest:
                    changed = True
            shortest_dist = new_shortest_dist
            iteration += 1
            if iteration >= k + 1:
                if shortest_dist[dst] < 100000:
                    return shortest_dist[dst]
                return -1
        if shortest_dist[dst] < 100000:
            return shortest_dist[dst]
        return -1