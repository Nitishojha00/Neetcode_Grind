class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        long long m = 1;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=k)
            {
                int m = (i-l);
                ans += (m*(m+1))/2;
                m = 1;
                l = i+1;
                continue;
            }

           m*=nums[i];
           if(m>=k)
           {
                while(l<=i && m>=k)
                {
                    ans+=(i-l);
                    m/=nums[l];
                    l++;
                }
           }
        }
        
        n = (n-l);
        // cout<<n<<endl;
        ans+=(n*(n+1))/2;
        return ans;
    }
};