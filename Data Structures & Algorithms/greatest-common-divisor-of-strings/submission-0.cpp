class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        string str = "";
        int m;
        string ans = "";
        for(int i=0;i<n2;i++)
        {
            str+=str2[i];
            int ss = i+1;
            if(n1%ss==0 && n2%ss==0)
            {
                 m = n2/ss;
                 string s1 = "" , s2 = "";
                 while(m--)
                 {
                      s1+=str;
                 }
                 if(s1!=str2)
                 continue;
                 m = n1/ss;
                 while(m--)
                 {
                      s2+=str;
                 }
                 if(s2==str1 && str.size()>ans.size())
                 ans = str;
            }
        }
        return ans;
    }
};