class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // lets apply dijakstra 

        // creating adjacency vector
        vector<pair<int,int>>adj[n+1];
        for(auto it:times)
        {
             adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>dist(n+1,1e6);
        dist[k] = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>>pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto node = pq.top().second;
            pq.pop();
            for(auto [neib,d]:adj[node])
            {
                    if(dist[neib]>dist[node]+d)
                    {
                        dist[neib] = dist[node]+d;
                        pq.push({dist[neib],neib});
                    }
            }
        }

        int ans = *max_element(dist.begin()+1,dist.end());
        return ans==1e6?-1:ans;
    }
};
