class Solution {
public:
    unordered_map<int, int> memoize;
    int dfs(int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (memoize.find(amount) != memoize.end())
            return memoize[amount];

        int res = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                int result = dfs(amount - coin, coins);
                if (result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }

        memoize[amount] = res;
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(amount, coins);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};
