class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        int x = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                x++;
            }
            else {
                if(count < x) {
                    count = x;
                }
                x = 0;
            }
        }
        if(count < x) {
            count = x;
        }

        return count;
    }
};