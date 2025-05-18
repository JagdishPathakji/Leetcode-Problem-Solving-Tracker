class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> adjlist(n);
        for(int i=0; i<relations.size(); i++) {
            int u = relations[i][0];
            int v = relations[i][1];

            adjlist[u-1].push_back(v-1);
        }

        vector<int> indegree(n,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<adjlist[i].size(); j++) {
                indegree[adjlist[i][j]]++;
            }
        }

        vector<int> PreviousTime(n,0);
        queue<int> q;

        for(int i=0; i<n; i++) {
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int i=0; i<adjlist[node].size(); i++) {
                indegree[adjlist[node][i]]--;
                if(indegree[adjlist[node][i]] == 0)
                q.push(adjlist[node][i]);

                PreviousTime[adjlist[node][i]] = max(PreviousTime[adjlist[node][i]],time[node]+PreviousTime[node]);
            }
        }

        for(int i=0; i<n; i++) {
            time[i] += PreviousTime[i];
        }

        int max = INT_MIN;
        for(int i=0; i<n; i++) {
            if(max < time[i])
            max = time[i];
        }

        return max;
    }
};