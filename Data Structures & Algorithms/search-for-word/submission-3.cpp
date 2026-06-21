class Solution {
public:
bool ans = false;
int dir[5] = {0,1,0,-1,0};
bool dfs(vector<vector<char>>& board,int x,int y,int idx,string &word)
{
    if(idx==word.size()) return true;

    bool flg = false;
    for(int i=0;i<4;i++)
    {
        int nx = x+dir[i];
        int ny = y+dir[i+1];
        if(nx>=0 && nx<board.size() && ny>=0  && ny<board[0].size() && board[nx][ny]==word[idx])
        {
            char ch = board[nx][ny] ;
            board[nx][ny] = '.';
            flg = flg|dfs(board,nx,ny,idx+1,word);
            board[nx][ny] = ch;
        }
    }
    return flg;
}
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    char ch = board[i][j] ;
                    board[i][j] = '.';
                    if(dfs(board,i,j,1,word))
                        return true;
                    board[i][j] = ch;
                }

            }
        }

        return ans;
    }
};
