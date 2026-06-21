class Solution {
public:
vector<bool>path;
vector<bool>vis;
bool ans = 0;
    bool detectCycle(int node  ,  vector<int>* adj  , int par = -1)
    {
        if(ans)  return true;
        vis[node] = 1;
        path[node] = 1;
        for(auto neib:adj[node])
        {
            if(par==neib) continue;

            if(path[neib])
            {
                ans = true;
                return true;
            }

            if(!vis[neib] && detectCycle(neib,adj,node))
            {
                return true;
            }
        }
        path[node] = 0;
        return false;
    }  

  bool validTree(int n, vector<vector<int>>& edges) {

            int s = edges.size();
            if(s!=n-1) return false;

            // if cycle present return false
            // create adjacency vector first
            vector<int>adj[n];
            path.resize(n);
            for(auto e:edges)
            {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }

            vis.resize(n);
            for(int i=0;i<n;i++)
            {
                
                if(!vis[i] && detectCycle(i,adj,-1))
                {
                    return false;
                }
            }
            return true;
    }
};
