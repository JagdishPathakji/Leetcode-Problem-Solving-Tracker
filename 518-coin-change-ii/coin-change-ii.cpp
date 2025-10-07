class Solution {
public:


    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<long long int>> dp(n+1,vector<long long int>(amount+1,0));

        // if(amount == 0) return 1;
        for(int i=0; i<=n; i++)
        dp[i][0] = 1;
        
        // if(index <= 0) automatically handled as dp is initialised with zero.

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                if(coins[i-1] > j)
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = int(dp[i][j-coins[i-1]] + dp[i-1][j]);
            }
        }

        return (int)dp[n][amount];
    }
};