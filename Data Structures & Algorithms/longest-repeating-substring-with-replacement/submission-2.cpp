class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int>freq(26);
        int n = s.size();
        int l = 0 , r = 0;
        int ans = k;
        while(r<n)
        {
            freq[s[r]-'A']++;
            // simply iterate and check
            int mx = *max_element(freq.begin(),freq.end());
            int distinct_chars = r-l+1 - mx;
            while(l<=r && distinct_chars>k)
            {
                freq[s[l]-'A']--;
                l++;
                mx = *max_element(freq.begin(),freq.end());
                distinct_chars = r-l+1 - mx;
            }

            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
