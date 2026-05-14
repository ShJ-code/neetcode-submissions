class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> stk;
        for (auto x: tokens) {
            if (x != "+" && x != "-" && x != "*" && x != "/") {
                stk.push_back(std::stoi(x));
            } else {
                int b = stk.back();
                stk.pop_back();
                int a = stk.back();
                stk.pop_back();
                if (x == "+") {
                    stk.push_back(a+b);
                } else if (x == "-") {
                    stk.push_back(a-b);
                } else if (x == "*") {
                    stk.push_back(a*b);
                } else {
                    stk.push_back(a/b);
                }
            }
        }
        return stk.back();
    }
};