class Solution {
private:
    vector<int> subsetSum;
    int target = 0;
    int k = 0;

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k <= 0 || nums.empty()) {
            return false;
        }

        int numsSum = accumulate(nums.begin(), nums.end(), 0);

        if (numsSum % k != 0) {
            return false;
        }

        target = numsSum / k;

        if (*max_element(nums.begin(), nums.end()) > target) {
            return false;
        }

        // 先放较大的数字，可以更早发现不可能的情况
        sort(nums.rbegin(), nums.rend());

        subsetSum.assign(k, 0);
        this->k = k;

        return backtrack(0, nums);
    }

private:
    bool backtrack(size_t idx, const vector<int>& nums) {
        // 所有数字都已经成功放入桶中
        if (idx == nums.size()) {
            return true;
        }

        for (int i = 0; i < k; ++i) {
            // 当前桶放不下 nums[idx]
            if (subsetSum[i] > target - nums[idx]) {
                continue;
            }

            subsetSum[i] += nums[idx];

            if (backtrack(idx + 1, nums)) {
                return true;
            }

            subsetSum[i] -= nums[idx];

            // 所有空桶彼此等价，只需尝试一个
            if (subsetSum[i] == 0) {
                break;
            }
        }

        return false;
    }
};