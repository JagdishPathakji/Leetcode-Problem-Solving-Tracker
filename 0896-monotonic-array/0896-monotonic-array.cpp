class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool m1 = true;
        bool m2 = true;

        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] < nums[i+1]) {
                m1 = false;
            }
            else if(nums[i] > nums[i+1]) {
                m2 = false;
            }
        }

        return m1 or m2;
    }
};