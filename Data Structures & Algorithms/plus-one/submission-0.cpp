class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();
        int carry = 1;
        int i;
        for(i=n-1;i>=0 && digits[i]==9;i--)
        {
               digits[i] = 0;
        }

        if(i>=0)
          digits[i]+=1;
        else
        {
            digits.resize(n+1);
            digits[n] = 1;
            for(int i=n-1;i>=0;i--)
              swap(digits[i],digits[i+1]);
        }
        


        return digits;
    }
};
