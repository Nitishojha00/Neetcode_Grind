class Solution {
public:
    
    string a;
    string encode(vector<string>& strs) {
    int n = strs.size();
        for(int i=0;i<n;i++)
        {
            a+=to_string(strs[i].size());
            a+=' ';
            a+=strs[i];
        }
        return a;
    }

    vector<string> decode(string s) {
      vector<string>ans;
      int i = 0;
      while(i<s.size())
      {
            int num = 0;
            while(s[i]!=' ')
            {
                num = num*10+(s[i]-'0');
                i++;
            }
            i++;
            int j = i;
            string str;
            while(j<num+i)
            {
                str+=s[j];
                j++;
            }
            i = j;
            ans.push_back(str);
      }
      return ans;
    }
};
