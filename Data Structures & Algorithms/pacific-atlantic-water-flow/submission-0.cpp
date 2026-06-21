class Solution {
public:
int dir[5] = {0,1,0,-1,0};
    void bfs(vector<vector<int>> &heights,queue<pair<int,int>> &q,vector<vector<bool>> &a)
    {
        int n = heights.size();
        int m = heights[0].size();
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            a[x][y] = true;
            for(int i=0;i<4;i++)
            {
                int nx = x+dir[i];
                int ny = y+dir[i+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !a[nx][ny] && heights[nx][ny]>=heights[x][y])
                {
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>a(n,vector<bool>(m,0)) , p(n,vector<bool>(m,0));
        queue<pair<int,int>>q1,q2;
        for(int i=0;i<n;i++)
        {
           q1.push({i,0}); // atlantic
            q2.push({i,m-1});
        }
        for(int j=0;j<m;j++)
        {
           q1.push({0,j}); // atlantic
            q2.push({n-1,j});
        }


        bfs(heights,q1,a);
        bfs(heights,q2,p);

        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    if(a[i][j] && p[i][j])
                    {
                        ans.push_back({i,j});
                    }
            }
        }

        return ans;
    }
};
