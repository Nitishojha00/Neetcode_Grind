class Solution {
public:
    int romanToInt(string s) {
       
      int ans = 0;
      int prev = 1;
   for(int i=s.size()-1;i>-1;i--)
     {
     if(s[i] == 'I')
       {
       if(prev>1)
         ans-=1;
       else
         ans+=1;
       prev=max(prev,1);
 
       }
     else if(s[i] == 'V')
     { 
       if(prev>5)
         ans-=5;
       else
         ans+=5;
       prev=max(prev,5);
       }
     else if(s[i] == 'X')
    {
       if(prev>10)
         ans-=10;
       else
         ans+=10;
       prev=max(prev,10);
     }
     else if(s[i] == 'L')
    {
       if(prev>50)
         ans-=50;
       else
         ans+=50;
       prev=max(prev,50);
    }
     else if(s[i] == 'C')
     {
       if(prev>100)
         ans-=100;
       else
         ans+=100;
       prev=max(prev,100);
       }
     else if(s[i] == 'D')
     {
       if(prev>500)
         ans-=500;
       else
         ans+=500;
       prev=max(prev,500);
     }
      else if(s[i] == 'M')
       {
       if(prev>1000)
         ans-=1000;
       else
         ans+=1000;
       prev=max(prev,1000);
     }
  }
      return ans;
    }
};