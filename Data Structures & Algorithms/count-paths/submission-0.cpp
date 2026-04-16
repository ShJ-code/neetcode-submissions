class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n));
        paths[0][0] = 1;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r > 0)
                    paths[r][c] += paths[r-1][c];
                if (c > 0)
                    paths[r][c] += paths[r][c-1];
            }
        }
        return paths[m-1][n-1];
    }
};
