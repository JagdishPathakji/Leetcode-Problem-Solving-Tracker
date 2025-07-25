class Solution {
public:

    const int MOD = 1e9 + 7;
    int find(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp, long long int &ans) {

        if(dp[i][j] != -1)
        return dp[i][j];

        long long int myans = 1;
        if(i+1 < grid.size() && grid[i][j] < grid[i+1][j])
        myans += find(i+1,j,n,m,grid,dp,ans)%MOD;
        if(i-1 >= 0 && grid[i][j] < grid[i-1][j])
        myans += find(i-1,j,n,m,grid,dp,ans)%MOD;
        if(j+1 < grid[i].size() && grid[i][j] < grid[i][j+1])
        myans += find(i,j+1,n,m,grid,dp,ans)%MOD;
        if(j-1 >= 0 && grid[i][j] < grid[i][j-1])
        myans += find(i,j-1,n,m,grid,dp,ans)%MOD;

        ans = ans + myans;
        dp[i][j] = myans;
        return myans;
    }

    int countPaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        long long int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j] == -1)
                find(i,j,n,m,grid,dp,ans);
            }
        }
        
        return ans%MOD;
    }
};