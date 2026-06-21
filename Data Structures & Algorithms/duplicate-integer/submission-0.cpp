class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto val:nums)
        {
            if(mp[val]) return true;
            mp[val]++;
        }
        return false;
    }
};