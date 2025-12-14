class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // 1 -1 -1 0 0
        // 0  0 -9 3 1

        // 0 0 9 0 0

        // Solution - 1 (O(n) - TC and O(1) - SC)
        // int zeroFound = 0;
        // int mult = 0;

        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i] == 0) {
        //         if(zeroFound >= 1) {
        //             mult = 0;
        //             break;
        //         }
        //         zeroFound += 1;
        //     }
        //     else {
        //         if(mult == 0 && zeroFound <= 1)
        //         mult = 1;
        //         mult = mult * nums[i];
        //     }
        // }

        // if(zeroFound) {
        //     for(int i=0; i<nums.size(); i++) {
        //         if(nums[i] != 0) {
        //             nums[i] = 0;
        //         }
        //         else {
        //             nums[i] = mult;
        //         }
        //     }
        // }
        // else {
        //     for(int i=0; i<nums.size(); i++) {
        //         nums[i] = mult / nums[i];
        //     }
        // }

        // return nums;




        // Solution - 2 
        vector<int> prefixMul(nums.size());
        vector<int> suffixMul(nums.size());

        prefixMul[0] = 1;
        for(int i=1; i<nums.size(); i++) {
            prefixMul[i] = prefixMul[i-1] * nums[i-1];
        }

        suffixMul[nums.size()-1] = 1;
        for(int i=nums.size()-2; i>=0; i--) {
            suffixMul[i] = suffixMul[i+1] * nums[i+1];
        }

        for(int i=0; i<nums.size(); i++) {
            nums[i] = prefixMul[i] * suffixMul[i];
        }

        return nums;
    }
};