class Solution {
public:
vector<bool>vis;
    bool dfs(int node , int par , vector<int>*adj)
    {
        bool ans = true;
        vis[node] = true;
        for(auto neib:adj[node])
        {
            if(neib==par) continue;
            if(vis[neib]) return false;

            ans = ans & dfs(neib,node,adj);
        }
        return ans;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
       
        vis.resize(n,false);
        vector<int>adj[n];
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(!dfs(0,-1,adj)) return false;
        for(auto val:vis)  if(!val) return false;
        return true;
    }
};
