class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        for(int i=0;i<a.size();i++)
        {
            if(st.empty())
            {
                st.push(a[i]);
            }
            else
            {
                if(st.top()>=0 && a[i]<=0)
                {
                    while(!st.empty() && st.top()>=0 && a[i]<=0 && st.top()<abs(a[i]))
                    {
                        st.pop();
                    }  
                     
                }
                if(!st.empty() && st.top()==abs(a[i]) && a[i]<=0) 
                {
                    st.pop();
                    continue;
                }
                else if(!st.empty() && st.top()>=0 && a[i]<st.top() && a[i]<=0)
                {
                    continue;
                }
                else 
                {
                    st.push(a[i]);
                }
            }
        }

        vector<int>ans(st.size());
        int n = st.size()-1;
        while(n>=0)
        {
            ans[n--] = st.top();
            st.pop();
        }
        return ans;
    }
};