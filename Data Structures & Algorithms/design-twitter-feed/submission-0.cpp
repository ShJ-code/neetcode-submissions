class Twitter {
    int count;
    std::unordered_map<int, std::vector<std::vector<int>>> tweetMap;
    std::unordered_map<int, std::set<int>> followMap;

public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        std::vector<int> res;
        auto compare = [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> maxHeap(compare);

        followMap[userId].insert(userId);
        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                const std::vector<std::vector<int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                maxHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            std::vector<int> curr = maxHeap.top();
            maxHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if (index > 0) {
                const std::vector<int>& tweet = tweetMap[curr[2]][index - 1];
                maxHeap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
