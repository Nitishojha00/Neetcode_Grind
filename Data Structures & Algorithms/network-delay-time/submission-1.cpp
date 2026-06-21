class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // okay yaha bellman ford hi lagaunga
        vector<int>dist(n+1,1e6);
        dist[k] = 0;
        for(int i=0;i<n-1;i++)
        {
            bool flg = false;
            for(auto it:times)
            {
                int u = it[0] , v = it[1] , d = it[2];

                if(dist[u]==1e6)  continue;
                if(dist[v]>dist[u]+d)
                {
                    dist[v] = dist[u] + d;
                    flg = true;
                }
            }

            if(!flg) break; // for optimization
        }

        int ans = *max_element(dist.begin()+1,dist.end());
        return ans==1e6?-1:ans;

    }
};
