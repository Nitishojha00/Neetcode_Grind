class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         // code here
        int n = intervals.size();
        intervals.push_back(newInterval);
        vector<vector<int>>ans;
        ans.reserve(n+1);
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<=n;i++)
        {
            if(ans[ans.size()-1][1]>=intervals[i][0])
            {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
