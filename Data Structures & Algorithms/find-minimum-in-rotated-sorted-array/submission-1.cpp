class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0 , r = n-1;
        int ans = 9999999;
        while(r>=l)
        {
            int mid = (l+r)/2;
            ans = min(ans,nums[mid]);
            if(nums[mid]>=nums[l])
            {
                if(nums[r]>nums[mid])
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else 
            {
                r = mid-1;
            }
        }

        return ans;
    }
};
