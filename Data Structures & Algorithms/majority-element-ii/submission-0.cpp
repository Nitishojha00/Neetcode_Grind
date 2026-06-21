class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto val:nums)
          freq[val]++;

        vector<int>ans;
        for(auto [key,val]:freq)
        {
            if(val>nums.size()/3) ans.push_back(key);
        }

        return ans;
    }
};