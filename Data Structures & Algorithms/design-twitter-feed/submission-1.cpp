class Twitter {
public:
int t;
unordered_map<int,vector<pair<int,int>>>mp;
unordered_map<int,unordered_set<int>>m;
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(!m[userId].size())  m[userId].insert(userId);
        mp[userId].push_back({++t,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pp;
        vector<int>ans;
        for(auto user:m[userId])
        {
            for(auto x:mp[user])
            {
                pp.push(x);
            }
        }
        int n = 10;
        while(!pp.empty() && n--)
        {
            ans.push_back(pp.top().second);
            pp.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        
         m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId && m[followerId].find(followeeId) != m[followerId].end())
             m[followerId].erase(followeeId);
    }
};
