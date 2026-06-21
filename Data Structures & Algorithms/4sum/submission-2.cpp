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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n = nums.size();
         sort(nums.begin(),nums.end());
         unordered_set<vector<int>, VectorHash> s;
         for(int i=0;i<n-3;i++)
         {
            for(int j = i+1;j<n-2;j++)
            {
                int k =  j+1, l = n-1; 
                while(l>k)
                {
                    if((long long)((long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l])==target)
                    {
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        l--,k++;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l]>target)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }
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