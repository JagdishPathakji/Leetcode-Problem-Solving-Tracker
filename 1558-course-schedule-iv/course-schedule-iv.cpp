class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adjlist(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjlist[u].push_back(v);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++) {
            for(int j=0; j<adjlist[i].size(); j++)
                indegree[adjlist[i][j]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0)
            q.push(i);
        }

        vector<vector<bool>> dependency(numCourses, vector<bool>(numCourses,false));
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int i=0; i<adjlist[node].size(); i++) {
                dependency[adjlist[node][i]][node] = 1;

                for(int j=0; j<numCourses; j++) {
                    if(dependency[node][j]) 
                    dependency[adjlist[node][i]][j] = 1;
                }

                indegree[adjlist[node][i]]--;
                if(indegree[adjlist[node][i]] == 0)
                q.push(adjlist[node][i]);
            }
        }

        vector<bool> result(queries.size(),false);
        for(int i=0; i<queries.size(); i++) {
            result[i] = dependency[queries[i][1]][queries[i][0]];
        }

        return result;
    }
};