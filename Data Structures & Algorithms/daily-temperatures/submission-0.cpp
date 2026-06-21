class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        // i have to store index
        st.push(temp.size()-1);
        vector<int>ans(temp.size());
        ans[temp.size()-1] = 0;
        for(int i=temp.size()-2;i>=0;i--)
        {
            while(!st.empty() && temp[st.top()]<=temp[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                ans[i] = 0;
                st.push(i);
            }
            else
            {
                ans[i] = st.top()-i;
                st.push(i);
            }
        }

        return ans;
    }
};
