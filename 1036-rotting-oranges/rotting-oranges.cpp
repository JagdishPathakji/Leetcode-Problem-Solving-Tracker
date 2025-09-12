class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int timer = 0;
        vector<vector<bool>> visited(row, vector<bool>(col,false));
        queue<pair<int,pair<int,int>>> q;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 2) {
                    visited[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()) {

            int size = q.size();
            while(size--) {

                auto node = q.front();
                q.pop();

                int i = node.second.first;
                int j = node.second.second;

                int time = node.first;
                timer = max(time,timer);
                visited[i][j] = 1;

                if(i-1 >= 0 and !visited[i-1][j] and grid[i-1][j] == 1) {
                    visited[i-1][j] = 1;
                    grid[i-1][j] = 2;
                    q.push({time+1,{i-1,j}});
                }

                if(j-1 >= 0 and !visited[i][j-1] and grid[i][j-1] == 1) {
                    visited[i][j-1] = 1;
                    grid[i][j-1] = 2;
                    q.push({time+1,{i,j-1}});
                }

                if(i+1 < grid.size() and !visited[i+1][j] and grid[i+1][j] == 1) {
                    visited[i+1][j] = 1;
                    grid[i+1][j] = 2;
                    q.push({time+1,{i+1,j}});
                }

                if(j+1 < grid[i].size() and !visited[i][j+1] and grid[i][j+1] == 1) {
                    visited[i][j+1] = 1;
                    grid[i][j+1] = 2;
                    q.push({time+1,{i,j+1}});
                }
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 1)
                return -1;
            }
        }

        return timer;
    }
};