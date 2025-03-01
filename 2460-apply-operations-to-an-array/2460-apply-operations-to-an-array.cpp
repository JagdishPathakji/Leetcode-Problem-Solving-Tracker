class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        vector<int> v;

        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }   
        
        for(int i=nums.size()-1; i>0; i--) {
            if(nums[i-1] == 0) {
                swap(nums[i],nums[i-1]);
            }
        }

        return nums;
    }
};