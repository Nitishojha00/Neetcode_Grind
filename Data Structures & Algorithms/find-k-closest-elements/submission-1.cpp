class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>valid ;
        //its only valid when its closes to x -> abs(x-a[i]) <= k
        for(int i=0;i<arr.size();i++)
        {
              valid.push_back({abs(x-arr[i]),arr[i]});
        }
        vector<int>ans;
        sort(valid.begin(),valid.end());
        int n = min(k,(int)valid.size());
        for(int i=0;i<n;i++)
         {
            ans.push_back(valid[i].second);
         }
        sort(ans.begin(),ans.end());
         return ans;
    }
};