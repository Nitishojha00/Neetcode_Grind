class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<>>pq;
        priority_queue<pair<int,int>>p;
        for(int i=0;i<capital.size();i++)
        {
            pq.push({capital[i],profits[i]});
        }

        while(k--)
        {
            while(!pq.empty() && pq.top().first<=w)
                 {
                    p.push({pq.top().second , pq.top().first});
                    pq.pop();
                 }
                 if(p.size()>0)
                 {
                    w+=p.top().first;
                    p.pop();
                 }
        }
        return w;
    }
};