class Solution {
public:
    vector<int>par,rank;
    int findPar(int u)
    {
        if(par[u]==u) return u;

        return par[u] = findPar(par[u]);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        par.resize(n) , rank.resize(n);
        for(int i=0;i<n;i++)  par[i] = i;

        unordered_map<string,int>mp;
        int i = 0;
        for(auto v:accounts)
        {
            string name = v[0];
             for(int j = 1;j<v.size();j++)
             {
                 if(mp.find(v[j])!=mp.end()) // mtlb union krna hai
                 {
                     int u = i , vv = mp[v[j]];
                     int pu = findPar(u) , pv = findPar(vv);
                     if(rank[pu]>rank[pv])
                     {
                        par[pv] = pu;
                     }
                     else if(rank[pv]>rank[pu])
                     {
                        par[pu] = pv;
                     }
                     else
                     {
                        rank[pv]++;
                        par[pu] = pv;
                     }
                 }
                 else
                 {
                    mp[v[j]] = i;
                 }
             }
             i++;
        }

        //okay i have copied the below part

        // Step 2: Group emails by parent
        unordered_map<int, set<string>> groups;
        for (auto &[email, idx] : mp) {
            int parentIdx = findPar(idx);
            groups[parentIdx].insert(email);
        }

        // Step 3: Build answer
        vector<vector<string>> ans;
        for (auto &[idx, emails] : groups) {
            vector<string> merged;
            merged.push_back(accounts[idx][0]); // name
            merged.insert(merged.end(), emails.begin(), emails.end());
            ans.push_back(merged);
        }

        return ans;
    }
};