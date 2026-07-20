class Solution {
public:
    bool ans = false;
    void isPossible(vector<int>&a, vector<int>&vis)
    {
      vector<int>s(4);
      int n = a.size();
      for(int i=0;i<n;i++)
       s[vis[i]]+=a[i];
      
        if(s[0]==s[1] && s[0]==s[2] && s[0]==s[3])
                ans = true;

                return;
    }

    void solve(vector<int>&a, vector<int>vis,  int index, int limit)
    {
        if(ans) return;
        if(index==a.size())
        {
            isPossible(a,vis);
            return;
        }

        for(int i=0;i<4;i++)
        {
            if(vis[i]+a[index]>limit) continue;
            vis[index] = i;
            solve(a,vis,index+1,limit);
        }
    }
    bool makesquare(vector<int>& matchsticks) {
        // every has 4 side assign 4 values to each and check finall it happen or not
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        sum/=4;
        vector<int>v(n);
        solve(matchsticks,v,0,sum);
        return ans;
    }
};