class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int prefix = 0;
        for(int i=0; i<nums.size(); i++) {
            if(prefix >= 0) {
                prefix += nums[i];
            }
            else {
                prefix = nums[i];
            }

            maxi = max(maxi,prefix);
        }

        return maxi;
    }
};