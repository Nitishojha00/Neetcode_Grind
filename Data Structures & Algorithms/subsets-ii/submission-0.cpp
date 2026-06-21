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
void solve(vector<int>&nums , int i , vector<int>v)
{
    if(i==nums.size())
    {
        ans.insert(v);
        return;
    }

    solve(nums,i+1,v);
    v.push_back(nums[i]);
    solve(nums,i+1,v);
    v.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        solve(nums,0,{});
        vector<vector<int>>v(ans.begin(),ans.end());
        return v;
    }
};
