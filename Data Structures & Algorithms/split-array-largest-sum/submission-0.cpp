class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

       int n = nums.size();
       int low  = *max_element(nums.begin(),nums.end());
       int high = accumulate(nums.begin(),nums.end(),0);
       int ans = high;
       while(high>=low)
       {
            int mid = low+(high-low)/2;
            int sum = 0;
            int gp = 0;
            for(auto val:nums)
            {
                sum+=val;
                if(sum>mid)
                {
                    sum = val;
                    gp++;
                }
            }

            if(sum)gp++;
            if(gp>k)
            {
                low = mid+1;
            }
            else
            {
                ans = mid;
                high = mid-1;
            }
       }

       return ans;
    }
};