class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // okay yaha bellman ford hi lagaunga
        vector<int>dist(n+1,1e6);
        dist[k] = 0;
        for(int i=0;i<n-1;i++)
        {
            for(auto it:times)
            {
                int u = it[0] , v = it[1] , d = it[2];

                if(dist[u]==1e6)  continue;
                if(dist[v]>dist[u]+d)
                {
                    dist[v] = dist[u] + d;
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<=n;i++)
            if(dist[i]==1e6)  return -1;
            else  ans = max(ans,dist[i]);

            return ans;

    }
};
