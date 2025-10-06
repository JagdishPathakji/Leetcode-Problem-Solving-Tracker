class Solution {
public:

    // void DFS(int node, vector<bool> &visited, vector<vector<int>> &adj, int curr, int &depth) {

    //     visited[node] = true;
    //     for(int i=0; i<adj[node].size(); i++) {
    //         if(!visited[adj[node][i]]) {
    //             DFS(adj[node][i],visited,adj,curr+1,depth);
    //             depth = max(depth,curr);
    //         }
    //     }
    // }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return {0};

        // vector<int> ans;
        vector<vector<int>> adj(n);
        // for(int i=0; i<edges.size(); i++) {
        //     int u = edges[i][0];
        //     int v = edges[i][1];

        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        // for(int i=0; i<n; i++) {
        //     vector<bool> visited(n,false);
        //     int depth = 0;
        //     DFS(i,visited,adj,0,depth);
        //     ans.push_back(depth);    
        // }

        // int min = ans[0];
        // for(int i=0; i<ans.size(); i++) {
        //     if(min > ans[i])
        //     min = ans[i];
        // }

        // vector<int> final;
        // for(int i=0; i<ans.size(); i++) {
        //     if(ans[i] == min) {
        //         final.push_back(i);
        //     }
        // }

        // return final;


        // Kahn's algorithm
        vector<int> indegree(n,0);

        for(int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

        queue<int> q;
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }

        int nodes = n;
        while(nodes > 2) {

            int size = q.size();
            nodes -= size;
            
            while(size--) {

                int node = q.front();
                q.pop();

                for(int i=0; i<adj[node].size(); i++) {
                    indegree[adj[node][i]]--;

                    if(indegree[adj[node][i]] == 1)
                    q.push(adj[node][i]);
                }
            }
        }

        if(q.size() == 1)
        return {q.front()};

        int first = q.front();
        q.pop();
        
        return {first,q.front()};

    }
};