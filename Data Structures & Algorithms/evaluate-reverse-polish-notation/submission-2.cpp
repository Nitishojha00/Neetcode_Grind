class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto val:tokens)
        {
            if(val=="+")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val1+val2);
            }
            else if(val=="-")
            {
                 int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2-val1);
            }
            else if(val=="*")
            {
                 int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val1*val2);
            }
            else if(val=="/")
            {
                 int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2/val1);
            }
            else
            {
                st.push(stoi(val));
            }
        }
        return st.top();
    }
};
