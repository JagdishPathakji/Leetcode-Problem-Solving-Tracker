class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        
        vector<int> adjlist[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i=0; i<preq.size(); i++) {
            int u = preq[i][0];
            int v = preq[i][1];

            adjlist[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == 0) 
            q.push(i);
        }

        int count = 0;
        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            count++;
            for(int i=0; i<adjlist[node].size(); i++) {
                indegree[adjlist[node][i]]--;

                if(indegree[adjlist[node][i]] == 0)
                q.push(adjlist[node][i]);
            }
        }

        return count == numCourses;
    }
};