class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int rows = coins.size();
        int cols = amount;
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,INT_MAX-1));

        for(int i=0; i<=rows; i++)
        dp[i][0] = 0;

        for(int i=1; i<=rows; i++) {
            for(int j=1; j<=cols; j++) {
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }

        return dp[rows][cols] != INT_MAX-1 ? dp[rows][cols] : -1;
    }
};