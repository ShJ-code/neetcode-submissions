class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int layers = (min(m, n)-1)/2+1;
        int r = 0, c = 0, res_idx = 0;
        for (int i = 0; i < layers; i++) {
            int h = m - i * 2, w = n - i * 2;
            if (h == 1) {
                for (int j = 0; j < w; j++)
                    res[res_idx++] = matrix[r][c++];
            } else if (w == 1) {
                for (int j = 0; j < h; j++)
                    res[res_idx++] = matrix[r++][c];
            } else {
                for (int j = 0; j < w-1; j++)
                    res[res_idx++] = matrix[r][c++];
                for (int j = 0; j < h-1; j++)
                    res[res_idx++] = matrix[r++][c];
                for (int j = 0; j < w-1; j++)
                    res[res_idx++] = matrix[r][c--];
                for (int j = 0; j < h-2; j++)
                    res[res_idx++] = matrix[r--][c];
                res[res_idx++] = matrix[r][c++];
            }
        }
        return res;
    }
};
