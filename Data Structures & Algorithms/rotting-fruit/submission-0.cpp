class Solution {
public:
    int n , m;
    int time = 0;
    using p = tuple<int,int,int>;
vector<int>a = {0,1,0,-1,0};
int solve(vector<vector<int>>& grid,queue<p>&pq)
    {
            int ans = 0;
            while(!pq.empty())
            {
                auto [d,x,y] = pq.front();
                pq.pop();
                time = max(time,d);
                for(int i=0;i<4;i++)
                {
                    int nx = x+a[i];
                    int ny = y+a[i+1];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1)
                    {
                        grid[nx][ny] = 2;
                        pq.push({d+1,nx,ny});
                        ans++;
                    }
                }
            }
            return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
       n = grid.size() , m = grid[0].size();
       queue<p>pq;
       int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    pq.push({0,i,j});
                }
                else if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        int ans = solve(grid,pq);

        return ans==cnt?time:-1;
    }
};
