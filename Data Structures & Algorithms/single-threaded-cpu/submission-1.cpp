class Solution {
public:
    using p = pair<int,int>;
    vector<int> getOrder(vector<vector<int>>& tasks) {

        priority_queue<p,vector<p>, greater<>>pq;
        int n = tasks.size();
        for(int i=0;i<n;i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        vector<int>ans(n);
        int i = 0;
        int t = tasks[0][0];
        int j = 0;
        while(i<n)
        {
            while(i<n && tasks[i][0]<=t)
            {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }

            if(!pq.empty())
            {
                t += pq.top().first;
                ans[j++] = pq.top().second;
                pq.pop();
            }
            else
            {
                t = tasks[i][0];
            }
       }

        while(!pq.empty())
        {
            ans[j++] = pq.top().second;
             pq.pop();
        }

        return ans;
    }
};