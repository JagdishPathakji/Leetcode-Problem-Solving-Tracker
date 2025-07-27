class Solution {
public:

    int find(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {

        if(i < 0 || j < 0 || i >= n || j >= m)
        return INT_MAX;

        if(dp[i][j] != -1)
        return dp[i][j];

        int ans1 = find(i+1,j,n,m,grid,dp);
        int ans2 = find(i,j+1,n,m,grid,dp);

        if(ans1 == INT_MAX && ans2 == INT_MAX)
        return dp[i][j] = grid[i][j];
        else
        return dp[i][j] = grid[i][j] + min(ans1,ans2);
    }   

    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return find(0,0,n,m,grid,dp);
    }
};