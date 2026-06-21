class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int>diffArr(10001);
        int n = trips.size();
        for(auto v:trips)
        {
            int c = v[0];
            int x1 = v[1];
            int x2 = v[2];
            diffArr[x1]+=c;
            diffArr[x2]-=c;
        }

        int val = 0;

        for(int i=0;i<1001;i++)
        {
            val+=diffArr[i];
            if(val>capacity) return false;
        }

        return true;
    }
};