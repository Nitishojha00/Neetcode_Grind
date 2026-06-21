class Solution {
public:
    int calPoints(vector<string>& s ) {
        stack<int>st;
        int  n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=="+")
            {
                int val1 = st.top();
                st.pop();
                int val2 = val1+st.top();
                st.push(val1);
                st.push(val2);
            }
            else if(s[i]=="D")
            {
                st.push(st.top()*2);
            }
            else if(s[i]=="C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(s[i]));
            }
        }

        int res = 0;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }

        return res;
    }
};