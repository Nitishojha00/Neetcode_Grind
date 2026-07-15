class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0 , r = 0 , ans = 0;
        int n = fruits.size();
        unordered_map<int,int>mp;
        while(r<n)
        {
            mp[fruits[r]]++;
            r++;
            if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[fruits[l]]--;
                    if(!mp[fruits[l]]) mp.erase(fruits[l]);
                    l++;
                }
            }
            ans = max(ans,r-l);
        }
        return ans;
    }
};