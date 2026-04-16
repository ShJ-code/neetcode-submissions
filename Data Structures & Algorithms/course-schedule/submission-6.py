class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        adj = [[] for i in range(numCourses)]
        for crs, pre in prerequisites:
            indegree[crs] += 1
            adj[pre].append(crs)
        
        q = deque()
        for courseIdx in range(numCourses):
            if indegree[courseIdx] == 0:
                q.append(courseIdx)

        finish = 0
        while q:
            node = q.popleft()
            finish += 1
            for ngb in adj[node]:
                indegree[ngb] -= 1
                if indegree[ngb] == 0:
                    q.append(ngb)

        return finish == numCourses