class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        
        int sum = 0;
        for(int l=0; l<nums.size(); l++) {
            if(((l+k) < nums.size() and nums[l] > nums[k+l]) and ((l-k) >= 0 and nums[l] > nums[l-k])) {
                sum = sum + nums[l];
            }
            else if((l+k) >= nums.size() and (l-k) < 0) {
                sum = sum + nums[l];
            }
            else if((l+k) >= nums.size() and (l-k) >= 0) {
                if(nums[l] > nums[l-k]) {
                    sum = sum + nums[l];
                }
            }
            else if((l-k) < 0 and (l+k) < nums.size()) {
                if(nums[l] > nums[l+k]) {
                    sum = sum + nums[l];
                }
            }
        }

        return sum;
    }
};