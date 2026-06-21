class Solution {
public:
vector<vector<int>>dp;
int solve(vector<int>& coins, int amt , int n)
{
    if(amt==0) return 0;
    if(n<0 || amt<0)  return 100001;

    if(dp[n][amt]!=-1) return dp[n][amt];

    return dp[n][amt]  =  min(1+solve(coins,amt-coins[n],n),
                                solve(coins,amt,n-1));
}
    int coinChange(vector<int>& coins, int amt) {
        
        int n = coins.size();
        dp.resize(n,vector<int>(amt+1,-1));
        int ans = solve(coins,amt,n-1);
        return ans==100001?-1:ans;
    }
};
