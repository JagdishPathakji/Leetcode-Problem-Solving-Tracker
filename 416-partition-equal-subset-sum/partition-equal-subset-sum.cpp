class Solution {
public:

    bool find(int index, int sum, int total, vector<int>&nums, vector<vector<int>> &dp) {

        if(index >= nums.size())
        return 0;

        if(dp[index][total] != -1)
        return dp[index][total];

        if(sum == total)
        return dp[index][total] = 1;

        return dp[index][total] = find(index+1,sum+nums[index],total-nums[index],nums,dp) or find(index+1,sum,total,nums,dp);
    }   

    bool canPartition(vector<int>& nums) {
        
        int total = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++) 
        total += nums[i];

        vector<vector<int>> dp(n+1,vector<int>(total+1,-1));
        return find(0,0,total,nums,dp);
    }
};