class Solution {
public:
vector<vector<int>> ans;
    void solve(int i , vector<int>v , vector<int>&nums , int sum  ,int target)
    {
       if(i==nums.size() || target<sum)
        {
            if(target==sum) ans.push_back(v);

            return;
        }

        v.push_back(nums[i]);
        solve(i,v,nums,sum+nums[i],target);
        v.pop_back();
        solve(i+1,v,nums,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(0,{},nums,0,target);
        return ans;
    }
};
