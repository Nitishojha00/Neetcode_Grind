class Solution {
public:
vector<int>par , rank;
    int findPar(int u)
    {
        if(par[u]==u)  return u;

        return par[u] = findPar(par[u]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int a,b;
        int n = edges.size();
        par.resize(n+1) , rank.resize(n+1);
        for(int i=1;i<=n;i++)
           par[i] = i;

        for(auto e:edges)
        {
            int u = e[0] , v = e[1];
            int pu = findPar(u);
            int pv = findPar(v);
            if(pu==pv)
            {
                a = u , b = v;
            }
            else
            {
                if(rank[pu]>rank[pv])
                {
                    par[pv] = pu;
                }
                else if(rank[pu]<rank[pv])
                {
                    par[pu] = pv;
                }
                else
                {
                    par[pv] = pu;
                    rank[pu]++;
                }
            }
        }

        return {a,b};
    }
};
