class Solution {
    vector<vector<int>> res;
    void dfs(int i, vector<int>& cur, int total, vector<int>& nums, int target) {
        if (total == target) {
            res.push_back(cur);
            return;
        }

        // Loop through all next choices
        for (int j = i; j < nums.size(); j++) {
            if (total + nums[j] > target)
                return;
            cur.push_back(nums[j]);
            dfs(j, cur, total + nums[j], nums, target);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(0, cur, 0, nums, target);
        return res;
    }
};
