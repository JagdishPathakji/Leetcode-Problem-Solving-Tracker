class Solution {
public:

    int find(int index, vector<int> &cost, vector<int> &dp) {

        if(index >= cost.size()) {
            return 0;
        }

        if(dp[index] != -1)
        return dp[index];

        return dp[index] = cost[index] + min(find(index+1,cost,dp),find(index+2,cost,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp1(n+2,-1);
                
        dp1[n] = 0;
        dp1[n+1] = 0;

        for(int i=n-1; i>=0; i--) {
            dp1[i] = cost[i] + min(dp1[i+1],dp1[i+2]);
        }
        
        vector<int> dp2(n+2,-1);
     
        dp2[n] = 0;
        dp2[n+1] = 0;

        for(int i=n-1; i>=1; i--) {
            dp2[i] = cost[i] + min(dp2[i+1],dp2[i+2]);
        }

        return min(dp1[0],dp2[1]);

    }
};