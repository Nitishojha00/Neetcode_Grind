class Solution {
public:
  
  void call(vector<int>&nums, vector<vector<int>>&ans,int s , int e)
    {
        if(s==e)
        {
            for(int i=0;i<ans.size();i++)
            {
            if(ans[i]==nums)
            {
            return;
                }
            }
            ans.push_back(nums);
            return;
        }
    
    for(int i=s;i<e;i++)
      {
      swap(nums[s],nums[i]);
      call(nums,ans,s+1,e);
      swap(nums[s],nums[i]);
      }
  }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>>ans;
    call(nums,ans,0,nums.size());
      return ans;
    }
};