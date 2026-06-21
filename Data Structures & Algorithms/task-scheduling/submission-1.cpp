class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26);
        int val = 0;
        for(auto a:tasks)
        {
            v[a-'A']++;
            val = max(val,v[a-'A']);
        }
        int cnt = count(v.begin(),v.end(),val);
        return max((int)tasks.size(),cnt+(n+1)*(val-1));
    }
};
