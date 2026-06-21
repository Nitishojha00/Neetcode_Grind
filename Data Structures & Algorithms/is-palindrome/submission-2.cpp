class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(auto ch:s)
        {
            if(isalnum(ch)) ans+=ch;
        }
        int i = 0 , e = ans.size()-1;
        while(i<e)
        {
            if(ans[i]>='A' && ans[i]<='Z')
            {
                ans[i] = (char)(ans[i]+32);
            }
            if(ans[e]>='A' && ans[e]<='Z')
            {
                ans[e] = (char)(ans[e]+32);
            }

            if(ans[i]!=ans[e]) return false;
            i++ , e--;
        }

        return true;
    }
};
