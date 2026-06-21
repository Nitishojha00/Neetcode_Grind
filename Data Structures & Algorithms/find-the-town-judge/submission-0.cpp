class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // i will create the adjacency list
        vector<int>indegree(n+1) , outdegree(n+1);
        for(int i=0;i<trust.size();i++)
        {
            int x = trust[i][0];
            int y = trust[i][1];
            indegree[y]++;
            outdegree[x]++;
        }

        for(int i=1;i<=n;i++)
        {
            if(!outdegree[i] && indegree[i]==n-1)
            return i;
        }

        return -1;
    }
};