class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();
        int i = 0;
        if(s[n-1]=='1') return false;
        while(i<n-1)
        {
            int j = i+minJump;
            int k = i+maxJump;
            int idx = -1;
            while(j<=min(k,n-1))
            {
                if(s[j]=='0') 
                {
                    if(j+minJump==n-1 || j+maxJump==n-1) return true;
                    idx = j;
                }
                j++;
            }
            if(idx==-1) return false;
            i = idx;
        }

        return true;
    }
};