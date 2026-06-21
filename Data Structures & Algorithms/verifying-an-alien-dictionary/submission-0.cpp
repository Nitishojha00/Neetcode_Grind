class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>f(26);
        for(int i=0;i<26;i++)
        {
            f[order[i]-'a'] = i;
        }

        for(int i=1;i<words.size();i++)
        {
            string s1 = words[i-1];
            string s2 = words[i];
            int n1 = s1.size() , n2 = s2.size();
            int n = min(n1,n2);
            int j;
            bool alleq = 1;
            for(j=0;j<n;j++)
            {
                if(f[s1[j]-'a']<f[s2[j]-'a']) break;
                
                if(f[s1[j]-'a']>f[s2[j]-'a']) return false;

                if(s1[j]!=s2[j]) alleq = false;
            }
        
           if(j==n && alleq && n1>n2) return false;
        }

        return true;
    }
};