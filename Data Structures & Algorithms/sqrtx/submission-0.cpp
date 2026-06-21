class Solution {
public:
using ll = long long;
    int mySqrt(int x) {
        ll l = 0;
        ll r = 1e9;
        int ans;
        while(r>=l)
        {
            ll mid = l+(r-l)/2;
            if(mid*mid<=x)
              {
                ans = mid;
                l = mid+1;
              }
              else
              {
                r= mid-1;
              }
        }
        return ans;
    }
};