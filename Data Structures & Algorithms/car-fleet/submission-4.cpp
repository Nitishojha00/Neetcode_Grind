class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>v;
        int n = position.size();
        v.reserve(n);
        for(int i=0;i<n;i++)
        {
            double time = (double)(target-position[i])/speed[i];
            v.push_back({position[i],time});
        }
        sort(v.rbegin(),v.rend());
        double lastt = 0, fleets = 0;
         for(int i=0;i<n;i++)
         {
            if(lastt<v[i].second)
            {
                lastt = v[i].second;
                fleets++;
            }
         }

         return fleets;
    }
};
