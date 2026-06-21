class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0;
        int n = s.size();
        int ans = 0;
        vector<int>freq(257);
        while(r<n)
        {
            int idx = (int)s[r];
            while(l<r && freq[idx]) // means that substring contain duplicates
            {
                freq[(int)s[l]]--;
                l++;
            }
            freq[idx]++;
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
