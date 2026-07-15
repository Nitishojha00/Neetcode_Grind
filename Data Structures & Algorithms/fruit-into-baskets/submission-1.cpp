class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int>freq(100001);
        for(auto f:fruits) freq[f]++;

        int f = 0 ,s = 0;
        for(auto val:freq)
        {
            if(val>f)
            {
                s = f;
                f = val;
            }
            else if(val>s)
                s = val;
        }

        return f+s;
    }
};