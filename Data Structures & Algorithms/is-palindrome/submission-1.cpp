#include <ranges>

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered_string, reversed_string;
        for (auto ch : s) {
            if (isalnum(ch)) filtered_string += tolower(ch);
        }

        reversed_string.resize(filtered_string.size());
        auto curr = reversed_string.begin();
        for (auto it = filtered_string.end(); it != filtered_string.begin();) {
            --it;
            *curr = *it;
            ++curr;
        }

        return filtered_string == reversed_string;
    }
};
