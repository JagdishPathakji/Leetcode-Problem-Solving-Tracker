class Solution {
public:

    int find(int index, vector<int> &coins, int amount, vector<vector<int>> &dp) {

        if(index <= 0) 
        return 0;

        if(amount == 0)
        return 1;

        if(dp[index][amount] != -1)
        return dp[index][amount];

        if(coins[index-1] > amount) // replacement for if(amount < 0) return 0;
        return dp[index][amount] = find(index-1,coins,amount,dp);
        else
        return dp[index][amount] = find(index,coins,amount-coins[index-1],dp) + find(index-1,coins,amount,dp);
    }

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        return find(n,coins,amount,dp);

    }
};