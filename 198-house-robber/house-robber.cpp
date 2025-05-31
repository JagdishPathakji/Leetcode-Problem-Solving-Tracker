class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n+1);
        // dp[i] = max stolen money still i th house
        dp[0] = 0; // when i have robbed zero houses, then ofcourse the total money robbed till now is zero
        dp[1] = nums[0]; // when i have robbed 1st house, maxm money i can rob is nums[0]

        for(int i=2; i<=n; i++) {
            int steal = nums[i-1] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(steal,skip);
        }

        return dp[n];
    } 
};