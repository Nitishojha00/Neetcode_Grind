class KthLargest {
public:
    int  k; 
    priority_queue<int,vector<int>,greater<>>pq;
    KthLargest(int K, vector<int>& nums) {
        k = K;
        for(auto val:nums)
        {
           if(pq.size()<k)
            {
              pq.push(val);
            }
            else if(pq.size()>=k && pq.top()<val)
            {
                pq.pop();
                pq.push(val);
            }
           else
            {
                continue;
            }
        }
    }
    
    int add(int val) {
        
        if(pq.size()<k)
            {
              pq.push(val);
            }
            else if(pq.size()>=k && pq.top()<val)
            {
                pq.pop();
                pq.push(val);
            }
          

        return pq.top();
    }
};
