class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            auto it = lower_bound(arr.begin(),arr.end(),nums[i]);
            if(it==arr.end())
            {
                arr.push_back(nums[i]);
            } 
            else
            {
                int idx = it-arr.begin();
                arr[idx] = min(arr[idx],nums[i]);
            }
        }
        return arr.size();
    }
};
