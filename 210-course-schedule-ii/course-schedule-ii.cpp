class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;

        for(int i=0; i<prerequisites.size(); i++) {

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjlist[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty()) {

            auto node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i=0; i<adjlist[node].size(); i++) {
                indegree[adjlist[node][i]]--;
                if(indegree[adjlist[node][i]] == 0)
                q.push(adjlist[node][i]);
            }
        }

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] != 0)
            return {};
        }

        return ans;
    }
};