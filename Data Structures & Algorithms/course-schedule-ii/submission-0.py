class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0] * numCourses
        adj = [[] for i in range(numCourses)]
        for crs, pre in prerequisites:
            indegree[crs] += 1
            adj[pre].append(crs)

        q = deque()
        for courseIdx in range(numCourses):
            if indegree[courseIdx] == 0:
                q.append(courseIdx)

        res = []
        while q:
            node = q.popleft()
            res.append(node)
            for ngb in adj[node]:
                indegree[ngb] -= 1
                if indegree[ngb] == 0:
                    q.append(ngb)

        if len(res) == numCourses:
            return res
        return []