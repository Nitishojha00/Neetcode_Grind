class Solution {
public:
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = 0;
        for (int x : v) {
            h ^= hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
         unordered_set<vector<int>, VectorHash> s;
        for(int i=0;i<n-2;i++)
        {
            int j = i+1 , e = n-1;
            while(e>j)
            {
                if(nums[i]+nums[j]+nums[e]==0)
                {
                    s.insert({nums[i],nums[j],nums[e]});
                    j++,e--;
                }
                else if(nums[i]+nums[j]+nums[e]>0)
                {
                    e--;
                }
                else
                {
                    j++;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto v:s)
        {
                ans.push_back(v);
        }

        return ans;
    }
};
