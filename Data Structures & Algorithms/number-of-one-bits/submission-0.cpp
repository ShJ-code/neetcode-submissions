class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int d = 0; d < 32; d++) {
            if ((n >> d) & 1)
                res++;
        }
        return res;
    }
};
