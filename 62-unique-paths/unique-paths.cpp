class Solution {
public:

    int find(int i, int j, int n, int m, vector<vector<int>> &dp) {

        if(i == n-1 and j == m-1)
        return 1;

        if(i < 0 || j < 0 || i >= n || j >= m)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = find(i,j+1,n,m,dp) + find(i+1,j,n,m,dp);
    }

    int uniquePaths(int n, int m) {
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return find(0,0,n,m,dp);
    }
};