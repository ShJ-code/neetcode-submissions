class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    int totalNQueens(int n) {
        int res = 0;
        backtrack(0, n, res);
        return res;
    }

private:
    void backtrack(int r, int n, int& res) {
        if (r == n) {
            res++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            backtrack(r + 1, n, res);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }
};