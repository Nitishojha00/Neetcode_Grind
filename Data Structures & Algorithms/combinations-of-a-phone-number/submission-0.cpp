class Solution {
public:
    unordered_map<char,string>st;
    vector<string>ans;
    void solve(vector<string> & v, int i, string s)
    {
        if(i==v.size())
        {
            ans.push_back(s);
            return;
        }


         for(int j=0;j<v[i].size();j++)
            {
                s += v[i][j];
                solve(v,i+1,s);
                s.pop_back();
            }
        
    }
    vector<string> letterCombinations(string digits) {
        st['2'] = "abc"; st['3'] = "def";
        st['4'] = "ghi"; st['5'] = "jkl";
        st['6'] = "mno"; st['7'] = "pqrs";
        st['8'] = "tuv" ; st['9'] = "wxyz";

        if(digits.size()==0) return {};
        
        // ab hoga asli maja;
        vector<string>v;
        for(int i=0;i<digits.size();i++)
        {
            v.push_back(st[digits[i]]);
        }
        solve(v,0,"");
        return ans;
    }
};
