class Solution {
public:
    string OddCheck(string &s , int l , int r)
    {
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r])
           l-- , r++;
        
        string str;
        for(int i=l+1;i<r;i++)  str+=s[i];
        return str;
    }
    string EvenCheck(string &s , int l,int r)
    {
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r])
           l-- , r++;

        string str;
        for(int i=l+1;i<r;i++)  str+=s[i];
        return str;
    }

    string longestPalindrome(string s) {
        
        int n = s.size();
        if(n==1) return s;
        string ans;
        for(int i=0;i<n;i++)
        {
            
            string str = OddCheck(s,i-1,i+1);
            string x = EvenCheck(s,i,i+1);
            if(str.size()>x.size() && str.size()>ans.size())
            {
                ans = str;
            }
            else if(x.size()>str.size() && x.size()>ans.size())
            {
                ans = x;
            }
        }

    return ans;
    }
};
