class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unordered_multiset<int>s;
        for(auto v:nums)
        {
            if(v==val) continue;
            s.insert(v);
        }

        int i = 0;
        for(auto v:s)
        {
            nums[i] = v;
            i++;
        }
        return i;
    }
};