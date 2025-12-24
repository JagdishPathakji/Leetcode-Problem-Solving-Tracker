class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        
        vector<int> indegree(numCourses);
        vector<vector<int>> adjlist(numCourses);

        for(int i=0; i<preq.size(); i++) {
            int ai = preq[i][0];
            int bi = preq[i][1];

            adjlist[bi].push_back(ai);
            indegree[ai]++;
        }

        queue<int> q;
        vector<int> order;

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            order.push_back(node);

            for(int i=0; i<adjlist[node].size(); i++) {
                indegree[adjlist[node][i]]--;
                if(indegree[adjlist[node][i]]==0)
                q.push(adjlist[node][i]);
            }
        }

        if(order.size() == numCourses)
        return order;

        return {};
    }
};