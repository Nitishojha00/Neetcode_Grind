class Solution {
public:
    int sum = 0;
    void bktrk(vector<int>&nums , int n , int val)
    {
          if(n<0)
          {
            sum+=val;
            return;
          }

          bktrk(nums,n-1,val^nums[n]);
          bktrk(nums,n-1,val);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        bktrk(nums,n-1,0);
        return sum;
    }
};