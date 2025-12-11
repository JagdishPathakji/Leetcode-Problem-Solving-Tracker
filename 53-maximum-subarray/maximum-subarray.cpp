class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = nums[0];
        int currSum = nums[0];

        if(nums.size() == 1)
        return nums[0];

        for(int i=1; i<nums.size(); i++) {

            int curr = nums[i];
            if(curr <= curr + currSum) {
                currSum = currSum + nums[i];
            }
            else {
                currSum = nums[i];
            }

            maxSum = max(maxSum,currSum);
        }

        return maxSum;
    }
};