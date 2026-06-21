class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n = nums.size()-1;
        int i = 0;
        while(i<(n+1)/2)
        {
         for(int j=i;j<n-i;j++)
          {
             int x = nums[i][j];
             int r = j;
             int c = n-i;
             while(r!=i || c!=j)
               {
            swap(x,nums[r][c]);  
               swap(r,c);
                c = n-c;
                }
             swap(x,nums[i][j]);
           }
            i++;
        }
        return;
    }
};