class Solution {
    void dfs(size_t i, size_t n, int target, std::vector<int>& candidates, std::vector<int>& sublist, std::vector<std::vector<int>>& res) {
        if (target == 0) {
            res.push_back(sublist);
            return;
        }
        if (i >= n || target < 0) {
            return;
        }
        sublist.push_back(candidates[i]);
        dfs(i+1, n, target - candidates[i], candidates, sublist, res);
        sublist.pop_back();
        while (i + 1 < n && candidates[i] == candidates[i + 1]) i++;
        dfs(i+1, n, target, candidates, sublist, res);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> sublist;
        std::vector<std::vector<int>> res;

        dfs(0, candidates.size(), target, candidates, sublist, res);
        return res;
    }
};