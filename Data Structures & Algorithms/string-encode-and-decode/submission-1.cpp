class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res, sep = "#";
        for (std::string str : strs) {
            res += (to_string(str.size()) + sep + str);
        }
        return res;
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        int i = 0, j;
        while ((j = s.find('#', i)) != std::string::npos) {
            int len = std::stoi(s.substr(i, j-i));
            i = j + 1;
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};
