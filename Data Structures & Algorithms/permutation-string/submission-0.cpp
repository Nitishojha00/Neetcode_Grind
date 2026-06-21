class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26);
        vector<int>freq2(26);
        for(auto ch:s1)
        {
            freq1[ch-'a']++;
        }
        
        int n = s2.size();
        int l = 0 , r = 0;

        while(r<n)
        {
            auto idx = s2[r]-'a';
            freq2[idx]++;
            while(freq2[idx]>freq1[idx] && l<=r)
            {
                freq2[s2[l]-'a']--;
                l++;
            }
            bool ans = true;
            for(int i=0;i<26;i++)
            {
                if(freq1[i]!=freq2[i])
                {
                    ans = false;
                    break;
                }
            }
            if(ans) return true;
            r++;
        }
        return false;
    }
};
