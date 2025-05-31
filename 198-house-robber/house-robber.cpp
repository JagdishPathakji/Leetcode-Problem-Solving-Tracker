class Solution {
public:

    int houserobber(vector<int> &nums, int i, vector<int> &dp) {

        if(i >= nums.size()) return 0;

        if(dp[i] != -1)
        return dp[i];

        int steal = nums[i] + houserobber(nums,i+2,dp);
        int skip = houserobber(nums,i+1,dp);

        return dp[i] = max(steal,skip);
    }

    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
        return houserobber(nums,0,dp);

    }
};