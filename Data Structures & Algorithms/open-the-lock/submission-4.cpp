class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //  base  consition
        unordered_set<string>dead(deadends.begin(),deadends.end());
        
        if(dead.count("0000")) return -1;
        if(target=="0000") return 0;

        queue<pair<int,string>>q1,q2;
        q1.push({0,"0000"});
        q2.push({0,target});
        unordered_map<string,int>mp1,mp2;
        mp2[target] = 0;
        mp1["0000"] = 0;
        while(!q1.empty() && !q2.empty())
        {
            int cnt1 = q1.front().first;
            string str1 = q1.front().second;
            q1.pop();
            int cnt2 = q2.front().first;
            string str2 = q2.front().second;
            q2.pop();

            for(int i=0;i<4;i++)
            {
                string s1,s2,s3,s4;
                s1=s2=str1;
                s3=s4=str2;
                s1[i] =  (char)('0' + (s1[i] - '0' - 1 + 10) % 10);
                s2[i] =  (char)('0' + (s2[i] - '0' + 1) % 10);
                s3[i] =  (char)('0' + (s3[i] - '0' - 1 + 10) % 10);
                s4[i] =  (char)('0' + (s4[i] - '0' + 1) % 10);


                if(mp2.find(s1)!=mp2.end())   return mp2[s1]+cnt1+1;
                if(mp2.find(s2)!=mp2.end())   return mp2[s2]+cnt1+1;
                if(mp1.find(s3)!=mp1.end())   return mp1[s3]+cnt2+1;
                if(mp1.find(s4)!=mp1.end())   return mp1[s4]+cnt2+1;
                
                if(mp1.find(s1)==mp1.end() && dead.find(s1)==dead.end())
                {
                    mp1[s1] = cnt1+1;
                    q1.push({cnt1+1,s1});
                }
                if(mp1.find(s2)==mp1.end() && dead.find(s2)==dead.end())
                {
                    mp1[s2] = cnt1+1;
                    q1.push({cnt1+1,s2});
                }
                if(mp2.find(s3)==mp2.end() && dead.find(s3)==dead.end())
                {
                    mp2[s3] = cnt2+1;
                    q2.push({cnt2+1,s3});
                }
                if(mp2.find(s4)==mp2.end() && dead.find(s4)==dead.end())
                {
                    mp2[s4] = cnt2+1;
                    q2.push({cnt2+1,s4});
                }
            }
        }

        return -1;
    }
};