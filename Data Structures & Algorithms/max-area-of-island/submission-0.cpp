class Solution {
public:
vector<int>a = {0,1,0,-1,0};
  int solve(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = 0;
        int cnt = 1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nx = x+a[i];
                int ny = y+a[i+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]) 
                {
                    q.push({nx,ny});
                    cnt++;
                    grid[nx][ny] = 0;
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    ans = max(ans,(solve(grid,i,j,n,grid[0].size())));
                }
            }
        }

        return ans;
    }
};
