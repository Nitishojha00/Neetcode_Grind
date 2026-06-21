class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>f1,f2;
        int n = s.size();
        if(s.size()!=t.size()) return false;
        f1.resize(26) , f2.resize(26);
        for(auto ch:s)
        { 
            f1[ch-'a']++;
        }
        for(auto ch:t)
        {
            f2[ch-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(f1[i]!=f2[i]) return false;
        }
        return true;
    }
};
