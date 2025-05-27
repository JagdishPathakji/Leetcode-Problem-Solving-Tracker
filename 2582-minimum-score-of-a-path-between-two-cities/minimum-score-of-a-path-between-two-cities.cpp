class Solution {
public:

    void DFS(int node, vector<bool> &visited, vector<vector<pair<int,int>>> &adj, int &min) {

        visited[node] = true;

        for(int i=0; i<adj[node].size(); i++) {
            int neigh = adj[node][i].first;
            int wt = adj[node][i].second;            
            min = wt < min ? wt : min;
            
            if(!visited[neigh]) {
                DFS(neigh,visited,adj,min);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adjlist(n);
        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adjlist[u-1].push_back({v-1,w});
            adjlist[v-1].push_back({u-1,w});
        }

        vector<bool> visited(n,false);
        int min = INT_MAX;
        DFS(0,visited,adjlist,min);

        return min;
    }
};