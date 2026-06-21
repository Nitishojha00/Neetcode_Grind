class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>last_occ;
        int n  = nums.size();
        int i = 1;
        for(int val : nums)
        {
            if(last_occ[val] && i-last_occ[val]<=k) return true;
            last_occ[val] = i;
            i++;
        }
        return false;
    }
};