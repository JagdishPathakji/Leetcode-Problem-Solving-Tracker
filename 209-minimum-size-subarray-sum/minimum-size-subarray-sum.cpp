class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int len = INT_MAX;
        int n = nums.size();
        int sum = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            
            if(sum < target) {
                sum += nums[j];
            }

            if(sum >= target) {
                len = min(len,j-i+1);

                sum -= nums[i];
                i++;
            }

            if(sum < target) {
                j++;
            }
        }

        if(len == INT_MAX) return 0;
        
        return len;
    }
};