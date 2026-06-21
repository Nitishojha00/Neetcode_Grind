class Solution {
public:
vector<vector<int>>ans;
void calculate(vector<int>&nums , int i , vector<int>v)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return ;
        }

        calculate(nums,i+1,v);
        v.push_back(nums[i]);
        calculate(nums,i+1,v);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        calculate(nums,0,v);
        return ans;
    }
};
