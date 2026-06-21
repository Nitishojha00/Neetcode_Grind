class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int val = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]+i>=val)
              val = i;
        }

        return val<=0;
    }
};
