class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, currMin = 0, currMax = INT_MIN;
        int allNeg = true;
        for (int x : nums) {
            if (x >= 0)
                allNeg = false;
            currSum += x;
            if (currSum < currMin)
                currMin = currSum;
            if (currSum > currMax)
                currMax = currSum;
        }
        return allNeg ? *max_element(nums.begin(), nums.end()) : currMax - currMin;
    }
};
