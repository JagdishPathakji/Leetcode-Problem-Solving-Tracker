class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjlist(n);
        vector<int> indegree(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjlist[u].push_back(v);
            indegree[v]++;
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0)
            ans.push_back(i);
        }

        return ans;
    }
};