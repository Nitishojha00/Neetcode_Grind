class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int n = arr.size();
        int i = 0;
        while(i<n-1)
        {
            int k = i;
            while(k<n-1 && ((k%2==0 && arr[k]<arr[k+1]) || (k%2!=0 && arr[k]>arr[k+1])))
               k++;

            if(k==i)
            while(k<n-1 && ((k%2==0 && arr[k]>arr[k+1]) || (k%2!=0 && arr[k]<arr[k+1])))
               k++;

               ans = max(ans,k-i+1);
              if(i==k)  k++;
               i = k;
        }

        return ans;
    }
};