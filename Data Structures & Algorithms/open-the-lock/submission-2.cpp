class Solution {
public:
using p = pair<int,string>;
    int openLock(vector<string>& deadends, string target) {
        queue<p>q;
        q.push({0,"0000"});
        unordered_set<string>s;
        unordered_set<string>dead(deadends.begin(),deadends.end());
        s.insert("0000");
        if(dead.find("0000")!=dead.end()) return -1;
        while(!q.empty())
        {
            string str = q.front().second;
            int cnt = q.front().first;
            q.pop();
            if(str==target) return cnt;
            
            for(int i=0;i<4;i++)
            {
                int val = str[i]-'0';
                string str1 , str2;
                str1 = str2 = str;
                str1[i] =  (char)('0'+(val-1+10)%10);
                str2[i] = (char)('0'+(val+1)%10);
                if(dead.find(str1)==dead.end() && s.find(str1)==s.end())
                {
                    s.insert(str1);
                    q.push({cnt+1,str1});
                }

                if(dead.find(str2)==dead.end() && s.find(str2)==s.end())
                {
                    s.insert(str2);
                    q.push({cnt+1,str2});
                }

            }
        }

        return -1;
    }
};