class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, max = 0;
        while (l < r) {
            if (heights[l] < heights[r]) {
                max = std::max({max, heights[l] * (r - l)});
                ++l;
            }
            else {
                max = std::max({max, heights[r] * (r - l)});
                --r;
            }
        }
        return max;
    }
};
