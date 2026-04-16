class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resLen = 0, resIdx = 0;
        for (int i = 0; i < n; i++) {
            // Check odd-length palindrome, centered at i
            int currLen = 1, currIdx = i;
            while (currIdx >= 0 &&
                   currIdx+currLen < n &&
                   s[currIdx-1] == s[currIdx+currLen]) {
                currLen += 2;
                currIdx--;
            }
            if (currLen > resLen) {
                resLen = currLen;
                resIdx = currIdx;
            }

            // Check even-length palindrome, centered at i and i+1
            if (i+1<n && s[i] == s[i+1]) {
                currLen = 2, currIdx = i;
                while (currIdx >= 0 &&
                       currIdx+currLen < n &&
                       s[currIdx-1] == s[currIdx+currLen]) {
                    currLen += 2;
                    currIdx--;
                }
                if (currLen > resLen) {
                    resLen = currLen;
                    resIdx = currIdx;
                }
            }
        }

        return s.substr(resIdx, resLen);
    }
};
