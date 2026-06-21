class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {  
        int val = 0;
        for(int i=0;i<nums.size();i++)
        {
            val = val^nums[i];
            val = val^i;
        }
        val = val^nums.size();

        return val;
 }
};
