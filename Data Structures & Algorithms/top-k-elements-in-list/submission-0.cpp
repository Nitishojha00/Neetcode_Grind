class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        for(auto v:nums)
        {
            f[v]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto  [k,v]:f)
        {
            pq.push({v,k});
        }
        nums.resize(k);
        int i = 0;
        while(k--)
        {
            nums[i] = pq.top().second;
            i++;
            pq.pop();
        }
        return nums;
    }
};
