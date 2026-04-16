class Solution {
public:
    unordered_map<int, bool> memo;

    bool dfs(string& s, vector<string>& wordDict, int i) {
        // If the result has been calculated, directly return.
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        // Try each word in the Dict as prefix
        for (const string& w : wordDict) {  // O(m)
            if (i + w.length() <= s.length() &&
                s.substr(i, w.length()) == w) {  // O(t)
                if (dfs(s, wordDict, i + w.length())) {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return dfs(s, wordDict, 0);
    }
};
