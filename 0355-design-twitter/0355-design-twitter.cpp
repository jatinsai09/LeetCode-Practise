class Twitter {
public:
    int time;
    unordered_map<int, deque<pair<int, int>>> tw;
    unordered_map<int, unordered_set<int>> fol;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tw[userId].push_front({time++, tweetId});
        while(tw[userId].size() > 10) {
            tw[userId].pop_back();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        if (tw[userId].size()) {
            for (const auto &t: tw[userId]) {
                pq.push(t);
            }
        }

        for (const auto &followeeId: fol[userId]) {
            if (tw[followeeId].size()) {
                for (const auto &t: tw[followeeId]) {
                    pq.push(t);
                }
            }
        }

        int c = 0;
        vector<int> res;
        while (!pq.empty() && c < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            c++;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            fol[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */