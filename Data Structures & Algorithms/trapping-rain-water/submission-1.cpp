class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>l(n) , r(n);
        int val = n-1;
        int ans = 0;
        for(int i=n-2;i>=0;i--)
        {
            r[i] = val;
            if(height[i]>height[val])
                val = i;
        }
        val = 0;
        for(int i=1;i<n;i++)
        {
            l[i] = val;
            if(height[i]>height[val])
                val = i;

            if(i<n-1)
            ans += max(min(height[l[i]],height[r[i]])-height[i],0);
        }

        return ans;
    }
};
