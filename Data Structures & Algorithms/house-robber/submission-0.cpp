class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        vector<pair<int, int>> ans(n);
        ans[0] = {nums[0], 0};
        for (int i = 1; i < n; i++) {
            auto [r1, r2] = ans[i-1];
            ans[i] = {max(r1, r2+nums[i]), max(r1, r2)};
        }
        auto [r1, r2] = ans[n-1];
        return r1;
    }
};
