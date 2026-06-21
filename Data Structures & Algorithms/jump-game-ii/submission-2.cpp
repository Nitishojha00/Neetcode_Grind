class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int ans = 0;
        while(i<n-1)
        {
            if(i+nums[i]>=n-1) return ans+1;
            int j = i+1;
            int idx = i+1;
            while(j<=min(n-1,i+nums[i]))
            {
                if((idx+nums[idx])<=(j+nums[j]))
                {
                    idx = j;
                }
                j++;
            }
            i = idx;
            ans++;
        }

        return ans;
    }
};
