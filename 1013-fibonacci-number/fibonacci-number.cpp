class Solution {
public:

    int findfibo(int n, vector<int> &dp) {

        if(dp[n] != -1) return dp[n];

        return dp[n] = findfibo(n-1,dp) + findfibo(n-2,dp);
    }

    int fib(int n) {
        
        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;

        findfibo(n,dp);

        return dp[n];
    }
};