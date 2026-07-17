class Solution {
public:

    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int l = 0 , r = 0;
        int ans = 0;
        vector<int>freq(26);
        while(r<n)
        {
              freq[s[r]-'A']++;
              int mx = *max_element(freq.begin(),freq.end());
              while(r-l+1-mx>k)
              {
                   freq[s[l]-'A']--;
                   l++;
                   int mx = *max_element(freq.begin(),freq.end());
              }
              ans = max(ans,r-l+1);
              r++;
        }
        return ans;
    }
};