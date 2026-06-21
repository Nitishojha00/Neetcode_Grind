class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp , m;
        string ans = "";

        if(s.size()<t.size())  return ans;

        for(auto ch:t)
           mp[ch]++;

        int l = 0 , r = 0;
        while(r<s.size())
        {
            char ch = s[r];
            m[ch]++;
            if(r-l+1>=t.size())
            {
                bool flag = 1;
                for(auto [key,val]:mp)
                {
                    if(m.find(key)==m.end() || val>m[key])
                     {
                        flag = 0;
                        break;
                     }
                }

                if(flag)
                {
                    while( m[s[l]]>mp[s[l]] || mp.find(s[l])==mp.end())
                    {
                        m[s[l]]--;
                        l++;
                    }

                  string x;
                  //cout<<l<<endl;
                  x = s.substr(l,r-l+1);
                  if(ans.size()==0 || ans.size()>x.size())
                       ans = x;
                }
            }
                r++;
        }

        return ans;
    }
};
