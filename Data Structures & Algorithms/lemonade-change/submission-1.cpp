class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0;
        int n = bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                f++;
            }
            else if(bills[i]==10)
            {
                if(f==0) return false;
                f--;
                t++;
            }
            else
            {
               if(t>0 && f>0)
               {
                    t--;
                    f--;
               }
               else if(f>3)
               {
                    f-=3;
               }
               else if((f==0) || (f<3 && t==0)) 
               {
                return false;
               }
            }
        }

        return true;
    }
};