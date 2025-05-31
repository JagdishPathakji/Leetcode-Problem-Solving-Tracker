class Solution {
public:

    int rob(vector<int>& nums) {

        if(nums.size() == 0)
        return nums[0];

        int n = nums.size();
        // dp[i] = max stolen money still i th house
        int one = 0; // when i have robbed zero houses, then ofcourse the total money robbed till now is zero
        int two = nums[0]; // when i have robbed 1st house, maxm money i can rob is nums[0]

        for(int i=2; i<=n; i++) {
            int steal = nums[i-1] + one;
            int skip = two;
            int curr = max(steal,skip);

            one = two;
            two = curr;
        }

        return two;
    } 
};