class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = n;

        int left, right;
        // Check every index of the string
        for (int i = 0; i < n; i++) {
            // Check odd-length palindrome centered at i
            left = i-1, right = i+1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                res++;
                left--;
                right++;
            }

            // Check even-length palindrome centered at i and i+1
            left = i, right = i+1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                res++;
                left--;
                right++;
            }
        }

        return res;
    }
};
