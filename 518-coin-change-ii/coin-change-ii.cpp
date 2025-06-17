class Solution {
public:

    int find(int index, vector<int> &coins, int amount, vector<vector<int>> &dp) {

        if(index >= coins.size()) 
        return 0;

        if(amount < 0)
        return 0;

        if(amount == 0) return 1;

        if(dp[index][amount] != -1)
        return dp[index][amount];

        int takecurrent = find(index,coins,amount-coins[index],dp);
        int moveforward = find(index+1,coins,amount,dp);

        return dp[index][amount] = (takecurrent+moveforward);
    }

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        return find(0,coins,amount,dp);

    }
};