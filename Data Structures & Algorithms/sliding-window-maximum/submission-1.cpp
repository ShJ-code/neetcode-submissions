class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int, int>> heap;
        std::vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            heap.push(std::make_pair(nums[i], i));
            if (i >= k - 1) {
                while (heap.top().second <= i - k) {
                    heap.pop();
                }
                output.push_back(heap.top().first);
            }
        }
        return output;
    }
};
