class Solution {
public:
vector<vector<string>> ans;
bool isPlaindrome(string s)
{
    string t = s;
    reverse(t.begin(),t.end());
    return s==t;
}
void palindromePartition(int i , vector<string>v , string &s)
{
    if(i==s.size())
    {
        ans.push_back(v);
        return;
    }

    string str;
    for(int j=i;j<s.size();j++)
    {
        str+=s[j];
        if(isPlaindrome(str))
        {
            v.push_back(str);
            palindromePartition(j+1,v,s);
            v.pop_back();
        }
    }

}
    vector<vector<string>> partition(string s) {
        palindromePartition(0,{},s);
        return ans;
    }
};
