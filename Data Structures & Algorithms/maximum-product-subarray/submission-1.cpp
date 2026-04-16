class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> ans(n+1);
        ans[0] = {INT_MIN, 1, 1};
        for (int i = 1; i <= n; i++) {
            auto [globMax, currMax, currMin] = ans[i-1];
            int nextMax = max({nums[i-1], currMax * nums[i-1], currMin * nums[i-1]});
            int nextMin = min({nums[i-1], currMin * nums[i-1], currMax * nums[i-1]});
            ans[i] = {max({globMax, nextMax, nextMin}), nextMax, nextMin};
        }
        auto [globMax, currMax, currMin] = ans[n];
        return globMax;
    }
};
