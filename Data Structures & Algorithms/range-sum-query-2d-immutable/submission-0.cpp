class NumMatrix {
public:
vector<vector<int>>a;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        a.resize(n+1,vector<int>(m+1));

        // yaha kuch kro
        for(int i=1;i<=n;i++)
        {
            int val = 0;
            for(int j=1;j<=m;j++)
            {
                val+=matrix[i-1][j-1];
                a[i][j] = (a[i-1][j]+val);
            }
        }
    }





    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return a[row2+1][col2+1]-(a[row2+1][col1]+a[row1][col2+1])+a[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */