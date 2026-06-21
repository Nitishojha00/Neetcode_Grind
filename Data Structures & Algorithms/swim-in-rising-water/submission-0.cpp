class Solution {
public:
int dir[5] = {0,1,0,-1,0};
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<>>pq;
        int n = grid.size() , m = grid[0].size();
        pq.push({grid[0][0], {0,0}});
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vis[0][0] = 1;
        while(!pq.empty())
        {
            auto dis = pq.top().first;
            auto u = pq.top().second.first;
            auto v = pq.top().second.second;
            pq.pop();

            if(u==n-1 && v==m-1)  return dis;

            for(int i=0;i<4;i++)
            {
                int nu = u+dir[i];
                int nv = v+dir[i+1];
                if(nu>=0 && nu<n && nv>=0 && nv<m && !vis[nu][nv])
                {
                    vis[nu][nv] = 1;
                    pq.push({max(dis, grid[nu][nv]), {nu, nv}});
                }
            }
        }

        return -1;
    }
};
