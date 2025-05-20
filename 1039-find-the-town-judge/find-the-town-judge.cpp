class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n,0);
        vector<int> outdegree(n,0);

        for(int i=0; i<trust.size(); i++) {
            int u = trust[i][0];
            int v = trust[i][1];

            indegree[v-1]++;
            outdegree[u-1]++;
        }

        for(int i=0; i<n; i++) {
            if(indegree[i] == n-1 and outdegree[i] == 0)
            return i+1;
        }

        return -1;
    }
};