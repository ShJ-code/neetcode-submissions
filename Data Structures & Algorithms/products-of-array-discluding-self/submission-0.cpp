class Solution {
public:
    std::vector<int> scan_prefix(std::vector<int>& v) {
        int acc = 1;
        std::vector<int> res{1};
        for (size_t i = 0; i < v.size() - 1; i++) {
            acc *= v[i];
            res.push_back(acc);
        }
        return res;
    }

    std::deque<int> scan_suffix(std::vector<int>& v) {
        int acc = 1;
        std::deque<int> res{1};
        for (size_t i = v.size() - 1; i > 0; i--) {
            acc *= v[i];
            res.push_front(acc);
        }
        return res;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix = scan_prefix(nums);
        std::deque<int> suffix = scan_suffix(nums);
        std::vector<int> res;
        auto suf_it = suffix.begin();
        for (auto pre_it = prefix.begin(); pre_it != prefix.end();) {
            res.push_back((*pre_it) * (*suf_it));
            ++pre_it;
            ++suf_it;
        }
        return res;
    }
};
