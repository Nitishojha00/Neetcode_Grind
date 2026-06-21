class Solution {
public:using ll = long long;
    int minEatingSpeed(vector<int>& piles, int h) {
        ll n = piles.size();
        ll ans = 0;
        ll l = 1 , r = 1e9;
        while(r>=l)
        {
            ll mid = (l+r)/2;
            ll hr = 0;
            for(int i=0;i<n;i++)
            {
                hr+=(piles[i]/mid);
                if(piles[i]%mid!=0)
                   hr++;
            }
                   if(hr>h)
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
