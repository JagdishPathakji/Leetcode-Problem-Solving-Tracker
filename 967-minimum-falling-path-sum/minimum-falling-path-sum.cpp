class Solution {
public:

    int find(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

        if(dp[i][j] != -1)
        return dp[i][j];

        int mini = INT_MAX;

        if(i+1 < matrix.size() and j-1 >= 0)
        mini = min(mini,find(i+1,j-1,n,m,matrix,dp));
        if(i+1 < matrix.size())
        mini = min(mini,find(i+1,j,n,m,matrix,dp));
        if(i+1 < matrix.size() && j+1 < matrix[i].size())
        mini = min(mini,find(i+1,j+1,n,m,matrix,dp));

        if(mini != INT_MAX)
        return dp[i][j] = mini + matrix[i][j];
        else
        return dp[i][j] = matrix[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        if(n == 1 and m == 1)
        return matrix[0][0];

        vector<vector<int>> dp(n, vector<int>(m,0));
        
        for(int i=0; i<m; i++) {
            dp[n-1][i] = matrix[n-1][i];
        }

        int ans = INT_MAX;
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<m; j++) {
                int mini = INT_MAX;
                if(i+1 < matrix.size() and j-1 >= 0)
                mini = min(mini,dp[i+1][j-1]);
                if(i+1 < matrix.size())
                mini = min(mini,dp[i+1][j]);
                if(i+1 < matrix.size() && j+1 < matrix[i].size())
                mini = min(mini,dp[i+1][j+1]);

                if(mini == INT_MAX)
                dp[i][j] = matrix[i][j];
                else
                dp[i][j] = matrix[i][j] + mini;
                
                if(i == 0)
                ans = min(ans,dp[i][j]);
            }
        }

        return ans;
    }
};