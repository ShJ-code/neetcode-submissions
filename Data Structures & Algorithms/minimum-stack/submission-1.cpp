class MinStack {
private:
    std::vector<int> stk;
    std::vector<int> min_stk;
    size_t len;

public:
    MinStack() {
        len = 0;
    }
    
    void push(int val) {
        stk.push_back(val);
        if (len > 0) {
            min_stk.push_back(std::min(val, min_stk.back()));
        } else {
            min_stk.push_back(val);
        }
        len++;
    }
    
    void pop() {
        stk.pop_back();
        min_stk.pop_back();
        len--;
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return min_stk.back();
    }
};
