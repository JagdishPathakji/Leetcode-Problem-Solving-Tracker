class Solution {
public:

    int robbery(vector<int> &nums, int i, int n, vector<int> &dp) {
        if(i >= n) return 0;

        if(dp[i] != -1)
        return dp[i];

        int steal = nums[i] + robbery(nums,i+2,n,dp);
        int skip = robbery(nums,i+1,n,dp);

        return dp[i] = max(steal,skip);
    }

    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
        return nums[0];

        int n = nums.size();
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        
        return max(robbery(nums,0,n-1,dp1),robbery(nums,1,n,dp2));
    }
};