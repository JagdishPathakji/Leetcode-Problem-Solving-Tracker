class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjlist(n);
        vector<int> indegree(n,0);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjlist[u].push_back(v);
            indegree[v]++;
        }
        
        vector<set<int>> s(n);
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i=0; i<adjlist[node].size(); i++) {
                indegree[adjlist[node][i]]--;

                s[adjlist[node][i]].insert(node);
                s[adjlist[node][i]].insert(s[node].begin(),s[node].end());
                
                if(indegree[adjlist[node][i]] == 0) {
                    q.push(adjlist[node][i]);
                }
            }
        }   

        vector<vector<int>> ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = vector<int>(s[i].begin(),s[i].end());
        }

        return ans;
    }
};