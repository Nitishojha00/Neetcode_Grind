class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26);
        for(auto ch:s)
        {
            freq[ch-'a']++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++)
            {
            if(freq[i])
                pq.push({freq[i],(char)('a'+i)});
            }
            string ans;
            while(!pq.empty())
            {
                auto [f,ch] = pq.top();
                pq.pop();
                if(pq.size()==0 && f>1) return "";
                ans+=ch;
                f--;
                if(pq.size()>0)
                {
                    auto [f1,ch1] = pq.top();
                    pq.pop();
                    ans+=ch1;
                    f1--;
                    if(f1) pq.push({f1,ch1});
                }
                cout<<ans<<endl;
                if(f) pq.push({f,ch});
            }

            return ans;
    }
};