class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int v = nums[0] , f = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==v)
            {
                f++;
                continue;
            }
            else
            {
                f--;
                if(f==-1)
                {
                    v = nums[i],f = 1;
                }
            }
        }
        return v;
    }
};