class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int max = INT_MIN;
        int max2 = INT_MIN;

        int index = 0;
        for(int i=0; i<nums.size(); i++) {
            if(max < nums[i]) {
                max = nums[i];
                index = i;
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != max)   {
                if(max2 < nums[i]) {
                    max2 = nums[i];
                }
            }
        }


        if(max >= max2 * 2) {
            return index;
        }
        else {
            return -1;
        }
    }
};