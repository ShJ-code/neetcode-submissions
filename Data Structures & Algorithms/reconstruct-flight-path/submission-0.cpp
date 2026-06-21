class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::unordered_map<std::string, std::deque<std::string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [src, dests] : adj) {
            std::sort(dests.rbegin(), dests.rend());
        }

        std::vector<std::string> res;
        dfs("JFK", adj, res);
        std::reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(const std::string& src, std::unordered_map<string, std::deque<std::string>>& adj, std::vector<std::string>& res) {
        while (!adj[src].empty()) {
            std::string dst = adj[src].back();
            adj[src].pop_back();
            dfs(dst, adj, res);
        }
        res.push_back(src);
    }
};
