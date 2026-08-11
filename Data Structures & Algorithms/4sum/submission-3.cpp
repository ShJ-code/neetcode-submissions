class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4UL) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        for (size_t i = 0UL; i < nums.size() - 3; ++i) {
            // if (target / 4 + 1 < nums[i]) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (size_t j = i+1; j < nums.size() - 2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                size_t l = j+1, r = nums.size() - 1;
                
                while (l < r) {
                    if ((long long)nums[i]+nums[j]+nums[l]+nums[r] == (long long)target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        while (l < r && nums[l] == nums[l-1]) ++l;
                        while (l < r && nums[r] == nums[r+1]) --r;
                    } else if ((long long)nums[i]+nums[j]+nums[l]+nums[r] < (long long)target) {
                        ++l;
                        while (l < r && nums[l] == nums[l-1]) ++l;
                    } else {
                        --r;
                        while (l < r && nums[r] == nums[r+1]) --r;
                    }
                }
            }
        }

        return ans;
    }
};