class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        // Reverse topological sort
        int n = graph.size();
        vector<int> outdegree(n,0);

        vector<int> ans;
        for(int i=0; i<n; i++) {
            outdegree[i] = graph[i].size();
        }

        vector<vector<int>> adjlist(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                adjlist[graph[i][j]].push_back(i);
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(outdegree[i] == 0) 
            q.push(i);
        }

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            ans.push_back(node);

            for(int i=0; i<adjlist[node].size(); i++) {
                outdegree[adjlist[node][i]]--;
                if(outdegree[adjlist[node][i]] == 0)
                q.push(adjlist[node][i]);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};