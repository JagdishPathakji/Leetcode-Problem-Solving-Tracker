class Solution {
public:

    int find(int i, int j, int n, int m, vector<vector<int>> &dp, vector<vector<int>> &grid) {

        if(i == n-1 and j == m-1)
        return 1;

        if(i < 0 || j < 0 || i >= n || j >= m)
        return 0;

        if(grid[i][j] == 1)
        return dp[i][j] = 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = find(i,j+1,n,m,dp,grid) + find(i+1,j,n,m,dp,grid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1)
        return 0;

        int n = grid.size();
        int m = grid[0].size();

        if(grid[n-1][m-1] == 1)
        return 0;

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return find(0,0,n,m,dp,grid);

    }
};