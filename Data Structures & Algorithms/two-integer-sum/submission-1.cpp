class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int x = 1000000, y = 10000000;
        for(int i=0;i<nums.size();i++)
        {
            int val = nums[i];
            int req = target-val;
            if(mp.find(req)!=mp.end() && mp[req]<x)
            {
                 x = mp[req];
                 y = i;
            }
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]] = i;
            }
        }

        return {x,y};
    }
};
