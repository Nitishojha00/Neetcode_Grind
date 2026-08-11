class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l = *max_element(weights.begin(),weights.end());
        int r = INT_MAX;
        int ans = -1;
        while(r>=l)
        {
            int mid = l+(r-l)/2;
            int d = 1  , s = 0;
            for(int i=0;i<weights.size();i++)
            {
                s+=weights[i];
                if(s>mid) 
                {
                    s = weights[i];
                    d++;
                }
            }
            
            if(d<=days)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};