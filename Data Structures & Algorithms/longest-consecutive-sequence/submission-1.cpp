class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int ans = 0 , cnt = 0;
        auto it = s.begin();
        while(it!=s.end())
        {
            int val = *it;
            it++;
            int cnt = 1;
            while(it!=s.end() && *it==val+1)
            {
                cnt++;
                val++;
                it++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
