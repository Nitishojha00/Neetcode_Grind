class Solution {
public:

    bool search(vector<int>& nums, int target) {
        
        int l = 0 , r = nums.size()-1;
          while(r>=l)
        {
            int mid = (l+r)/2;
            
            if(nums[mid]==target)   return true;

            if(nums[mid]>nums[l])
            {
               if(target>=nums[l] && target<nums[mid]) 
                    r = mid-1;
               else
                    l = mid+1;
            }
            else if(nums[l]>nums[mid])
            {
                if(target>nums[mid] && target<=nums[r])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            else
            {
               l++;
            }
        }

        return false;
    }
};