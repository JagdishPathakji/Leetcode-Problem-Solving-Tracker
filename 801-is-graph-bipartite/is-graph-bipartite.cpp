class Solution {
public:

    bool DFS(int node, char c, vector<vector<int>> &graph, vector<bool> &visited, vector<char> &color) {

        visited[node] = true;
        color[node] = c;
        c = c == 'R' ? 'B' : 'R'; 

        for(int i=0; i<graph[node].size(); i++) {
            if(!visited[graph[node][i]]) {
                if(!DFS(graph[node][i],c,graph,visited,color))
                return 0;
            }
            else {
                if(color[node] == color[graph[node][i]])
                return 0;
            }
        }

        return 1;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        // here we are provided with the adjacency list
        int n = graph.size();
        vector<char> color(n);
        vector<bool> visited(n,false);

        for(int i=0; i<n; i++) {
            if(!visited[i] and !DFS(i,'R',graph,visited,color))
            return 0;
        }

        return 1;
    }
};