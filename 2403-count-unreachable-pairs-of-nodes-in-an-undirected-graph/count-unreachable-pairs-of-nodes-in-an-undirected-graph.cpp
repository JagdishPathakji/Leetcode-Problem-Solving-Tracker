class Solution {
public:

    void DFS(int node, vector<bool> &visited, vector<vector<int>> &adj, int &size) {

        visited[node] = true;
        size++;

        for(int i=0; i<adj[node].size(); i++) {
            if(!visited[adj[node][i]])
            DFS(adj[node][i],visited,adj,size);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int> ans;
        vector<bool> visited(n,false);
        
        vector<vector<int>> adjlist(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        for(int i=0; i<n; i++) {
            int size = 0;
            if(!visited[i])
            DFS(i,visited,adjlist,size);
            ans.push_back(size);
        }

        long long number = 0;
        for(int i=0; i<ans.size(); i++)
        number += ans[i];

        long long sum = 0;
        for(int i=0; i<ans.size(); i++) {
            sum += (ans[i]*(number-ans[i]));
        }

        return sum/2;
    }
};