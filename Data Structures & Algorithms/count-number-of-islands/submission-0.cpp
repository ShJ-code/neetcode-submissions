class Solution {
public:
    // int cnt;

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<bool>> remain(m, vector<bool>(n, false));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
                
        //     }
        // }
        vector<vector<char>> copy(grid);
        // cnt = 0;
        int res = 0;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (copy[i][j] == '1') {
        //             cnt++;
        //         }
        //     }
        // }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (copy[i][j] == '1') {
                    res++;
                    dfs_remove(copy, i, j, m, n);
                }
            }
        }
        return res;
    }

    void dfs_remove(auto& copy, int x, int y, int m, int n) {
        if (x >= 0 && y >= 0 && x < m && y < n && copy[x][y] == '1') {
            copy[x][y] = '0';
            // cnt--;
            dfs_remove(copy, x+1, y, m, n);
            dfs_remove(copy, x-1, y, m, n);
            dfs_remove(copy, x, y+1, m, n);
            dfs_remove(copy, x, y-1, m, n);
        }
    }
};
