class Solution {
public:

    void DFS(int node, vector<bool> &visited, vector<vector<int>> &adjlist) {

        visited[node] = true;

        for(int i=0; i<adjlist[node].size(); i++) {
            if(!visited[adjlist[node][i]])
            DFS(adjlist[node][i],visited,adjlist);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)
        return -1;

        vector<vector<int>> adjlist(n);
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<bool>visited(n,false);
        int count = 0;

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                DFS(i,visited,adjlist);
                count++;
            }   
        }

        return count-1;
    }
};