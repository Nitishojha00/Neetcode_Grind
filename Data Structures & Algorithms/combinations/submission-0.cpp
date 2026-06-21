class Solution {
public:
vector<vector<int>> ans;
    void solve(int i , vector<int>v , int n , int k )
    {
        if(i>n || v.size()>=k)
        {
            if(v.size()==k) ans.push_back(v);

            return ;
        }
        
        v.push_back(i);
        solve(i+1,v,n,k);
        v.pop_back();
        solve(i+1,v,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        solve(1,{},n,k);
        return ans;
    }
};