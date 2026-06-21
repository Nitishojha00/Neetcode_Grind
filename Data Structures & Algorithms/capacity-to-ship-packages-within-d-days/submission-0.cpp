class Solution {
public:
using ll = long long;
    int shipWithinDays(vector<int>& weights, int days) {
        ll n = weights.size();
        ll ans = 0;
        ll l = (ll) *max_element(weights.begin(),weights.end()) , r = 1e9;
        while(r>=l)
        {
            ll mid = (l+r)/2;
            ll v = 0;  
            ll sum = 0;
          for(int i=0;i<n;i++)
            {
                sum+= weights[i];
                if(sum>mid)
                   {
                    v++;
                    sum = weights[i];
                   }

            }
             
            if(sum>0) v++;
            if(v>days)
            {
                l = mid+1;
            }
            else 
            {
                ans = mid;
                r = mid-1;
            }
        }

        return ans;
    }
};