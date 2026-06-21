class Solution {
public:
// i will do it using disjoint union set
vector<int>par , rank;
    int findPar(int u)
    {
        if(par[u]==u)  return u;

        return par[u] = findPar(par[u]);
    }



    int countComponents(int n, vector<vector<int>>& edges) {

        int ans = n;
        par.resize(n);
        rank.resize(n);
        for(auto i=0;i<n;i++)
            par[i] = i;

        for(auto e:edges)
        {
           int u = e[0] , v = e[1];
           int pu = findPar(u);
           int pv = findPar(v);

           if(pu!=pv)
           {
              ans--;
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
                   rank[pu]++;
                   par[pv] = pu;
              }
           }
        }
        

        return ans;
    }
};
