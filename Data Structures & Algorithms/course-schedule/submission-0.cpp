class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // aisa krta hu ki pehele firected graph banaleta hu 
        // fir topo sort nikalunga 
        // shi aya to answer shi hoga nhito nhi hoga  
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

        int cnt = 0;
        while(!q.empty())
        {
            int  node = q.front();
            q.pop();
            cnt++;
            for(auto neib:adj[node])
            {
                indegree[neib]--;
                if(!indegree[neib])
                     q.push(neib);
            }
        }

        return cnt==n;
    }
};
