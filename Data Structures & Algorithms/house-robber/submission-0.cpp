class Solution {
public:
int find(vector<int>& nums , vector<int>&dp , int n)
{
    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = max(nums[n]+find(nums,dp,n-2),find(nums,dp,n-1));
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return find(nums,dp,n-1);
    }
};
