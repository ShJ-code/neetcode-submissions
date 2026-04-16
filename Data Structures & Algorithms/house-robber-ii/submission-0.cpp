class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) {
            return *max_element(nums.begin(), nums.end());
        }
        vector<tuple<int, int, int, int>> ans(n-2);
        ans[0] = {max(nums[0] + nums[2], nums[1]), nums[0], nums[2], nums[1]};
        for (int i = 1; i < n-2; i++) {
            auto [a, b, c, d] = ans[i-1];
            ans[i] = {b+nums[i+2], max(a, b), d+nums[i+2], max(c, d)};
        }
        auto [a, b, c, d] = ans[n-3];
        return max({b, c, d});
    }
};
