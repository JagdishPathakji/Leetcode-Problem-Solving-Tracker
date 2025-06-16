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
        
        vector<int> dp1(cost.size()+1,-1);
        vector<int> dp2(cost.size()+1,-1);

        return min(find(0,cost,dp1),find(1,cost,dp2));        

    }
};