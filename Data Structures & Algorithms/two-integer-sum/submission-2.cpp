class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t len = nums.size();
        for (size_t i = 0; i < len; i++) {
            for (size_t j = i+1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int>{i, j};
                }
            }
        }
    }
};
