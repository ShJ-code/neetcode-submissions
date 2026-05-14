class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> dec_temp;
        size_t n = temperatures.size();
        std::vector<int> res(n, 0);
        for (size_t i = 0; i < n; i++) {
            while (!dec_temp.empty() && temperatures[i] > dec_temp.top().second) {
                auto [idx, _] = dec_temp.top();
                res[idx] = i - idx;
                dec_temp.pop();
            }
            dec_temp.push(std::make_pair(i, temperatures[i]));
        }
        return res;
    }
};
