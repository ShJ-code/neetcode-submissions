class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> ans(m+1, vector<int>(n+1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int a = ans[i][j], b = ans[i][j+1], c = ans[i+1][j];
                if (text1[i] == text2[j]) {
                    ans[i+1][j+1] = a + 1;
                } else {
                    if (a == b && a == c) {
                        ans[i+1][j+1] = a;
                    } else if (a+1 == b && a+1 == c) {
                        ans[i+1][j+1] = a + 1;
                    } else {
                        ans[i+1][j+1] = max(b, c);
                    }
                }
            }
        }
        return ans[m][n];
    }
};
