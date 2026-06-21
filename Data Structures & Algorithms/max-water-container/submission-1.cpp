class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int ans = 0;
        int i = 0;
        int e = n-1;
        while(e>i)
        {
            ans = max(ans,min(h[i],h[e])*(e-i));
            if(h[i]<=h[e])
               i++;
            else
               e--;
        }
        return ans;
    }
};
