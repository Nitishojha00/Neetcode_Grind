class Solution {
public:
vector<int>a = {0,1,0,-1,0};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
            {
                if(board[i][0]=='O')
                  {
                    board[i][0] = 'a';
                    q.push({i,0});
                  }
                  if(board[i][m-1]=='O')
                  {
                    board[i][m-1] = 'a';
                    q.push({i,m-1});
                  }
            }

        for(int i=1;i<m-1;i++)
        {
              if(board[0][i]=='O')
                  {
                    board[0][i] = 'a';
                    q.push({0,i});
                  }
                  if(board[n-1][i]=='O')
                  {
                    board[n-1][i] = 'a';
                    q.push({n-1,i});
                  }
        }

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = x+a[i];
                int ny = y+a[i+1];
                if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]=='O')
                {
                    board[nx][ny] = 'a';
                    q.push({nx,ny});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='a')
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
        return ;
    }
};
