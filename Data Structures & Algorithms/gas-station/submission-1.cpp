class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int  j = 0;
        int val = 0;
        int idx = 0;
        int n = gas.size();
        for(int i=0;i<n;i++)
        {
           val  =  val+gas[i];
           val = val-cost[i];
        }
        if(val<0) return -1;
        int total = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);

            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};
