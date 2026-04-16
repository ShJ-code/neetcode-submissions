class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int idx = 0, maxReach = 0;
        while (idx < n-1) {
            if (idx > maxReach)
                return false;
            maxReach = max(maxReach, nums[idx] + idx);
            idx++;
        }
        if (idx > maxReach)
            return false;
        return true;
    }
};
