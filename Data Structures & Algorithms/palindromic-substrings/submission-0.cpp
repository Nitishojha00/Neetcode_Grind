class Solution {
public:
    int Pal(string &s , int j , int i)
    {
        int n = s.size();
        int idx = j;
        while(i>=0 && j<n & s[i]==s[j])
        {
            i--;
            j++;
        }
        return j-idx;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            ans+=Pal(s,i,i-1);
            ans+=Pal(s,i,i);
        }
        return ans;
    }
};
