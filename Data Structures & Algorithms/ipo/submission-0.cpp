class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto cmpCapital = [&](int a, int b) { return capital[a] > capital[b]; };
        auto cmpProfit = [&](int a, int b) { return profits[a] < profits[b]; };

        priority_queue<int, vector<int>, decltype(cmpCapital)> minCapital(cmpCapital);
        priority_queue<int, vector<int>, decltype(cmpProfit)> maxProfit(cmpProfit);

        for (int i = 0; i < capital.size(); i++) {
            minCapital.push(i);
        }

        for (int i = 0; i < k; i++) {
            while (!minCapital.empty() && capital[minCapital.top()] <= w) {
                maxProfit.push(minCapital.top());
                minCapital.pop();
            }
            if (maxProfit.empty()) {
                break;
            }
            w += profits[maxProfit.top()];
            maxProfit.pop();
        }

        return w;
    }
};