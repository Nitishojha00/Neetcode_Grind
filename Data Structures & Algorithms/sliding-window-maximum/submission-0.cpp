class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int>dq;
        if(k==1)  return nums;

        dq.push_back(0);
        vector<int>ans(nums.size()-k+1);
        for(int i=0;i<nums.size();i++)
        {
               if(nums[i]>=nums[dq.front()])
                {
                    dq.clear();
                    dq.push_back(i);
                }
                else
                {
                    while(!dq.empty() && nums[dq.back()]<=nums[i])
                    {
                        dq.pop_back();
                    }
                     dq.push_back(i);
                }
            
            

            if(i>=k-1)  // window of size k
            {
                while(dq.front()<=i-k) dq.pop_front();

                ans[i-k+1] =  nums[dq.front()];

            }
        }
    return ans;
    }
};
