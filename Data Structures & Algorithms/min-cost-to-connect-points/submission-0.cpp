class Solution {
public:
vector<int>par,rank;
    int findPar(int u)
    {
        if(par[u]==u) return u;

        return par[u] = findPar(par[u]);
    }
    //  okay that problem of also kruskal
    int minCostConnectPoints(vector<vector<int>>& points) {
       // okay lets create edge list
        int n = points.size();
        par.resize(n) , rank.resize(n);
        for(int i=0;i<n;i++)  par[i] = i;
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<n-1;i++)
        {
                for(int j=i+1;j<n;j++)
                {
                    v.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
                }
        }

       sort(v.begin(),v.end());
       int ans = 0;
       for(auto i=0;i<v.size();i++)
       {
             auto dis = v[i].first;
             auto un = v[i].second.first;
             auto vn = v[i].second.second;
             int pu = findPar(un);
             int pv = findPar(vn);
             if(pu==pv) continue;
             ans+=dis;
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
                par[pu] = pv;
                rank[pv]++;
             }
       }
       return ans;
    }
};
