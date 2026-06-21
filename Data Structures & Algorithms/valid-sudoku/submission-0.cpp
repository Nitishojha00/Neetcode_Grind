class Solution {
public:
bool check(vector<vector<char>>&board,int a,int b,int n,int m)
{
    unordered_set<char>s;
    for(int i=a;i<a+3;i++)
    {
        for(int j=b;j<b+3;j++)
        {
            if(board[i][j]=='.')  continue;
            if(s.find(board[i][j])!=s.end())
                {
                    return false;
                }
                else
                {
                    s.insert(board[i][j]);
                }
        }

    }
        return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<unordered_set<char>>v(n*m);
        vector<unordered_set<char>>row(n) , col(m);
        // for column indivisually
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='.')  continue;
                if(row[i].find(board[i][j])!=row[i].end())
                {
                    return false;
                }
                else
                {
                    row[i].insert(board[i][j]);
                }
            }
        }

        // for row indivisually
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[j][i]=='.')  continue;
                if(col[i].find(board[j][i])!=col[i].end())
                {
                    return false;
                }
                else
                {
                    col[i].insert(board[j][i]);
                }
            }

        }

        for(int i=0;i<n;i+=3)
        for(int j=0;j<m;j+=3)
        {
            if(!check(board,i,j,n,m))
                return false;
        }

        return true;
    
    }
};
