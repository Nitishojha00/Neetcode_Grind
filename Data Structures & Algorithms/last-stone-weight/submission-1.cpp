class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            if(x>y) swap(x,y);

            if(x==y) continue;
            else if(y>x)
            {
                pq.push(y-x);
            }
        }

        return pq.size()==1?pq.top():0;
    }
};
