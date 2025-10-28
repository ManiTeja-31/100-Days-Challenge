//Naive or Brute Force Approach
class Twitter {
public:
    vector<pair<int,int>> tweets; // {userId, tweetId}
    unordered_map<int, unordered_set<int>> followees;
    
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId); // follow self
        vector<pair<int,int>> feed;
        
        // collect tweets from followees
        for(auto &t : tweets) {
            if(followees[userId].count(t.first))
                feed.push_back(t);
        }
        
        // take last 10 tweets
        vector<int> res;
        for(int i = feed.size()-1; i >= 0 && res.size()<10; i--) {
            res.push_back(feed[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

//Store Tweets Per User
class Twitter {
    long long timeStamp=0;
    unordered_map<int, unordered_set<int>> friends;
    unordered_map<int,vector<pair<long long,int>>> tweets;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timeStamp,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<long long,int>> mergeTweets(tweets[userId].begin(),tweets[userId].end());
        for(auto f:friends[userId]){
            mergeTweets.insert(mergeTweets.end(),tweets[f].begin(),tweets[f].end());
        }
        sort(mergeTweets.begin(),mergeTweets.end(),
        [](const pair<long long,int> &a,const pair<long long,int> &b){
            return a.first>b.first;
        });
        vector<int> res;
        int count=0;
        for(int i=0;i<mergeTweets.size();i++){
            res.push_back(mergeTweets[i].second);
            count++;
            if(count==10)break;
        }
        mergeTweets.clear();
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

//Store Tweets Per User + Min-Heap
class Twitter {
    long long timeStamp = 0;
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<long long,int>>> tweets; // userId -> [(time,tweetId)]
    
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timeStamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> minHeap;
        
        for(int f : followees[userId]) {
            for(auto &tw : tweets[f]) {
                minHeap.push(tw);
                if(minHeap.size() > 10) minHeap.pop();
            }
        }
        
        vector<int> res;
        while(!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};


//Merge K Sorted Lists Approach
class Twitter {
    long long timeStamp = 0;
    
    struct Tweet {
        long long time;
        int tweetId;
        int userId;
        int index; // index in user's tweet list
        bool operator<(const Tweet& other) const {
            return time < other.time; // max-heap by time
        }
    };
    
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<long long,int>>> tweets; // userId -> [(time, tweetId)]
    
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timeStamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId); // follow self
        priority_queue<Tweet> pq;
        
        // Push the latest tweet of each followee into heap
        for(int f : followees[userId]) {
            int sz = tweets[f].size();
            if(sz > 0) {
                auto &tw = tweets[f][sz-1];
                pq.push({tw.first, tw.second, f, sz-1});
            }
        }
        
        vector<int> res;
        while(!pq.empty() && res.size() < 10) {
            Tweet t = pq.top(); pq.pop();
            res.push_back(t.tweetId);
            
            // Push the next latest tweet from same user
            if(t.index > 0) {
                auto &tw = tweets[t.userId][t.index-1];
                pq.push({tw.first, tw.second, t.userId, t.index-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
