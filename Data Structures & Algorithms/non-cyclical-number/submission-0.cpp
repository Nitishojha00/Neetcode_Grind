class Solution {
public:
unordered_set<int>s;
    bool isHappy(int n) {
        
        s.insert(n);
        while(n!=1)
        {
            int sum = 0;
            while(n)
            {
                int m = n%10;
                n/=10;
                sum+=pow(m,2);
            }
            n = sum;
            if(sum==1) return true;

            if(s.find(sum)!=s.end()) return false;
            s.insert(n);
        }

        return n==1;
    }
};
