class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<int>adj[n];
         vector<int>indegree(n);
        for(auto x:pre)
        {
            int u = x[1];
            int v = x[0];
            indegree[v]++;
            adj[u].push_back(v);
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(!indegree[i]) q.push(i);
        }

        vector<int>ans;
        ans.reserve(n);
        while(!q.empty())
        {
            int  node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto neib:adj[node])
            {
                indegree[neib]--;
                if(!indegree[neib])
                     q.push(neib);
            }
        }

        vector<int>z;
        return (int)ans.size()==n? ans : z;
    }
};
