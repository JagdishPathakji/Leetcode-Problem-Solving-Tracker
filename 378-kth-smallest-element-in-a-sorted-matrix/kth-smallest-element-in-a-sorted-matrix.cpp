class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({matrix[0][0],{0,0}});
        vector<vector<int>> visited(rows, vector<int> (cols,false));

        int ans;
        int i,j;

        int x[4] = {0,0,1,-1};
        int y[4] = {1,-1,0,0};

        while(k--) {
            
            auto node = pq.top();
            pq.pop();

            ans = node.first;
            i = node.second.first;
            j = node.second.second;

            visited[i][j] = true;

            for(int k=0; k<4; k++) {
                if(x[k]+i >= 0 && x[k]+i < rows && y[k]+j >= 0 && y[k]+j < cols && !visited[x[k]+i][y[k]+j]) {
                    visited[x[k]+i][y[k]+j] = true;
                    pq.push({matrix[x[k]+i][y[k]+j],{x[k]+i,y[k]+j}});
                }
            }
        }

        return ans;
    }
};