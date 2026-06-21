class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int> , greater<>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k;i<n;i++)
        {
            int val = pq.top();
            if(nums[i]>val)
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }


        return pq.top();
    }
};
