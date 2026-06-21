class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // O(n) space complexity solution
        vector<bool>v(1e6+10);
        const int mx = 1e6;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0 && nums[i]<=mx)
            {
                v[nums[i]] = 1;
            }
        }

        for(int i=1;i<=mx;i++)
        {
           if(!v[i]) return i;
        }
        return mx;
    }
};