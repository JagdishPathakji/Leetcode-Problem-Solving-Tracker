class Solution {
public:

    void DFS(int node, int parent, vector<vector<int>> &adj, vector<int> &discovery, vector<int> &low, vector<bool> &visited, vector<vector<int>> &bridges, int &count) {
        discovery[node] = low[node] = count;
        visited[node] = true;

        for(int i=0; i<adj[node].size(); i++) {
            int neigh = adj[node][i];
            if(neigh == parent) {
                continue;
            }
            else if(visited[neigh]) {
                low[node] = min(low[node],low[neigh]);
            }
            else {
                count++;
                DFS(neigh,node,adj,discovery,low,visited,bridges,count);
                // bridge exists or not
                if(discovery[node] < low[neigh]) {
                    bridges.push_back({node,neigh});
                }

                low[node] = min(low[node],low[neigh]);
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adjlist(n);
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<vector<int>> bridges;
        vector<int> discovery(n);
        vector<int> low(n);

        vector<bool> visited(n,false);
        int count = 0;

        DFS(0,-1,adjlist,discovery,low,visited,bridges,count);

        return bridges;
    }
};