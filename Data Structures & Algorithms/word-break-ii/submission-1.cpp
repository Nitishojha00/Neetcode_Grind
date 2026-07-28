class Solution {
public:
    unordered_set<string>dict;
    vector<string>ans;

    void solve(string &s , string t , string f, int i=0)
    {
        if(i==s.size())
        {
            t.pop_back();
            if(!f.size()) ans.push_back(t);
            return;
        }


        t+=s[i];
        f+=s[i];
        if(dict.find(f)!=dict.end())
        {
            t+=" ";
            solve(s,t,"",i+1);
            t.pop_back();
        }
         solve(s,t,f,i+1);
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(auto word:wordDict)
            dict.insert(word);

        solve(s,"","");
        return ans;
    }
};