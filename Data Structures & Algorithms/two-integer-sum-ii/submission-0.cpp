class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int i = 0 ,  e = a.size()-1;
        while(a[i]+a[e]!=target)
        {
            if(a[i]+a[e]<target) i++;
            if(a[i]+a[e]>target) e--;
        }

        return {i+1,e+1};
    }
};
