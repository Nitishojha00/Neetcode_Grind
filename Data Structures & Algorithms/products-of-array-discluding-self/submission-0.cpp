class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n = nums.size();
         vector<int>suff(n) , pref(n);
         suff[n-1] = nums[n-1];
         pref[0] = nums[0];
         for(int i=1;i<n;i++)
         {
            pref[i] = pref[i-1]*nums[i];
            suff[n-(i+1)] = suff[n-i]*nums[n-(i+1)];
         }

         nums[0] = suff[1];
         nums[n-1] = pref[n-2];
         for(int i=1;i<n-1;i++)
         {
            nums[i] = pref[i-1]*suff[i+1];
         }
         return nums;
    }
};
