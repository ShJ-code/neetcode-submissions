class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int acc = 0, n = nums.size();
        for (int i = 0; i <= n; i++)
            acc ^= i;
        for (int x : nums)
            acc ^= x;
        return acc;
    }
};
