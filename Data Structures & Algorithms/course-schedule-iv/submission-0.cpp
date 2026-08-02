class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> isPrereq;

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.assign(numCourses, vector<int>());
        isPrereq.assign(numCourses, vector<int>(numCourses, -1));

        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            isPrereq[pre[1]][pre[0]] = 1;
        }

        vector<bool> res;
        for (auto& query : queries) {
            res.push_back(dfs(query[1], query[0]));
        }
        return res;
    }

private:
    bool dfs(int crs, int prereq) {
        if (isPrereq[crs][prereq] != -1) {
            return isPrereq[crs][prereq] == 1;
        }
        for (int pre : adj[crs]) {
            if (pre == prereq || dfs(pre, prereq)) {
                isPrereq[crs][prereq] = 1;
                return true;
            }
        }
        isPrereq[crs][prereq] = 0;
        return false;
    }
};