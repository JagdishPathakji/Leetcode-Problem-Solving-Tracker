class Solution {
public:

    int findfibo(int n, vector<int> &dp) {
        
        if(n <= 1) {
            return n;
        }

        if(dp[n] != -1) 
        return dp[n];

        return dp[n] = findfibo(n-1,dp) + findfibo(n-2,dp);
    }

    int fib(int n) {

        vector<int> dp(n+1,-1);
        return findfibo(n,dp);
    }
};