/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> scan(2 * intervals.size());
        for (int i = 0; i < intervals.size(); i++) {
            scan[2*i] = {intervals[i].start, 1};
            scan[2*i+1] = {intervals[i].end, -1};
        }
        sort(scan.begin(), scan.end());
        int acc = 0, maxAcc = 0;
        for (auto [time, ch] : scan) {
            acc += ch;
            maxAcc = max(acc, maxAcc);
        }
        return maxAcc;
    }
};
