class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (size_t i = 0UL; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k += 1;
            }
        }
        return k;
    }
};