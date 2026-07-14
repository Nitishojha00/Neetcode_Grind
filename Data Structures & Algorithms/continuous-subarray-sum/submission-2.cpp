class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = nums[0];
        unordered_map<int,int>mp;
        mp[0] = 0;
        for(int i=1;i<n;i++)
           {
              sum+=nums[i];
              if(mp.find(sum%k)!==mp.end())return true;
              mp[sum%k] = i;
           }
           return false;
    }
};