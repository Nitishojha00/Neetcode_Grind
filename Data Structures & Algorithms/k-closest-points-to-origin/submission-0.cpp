class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>>pq;
        int i =0;
        for(auto val:points)
        {
            int x = val[0], y = val[1];
             pq.push({(double)sqrt((double)pow(x,2)+(double)pow(y,2)),i++});
        }
        while(pq.size()>k)  pq.pop();
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            auto [x,y] = pq.top(); pq.pop();
            ans.push_back(points[y]);
        }

        return ans;
    }
};
