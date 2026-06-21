class Solution {
public:
// void ExtractString(string &s , string &t , int &i)
//     {
//         int j;
//         for(j=i;j<s.size() && s[j]>='a' && s[j]<='z';j++)
//         {
//             t+=s[j];
//         }
//         i = j;
//     }
    void ExtractNum(string &s , string &t , int &i)
    {
        int j;
        for(j=i;j<s.size() && s[j]>='0' && s[j]<='9';j++)
        {
            t+=s[j];
        }
        i = j;
    }
    void repeat(string &t, int num)
    {
        string ans = t;
        while(--num)
        {
            ans+=t;
        }

         t = ans;
         return;
    }
    string decodeStrings(string &s , int &i) {
    
            string ans;
            int n = s.size();
            while(i<n)
            {
                if(s[i]>='0' && s[i]<='9')// number hua  mtlb aga bracked bhi hoga
                {
                    string t;
                    ExtractNum(s,t,i);
                    int num = stoi(t);
                    if(s[i]=='[')
                    {
                        i++;
                        string temp = decodeStrings(s,i);
                        repeat(temp,num);
                        ans+=temp;
                    }
                }
                else if(s[i]>='a' && s[i]<='z')
                {
                   ans+=s[i];
                   i++;
                }
                else if(s[i]==']')
                 {
                    i++;
                    return ans;
                 }
            }
                 return ans;
    }

            string decodeString(string s) {
                int i = 0;
                return decodeStrings(s,i);
            }
    
};