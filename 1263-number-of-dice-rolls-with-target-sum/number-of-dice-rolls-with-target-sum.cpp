class Solution {
public:

    const int MOD = 1e9 + 7;
    int dp[31][1001];

    int find(int level, int sum, int n, int k, int target) {

        if(level > n || sum > target) 
        return 0;

        if(level == n) {
            return sum == target ? 1:0;
        }

        if(dp[level][sum] != -1)
        return dp[level][sum];

        int count = 0;
        for(int i=1; i<=k; i++) {
            count = (count+find(level+1,sum+i,n,k,target))%MOD;
        }

        return dp[level][sum] = count;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,n,k,target);
    }
};