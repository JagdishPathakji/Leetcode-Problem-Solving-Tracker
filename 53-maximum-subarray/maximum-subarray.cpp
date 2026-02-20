class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int prefixSum = 0;
        int maxAns = INT_MIN;

        for(int i=0; i<nums.size(); i++) {

            prefixSum += nums[i];

            maxAns = max(maxAns,prefixSum);
            if(prefixSum < 0) {
                prefixSum = 0;
            }
        }

        return maxAns;
    }
};