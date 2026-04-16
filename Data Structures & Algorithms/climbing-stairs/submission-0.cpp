class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int p = 2, pp = 1;
        for (int i = 3; i <= n; i++) {
            int tmp = p + pp;
            pp = p;
            p = tmp;
        }
        return p;
    }
};
