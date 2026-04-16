class MedianFinder {
    std::priority_queue<int>* smaller;
    int median;
    std::priority_queue<int, std::vector<int>, std::greater<int>>* larger;
    int total = 0;
public:
    MedianFinder() {
        smaller = new std::priority_queue<int>();
        median = 0;
        larger = new std::priority_queue<int, std::vector<int>, std::greater<int>>();
    }
    
    void addNum(int num) {
        total += 1;
        if (total == 1) {
            median = num;
            return;
        }
        if (num > median) {
            larger->push(num);
            if (total % 2 == 0) {
                smaller->push(median);
                median = larger->top();
                larger->pop();
            }
        } else {
            if (total % 2 == 1) {
                larger->push(median);
                smaller->push(num);
                median = smaller->top();
                smaller->pop();
            }
            else {
                smaller->push(num);
                // median = num;
            }
        }
    }
    
    double findMedian() {
        if (total % 2 == 0) {
            return (smaller->top() + median) / 2.0;
        } else {
            return median;
        }
    }
};
