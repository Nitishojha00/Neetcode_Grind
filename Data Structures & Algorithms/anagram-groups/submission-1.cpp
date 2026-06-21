class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>>f(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            string s = strs[i];
            for(int j=0;j<s.size();j++)
            {
                f[i][s[j]-'a']++;
            }
        }
        vector<vector<string>> ans;
        vector<bool>v(n);

        for(int i=0;i<n;i++)
        {
            if(!v[i])
            {
                vector<string>x;
                x.push_back(strs[i]);
                v[i] = 1;
                for(int j=i+1;j<n;j++)
                {
                    if(!v[j])
                    {
                        int k;
                        for( k=0;k<26;k++)
                        {
                            if(f[i][k]!=f[j][k]) break;
                        }

                        if(k==26)
                        {
                            v[j] = 1;
                            x.push_back(strs[j]);
                        }
                    }
                }
                ans.push_back(x);
            }
        }

        return ans;
    }
};
