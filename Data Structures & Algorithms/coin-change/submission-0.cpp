class Solution {
public:
//vector<int>dp(10001);
const int inf = 100001;
int find(vector<int>& coins , int amt , int n , int val )
{
       if(amt==0) return 0;
       if(n<0 || amt<0)  return inf;
       

       return min(1+find(coins,amt-coins[n],n,val),
                find(coins,amt,n-1,val));
}
    int coinChange(vector<int>& coins, int amount) {
        // isko jaldi se krunga
        int ans = find(coins,amount,coins.size()-1,0);
        return ans==100001?-1:ans;
    }
};
