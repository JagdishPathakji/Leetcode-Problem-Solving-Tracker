class Solution {
public:

    
    void DFS(int i, int j, vector<vector<int>> &grid, int &noOfOnes) {

        grid[i][j] = -1;
        noOfOnes++;

        if(i+1 < grid.size() && grid[i+1][j] == 1) 
        DFS(i+1,j,grid,noOfOnes);

        if(i-1 >= 0 and grid[i-1][j] == 1)
        DFS(i-1,j,grid,noOfOnes);

        if(j+1 < grid[i].size() and grid[i][j+1] == 1)
        DFS(i,j+1,grid,noOfOnes);

        if(j-1 >= 0 and grid[i][j-1] == 1)
        DFS(i,j-1,grid,noOfOnes);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 1) {
                    int noOfOnes = 0;
                    DFS(i,j,grid,noOfOnes);
                    ans = max(ans,noOfOnes);
                }
            }
        }

        return ans;


    }
};