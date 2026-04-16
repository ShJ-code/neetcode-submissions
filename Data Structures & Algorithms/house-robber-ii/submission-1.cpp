class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // When the size of nums is smaller than 4, we can only choose the
        // largest number
        if (n <= 3) {
            return *max_element(nums.begin(), nums.end());
        }

        vector<tuple<int, int, int, int>> ans(n-2);
        // Record four fields for each sublist from index 0 to i+2:
        // (1) Maximum amount one can rob if both ends are robbed
        // (2) ... if only front end is robbed
        // (3) ... if only back end is robbed
        // (4) ... if neither of the ends are robbed
        ans[0] = {max(nums[0] + nums[2], nums[1]), nums[0], nums[2], nums[1]};

        // For each subproblem, calculate the four fields for the next subproblem
        for (int i = 1; i < n-2; i++) {
            auto [a, b, c, d] = ans[i-1];
            ans[i] = {b+nums[i+2], max(a, b), d+nums[i+2], max(c, d)};
        }
        auto [a, b, c, d] = ans[n-3];
        return max({b, c, d});
    }
};
