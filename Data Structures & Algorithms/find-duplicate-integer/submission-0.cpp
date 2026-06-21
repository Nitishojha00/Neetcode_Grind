class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int val = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==i+1) continue;

            if(nums[nums[i]-1]==nums[i]) return nums[i];
            swap(nums[nums[i]-1],nums[i]);
        }

        return -1;
    }
};
