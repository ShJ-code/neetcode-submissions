class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        dec_stk = []
        n = len(temperatures)
        res = [0] * n
        for i in range(n):
            while dec_stk and dec_stk[-1][1] < temperatures[i]:
                idx, temp = dec_stk.pop()
                res[idx] = i - idx
            dec_stk.append((i, temperatures[i]))
        # while dec_stk:
        #     idx, _ = dec_stk.pop()
        #     res[idx] = 0
        return res