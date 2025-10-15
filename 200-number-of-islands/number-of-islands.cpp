class Solution {
public:

    int x[4] = {0,0,1,-1};
    int y[4] = {1,-1,0,0};

    void DFS(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited) {

        visited[i][j] = true;

        for(int k=0; k<4; k++) {
            if(i+x[k] < grid.size() && j+y[k] < grid[0].size()) {
                if(!visited[i+x[k]][j+y[k]] && grid[i+x[k]][j+y[k]] == '1')
                DFS(i+x[k],j+y[k],grid,visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
       
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int count = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    DFS(i,j,grid,visited);
                    count++;
                }
            }
        }

        return count;
    }
};