class Solution {
public:

using p = tuple<int,int,int>;
vector<int>a = {0,1,0,-1,0};
void solve(vector<vector<int>>& grid,queue<p>&pq,int n , int m)
    {
            while(!pq.empty())
            {
                auto [d,x,y] = pq.front();
                pq.pop();
                for(int i=0;i<4;i++)
                {
                    int nx = x+a[i];
                    int ny = y+a[i+1];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]>d+1)
                    {
                        grid[nx][ny] = d+1;
                        pq.push({d+1,nx,ny});
                    }
                }
            }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int  m = grid[0].size();
        queue<p>pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!grid[i][j])
                {
                    pq.push({0,i,j});
                }
            }
        }
        solve(grid,pq,n,m);
        return ;
    }
};
