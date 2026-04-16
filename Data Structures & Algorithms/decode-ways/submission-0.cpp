class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // if (n == 1) {
        //     return 1;
        // }
        // int res = 0;
        // for (int i = 0; i < n; i++) {
        //     if (s[i] == '1' || s[i] == '2') {
        //         return numDecodings(s.substr(i+1, n)) + numDecodings(s.substr(i+2, n));
        //     }
        // }

        vector<int> ans(n+1);
        ans[n] = 1;
        if (s[n-1] == '0')
            ans[n-1] = 0;
        else
            ans[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == '0') {
                ans[i] = 0;
            } else if (s[i] == '1') {
                ans[i] = ans[i+1] + ans[i+2];
            } else if (s[i] == '2') {
                if (s[i+1] - '0' <= 6) {
                    ans[i] = ans[i+1] + ans[i+2];
                } else {
                    ans[i] = ans[i+1];
                }
            } else {
                ans[i] = ans[i+1];
            }
        }
        return ans[0];
    }
};
