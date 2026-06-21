class Solution {
public:
    bool isPalindrome(string &s)
    {
        int i = 0;
        int n = s.size()-1;
        while(n>i)
        {
            if(s[i]!=s[n])  return false;
                i++,n--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size()/2;
        int ind = -1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s[s.size()-(i+1)]) 
            { 
                ind = i;
                break;
            }
        }

        if(ind==-1) return true;

        string a,b;
        for(int i=0;i<s.size();i++)
        {
            if(i!=ind) a+=s[i];
            
            if(i!=s.size()-(ind+1)) b+=s[i];
        }

        if(isPalindrome(a) || isPalindrome(b)) return true;

        return false;
    }
};