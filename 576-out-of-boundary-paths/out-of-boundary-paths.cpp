class Solution {
public:

    const int MOD = 1e9 + 7;
    long long int find(int i, int j, int max, int n, int m, vector<vector<vector<int>>> &dp) {

        if(i >= n || j >= m) {
            return 1;
        }

        if(i < 0 || j < 0) {
            return 1;
        }

        if(max == 0) {
            return 0;
        }

        if(dp[i][j][max] != -1) {
            return dp[i][j][max];
        }

        long long int total = find(i+1,j,max-1,n,m,dp);
        total += find(i,j+1,max-1,n,m,dp);
        total += find(i-1,j,max-1,n,m,dp);
        total += find(i,j-1,max-1,n,m,dp);
        return dp[i][j][max] = total%MOD;
    }

    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(maxMove+1,-1)));
        return find(startRow,startColumn,maxMove,n,m,dp);
    }
};