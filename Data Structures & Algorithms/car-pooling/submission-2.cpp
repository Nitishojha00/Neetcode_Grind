class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n = trips.size();
        vector<int>a(1001);
        for(auto t:trips)
        {
            int p = t[0] , s = t[1] , e = t[2];
            a[s]+=p;
            a[e]-=p;
        }

        int pas= 0;
        for(int i=0;i<1001;i++)
        {
            pas+=a[i];
            if(pas>capacity) return false;
        }

        return true;
    }
};