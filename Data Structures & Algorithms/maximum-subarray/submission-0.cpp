class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            sum = sum+nums[i];
            sum = max(sum,nums[i]);
            ans = max(ans,sum);
        }
        return ans;
    }
};
