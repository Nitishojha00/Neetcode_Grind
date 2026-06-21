class Solution {
public:
vector<int>a = {1,0,-1,0,1};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j] = '0';
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int p=0;p<4;p++)
                        {
                            int nx = x+a[p];
                            int ny = y+a[p+1];
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1')
                            {
                                q.push({nx,ny});
                                grid[nx][ny] = '0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
