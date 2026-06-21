class Solution {
public:
// Custom hash for vector<int>
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = 0;
        for (int x : v) {
            // Combine hashes (like boost::hash_combine)
            h ^= hash<int>()(x) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        }
        return h;
    }
};
// Custom equality (default works, but we define explicitly for clarity)
struct VectorEqual {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a == b;
    }
};

unordered_set<vector<int>, VectorHash, VectorEqual> ans;
    void solve(int i , vector<int>v , vector<int>&nums , int sum  ,int target)
    {
       if(i==nums.size() || target<sum)
        {
            if(target==sum) ans.insert(v);

            return;
        }

        v.push_back(nums[i]);
        solve(i+1,v,nums,sum+nums[i],target);
        v.pop_back();
        solve(i+1,v,nums,sum,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(0,{},candidates,0,target);
        vector<vector<int>>v(ans.begin(),ans.end());
        return v;
    }
};
