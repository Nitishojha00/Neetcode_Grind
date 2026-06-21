class Solution {
    static constexpr int MX = 20009;
    vector<int> adj[MX];   // adjacency list
public:

    int solve(vector<int>& a) {
        return max_element(a.begin(), a.end()) - a.begin();
    }

    void dfs(int node, int par, vector<int>& depth) {
        if (par == -1) depth[node] = 0;
        else depth[node] = depth[par] + 1;

        for (auto neib : adj[node]) {
            if (neib == par) continue;
            dfs(neib, node, depth);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // clear adjacency list
        for (int i = 0; i < n; i++) adj[i].clear();

        // build graph
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // step 1: farthest node from 0
        vector<int> h1(n, 0), h2(n, 0);
        dfs(0, -1, h1);
        int root1 = solve(h1);

        // step 2: farthest from root1
        fill(h1.begin(), h1.end(), 0);
        dfs(root1, -1, h1);
        int root2 = solve(h1);

        // step 3: distances from root2
        dfs(root2, -1, h2);

        // step 4: find centers
        vector<int> ans;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, max(h1[i], h2[i]));
        }
        for (int i = 0; i < n; i++) {
            if (max(h1[i], h2[i]) == mn)
                ans.push_back(i);
        }
        return ans;
    }
};
