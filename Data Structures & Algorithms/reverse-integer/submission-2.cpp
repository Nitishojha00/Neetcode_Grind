class Solution {
public:
    int reverse(int x) {

        if(x==INT_MIN) return 0;
        bool neg;
        neg = x<0?1:0;
        x = abs(x);
        int val = 0;
        int cnt = 0;
        int f = x%10;
        while(x)
        {
            cnt++;
            if(((val>INT_MAX/10) && f>=2 )|| (f>2 && cnt==10)) return 0;
            val = val*10+(x%10);
            x/=10;


        }
        
        return neg?-1*val:val;
    }
};