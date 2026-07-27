class Solution {
    unordered_set<string> wordSet;
    vector<string> res;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        vector<string> cur;
        backtrack(s, 0, cur);
        return res;
    }

private:
    void backtrack(const string& s, int i, vector<string>& cur) {
        if (i == s.size()) {
            res.push_back(join(cur));
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            string w = s.substr(i, j - i + 1);
            if (wordSet.count(w)) {
                cur.push_back(w);
                backtrack(s, j + 1, cur);
                cur.pop_back();
            }
        }
    }

    string join(const vector<string>& words) {
        ostringstream oss;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) oss << " ";
            oss << words[i];
        }
        return oss.str();
    }
};