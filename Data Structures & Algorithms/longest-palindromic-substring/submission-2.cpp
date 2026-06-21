class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i++)
        {
            string x;
            string t = "";
            for(int j=i;j<n;j++)
            {
                x+=s[j];
                t = s[j]+t;
                if(t==x && ans.size()<t.size())
                 ans = t;
            }
        }

    return ans;
    }
};
