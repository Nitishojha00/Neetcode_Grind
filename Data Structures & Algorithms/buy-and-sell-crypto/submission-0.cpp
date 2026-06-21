class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int purchased = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            ans = max(ans,prices[i]-purchased);
            purchased = min(purchased,prices[i]);
        }

        return ans;
    }
};
