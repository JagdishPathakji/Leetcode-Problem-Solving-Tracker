class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {

        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses);

        for(int i=0; i<preq.size(); i++) {
            int ai = preq[i][0];
            int bi = preq[i][1];

            adjlist[bi].push_back(ai);
            indegree[ai]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            count++;

            for(int i=0; i<adjlist[node].size(); i++) {
                indegree[adjlist[node][i]]--;
                if(indegree[adjlist[node][i]]==0)
                q.push(adjlist[node][i]);
            }
        }

        return count == numCourses;
    }
};