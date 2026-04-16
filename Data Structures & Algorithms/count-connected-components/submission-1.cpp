class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);

        // Iterate through every edge in the edge list, construct the
        // adjacency list representation.
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // For every possible node, start a bfs search from the node
        // (mark every node connected as visited). If the node is not
        // visited, increase the connected components counter(res).
        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                bfs(adj, visit, node);
                res++;
            }
        }
        return res;
    }

private:
    // Standard bfs method, passing adjacency list, visited set, and
    // start node as parameter.
    void bfs(vector<vector<int>>& adj, vector<bool>& visit, int node) {
        queue<int> q;
        q.push(node);
        visit[node] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nei : adj[cur]) {
                if (!visit[nei]) {
                    visit[nei] = true;
                    q.push(nei);
                }
            }
        }
    }
};
