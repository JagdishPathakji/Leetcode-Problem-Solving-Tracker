class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        for(int i=0; i<richer.size(); i++) {
            int u = richer[i][0];
            int v = richer[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++) 
        ans[i] = i;

        queue<int> q;
        for(int i=0; i<n; i++) 
        if(indegree[i] == 0)
        q.push(i);

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int i=0; i<adj[node].size(); i++) {
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0)
                q.push(adj[node][i]);

                if(quiet[ans[adj[node][i]]] > quiet[ans[node]]) {
                    ans[adj[node][i]] = ans[node];
                }
            }
        }

        return ans;
    }
};