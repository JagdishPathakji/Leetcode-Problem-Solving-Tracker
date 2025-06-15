class Solution {
public:

    void find(int i, int j, vector<vector<int>> &grid, int &ans, int &maxi) {

        ans += grid[i][j];

        int temp = grid[i][j];
        grid[i][j] = 0;

        if(i+1 < grid.size() and grid[i+1][j] != 0) {
            find(i+1,j,grid,ans,maxi);
        }
        if(j+1 < grid[i].size() and grid[i][j+1] != 0) {
            find(i,j+1,grid,ans,maxi);
        }
        if(i-1 >= 0 and grid[i-1][j] != 0) {
            find(i-1,j,grid,ans,maxi);
        }
        if(j-1 >= 0 and grid[i][j-1] != 0) {
            find(i,j-1,grid,ans,maxi);
        }

        grid[i][j] = temp;
        maxi = max(maxi,ans);
        ans -= grid[i][j];
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int ans = 0;
        int maxi = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] != 0) {
                    find(i,j,grid,ans,maxi);
                    ans = 0;
                }
            }
        }

        return maxi;
    }
};