class Solution {
public:
vector<string>ans;
bool isValid(string &s)
{
    stack<char>st;
    int n = s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty() || st.top()==')')return false;
               else
              st.pop();
        }
    }
    return st.empty();
}


    vector<string> generateParenthesis(int n) {
        string s ;
        for(int i=0;i<n;i++)
          s+='(';
        for(int i=0;i<n;i++)
          s+=')';
          do{
            if(isValid(s))
            ans.push_back(s);
          }while(next_permutation(s.begin(),s.end()));
        return ans;
    }
};
