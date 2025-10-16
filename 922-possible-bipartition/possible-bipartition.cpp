class Solution {
public:

    bool DFS(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<char> &color, int prev=-1) {

        visited[node] = true;
        if(prev != -1) {
            if(color[prev] == 'R')
            color[node] = 'B';
            else
            color[node] = 'R';
        }

        for(int i=0; i<adj[node].size(); i++) {
            if(visited[adj[node][i]] && adj[node][i] != prev && color[node] == color[adj[node][i]])
            return true;
            else if(!visited[adj[node][i]] && DFS(adj[node][i],visited,adj,color,node))
            return true;
            else if(visited[adj[node][i]] && adj[node][i] == prev)
            continue;
        }

        return false;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adjlist(n);

        for(int i=0; i<dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adjlist[u-1].push_back(v-1);
            adjlist[v-1].push_back(u-1);
        }

        vector<bool> visited(n,false);
        vector<char> color(n);

        color[0] = 'R';
        for(int i=0; i<visited.size(); i++) {
            if(!visited[i]) {
                color[i] = 'R';
                if(DFS(i,visited,adjlist,color))
                return false;
            }
        }

        return true;
    }
};