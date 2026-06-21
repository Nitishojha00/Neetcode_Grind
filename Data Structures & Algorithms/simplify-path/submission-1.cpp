class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string s;
        int n = path.size();
        int i = 0;

        while (i < n) {
            // skip leading slashes
            while (i < n && path[i] == '/') i++;

            // collect one directory/file name
            s.clear();
            while (i < n && path[i] != '/') {
                s += path[i];
                i++;
            }

            // process s if not empty
            if (!s.empty()) {
                if (s == "..") {
                    if (!st.empty()) st.pop();
                } else if (s != ".") {
                    st.push(s);
                }
            }
        }

        // build result
        if (st.empty()) return "/";
        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
