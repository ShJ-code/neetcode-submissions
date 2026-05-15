class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::vector<int> new_heights(heights.size()+2, 0);
        for (size_t i = 0; i < heights.size(); i++) {
            new_heights[i+1] = heights[i];
        }
        size_t n = new_heights.size();
        std::stack<int> s;
        int max_area = 0;

        for (size_t i = 0; i < n; i++) {
            while (!s.empty() && new_heights[i] < new_heights[s.top()]) {
                int height = new_heights[s.top()];
                s.pop();
                int width = i - s.top() - 1;
                max_area = std::max(max_area, height * width);
            }
            s.push(i);
        }

        return max_area;
    }
};
