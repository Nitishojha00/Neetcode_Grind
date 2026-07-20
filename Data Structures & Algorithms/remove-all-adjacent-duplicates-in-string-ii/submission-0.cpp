class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>>st;
        st.push({'-',0});

        for(int i=0;i<n;i++)
        {
            auto [str,cnt] = st.top();
            if(s[i]==str)
            {
                cnt+=1;
                if(cnt==k)
                {
                    cnt--;
                    while(cnt--) st.pop();
                }
                else
                {
                    st.push({str,cnt});
                }
            }
            else
            {
                st.push({s[i],1});
            }
        }

        string ans;
        while(st.size()>1)
           {
                ans+=st.top().first;
                st.pop();
           }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};