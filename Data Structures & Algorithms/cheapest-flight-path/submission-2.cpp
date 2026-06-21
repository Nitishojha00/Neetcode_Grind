class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // okay lets create adjacency vector
        vector<pair<int,int>>adj[n];
        for(auto it :flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,src}}); //  moves cost node
        int ans = INT_MAX;
        while(!pq.empty())
        {
            int m = pq.front().first;
            int c = pq.front().second.first;
            int n = pq.front().second.second;
            pq.pop();

            if(n==dst)  ans = min(ans,c); 
            if(m==k+1) continue; // no needed to make moves any more

            for(auto [neib,charge]:adj[n])
            {
                 pq.push({m+1,{c+charge,neib}});
            }
        }

        return ans==INT_MAX?-1:ans;
    }
};
