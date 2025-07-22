class Solution {
public:

    int find(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp, int &maxi) {
    
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return 0;
        }

        if(dp[i][j] != -1) 
        return dp[i][j];     

        int first = 0,second = 0,third = 0,fourth = 0;
        if(i+1 < n && matrix[i+1][j] > matrix[i][j]) {
            first = find(i+1,j,n,m,matrix,dp,maxi);
        }
        if(i-1 >= 0 && matrix[i-1][j]  > matrix[i][j]) {
            second = find(i-1,j,n,m,matrix,dp,maxi);
        }
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) {
            third = find(i,j-1,n,m,matrix,dp,maxi);
        }
        if(j+1 < m && matrix[i][j+1] > matrix[i][j]) {
            fourth = find(i,j+1,n,m,matrix,dp,maxi);
        }
        
        dp[i][j] = 1 + max({first,second,third,fourth});
        maxi = max(maxi,dp[i][j]);
        
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int max = 1; 

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j] == -1) {
                    find(i,j,n,m,matrix,dp,max);
                }
            }
        }

        return max;
    }
};