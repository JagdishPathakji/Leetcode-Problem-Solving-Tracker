class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int zeroFound = 0;
        int mult = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                if(zeroFound >= 1) {
                    mult = 0;
                    break;
                }
                zeroFound += 1;
            }
            else {
                if(mult == 0 && zeroFound <= 1)
                mult = 1;
                mult = mult * nums[i];
            }
        }

        if(zeroFound) {
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] != 0) {
                    nums[i] = 0;
                }
                else {
                    nums[i] = mult;
                }
            }
        }
        else {
            for(int i=0; i<nums.size(); i++) {
                nums[i] = mult / nums[i];
            }
        }

        return nums;
    }
};