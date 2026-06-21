class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int i = 0;
        nums.resize(s.size());
        for(int val:s)
         {
            nums[i] = val;
            i++;
         }
        return s.size();
    }
};