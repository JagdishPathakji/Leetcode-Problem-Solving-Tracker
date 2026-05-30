class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        int m = graph[0].size();

        vector<bool> visited(n,false);
        vector<char> color(n);
        
        queue<int> q;
        for(int i=0; i<n; i++) {

            if(!visited[i]) {

                q.push(i);
                visited[i] = true;
                color[i] = 'R';

                while(!q.empty()) {
                    auto node = q.front();
                    q.pop();

                    for(int j=0; j<graph[node].size(); j++) {
                        if(visited[graph[node][j]] == true && color[graph[node][j]] == color[node])
                        return false;

                        if(visited[graph[node][j]])
                        continue;

                        visited[graph[node][j]] = true;

                        if(color[node] == 'R')
                        color[graph[node][j]] = 'B';
                        else if(color[node] == 'B')
                        color[graph[node][j]] = 'R';

                        q.push(graph[node][j]);
                    }
                }
            }
        }

        return true;

    }
};