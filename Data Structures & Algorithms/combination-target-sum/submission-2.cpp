class Solution {
    void dfs(vector<vector<int>>& res, int i, vector<int>& cur, int total, vector<int>& nums, int target) {
        if (total == target) {
            res.push_back(cur);
            return;
        }
        if (i >= nums.size() || total > target) {
            return;
        }

        // Two choices: include the current number, or move on.
        cur.push_back(nums[i]);
        dfs(res, i, cur, total + nums[i], nums, target);
        cur.pop_back();
        dfs(res, i+1, cur, total, nums, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, 0, cur, 0, nums, target);
        return res;
    }
};
