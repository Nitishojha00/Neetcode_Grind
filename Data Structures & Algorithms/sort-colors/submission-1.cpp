class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1;
        while(l<n && !nums[l]) l++;
        while(r>=0 && nums[r]==2) r--;
        while(r>l && nums[r]==0 && nums[l]==2)
        {
            swap(nums[l],nums[r]);
            l++,r--;
        }
        int j = l+1;
        while(j<=r)
        {
            if(nums[j]==1)
              j++;
            else if(nums[j]==0)
            {
               swap(nums[j],nums[l]);
               l++;
            }
            else if(nums[j]==2)
            {
                swap(nums[j],nums[r]);
                r--;
            }
        }
        return ;
    }
};