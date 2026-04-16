class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indeg = [0] * numCourses
        adj = [[] for i in range(numCourses)]
        for src, dst in prerequisites:
            indeg[dst] += 1
            adj[src].append(dst)

        q = deque()
        for n in range(numCourses):
            if indeg[n] == 0:
                q.append(n)
        
        finish = 0
        while q:
            node = q.popleft()
            finish += 1
            for ngb in adj[node]:
                indeg[ngb] -= 1
                if indeg[ngb] == 0:
                    q.append(ngb)
        
        return finish == numCourses