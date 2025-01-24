class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int i = 0;
        int n  = nums.size();
        while(i < n-1) {
            if(nums[i] == nums[i+1]) {
                i = i + 3; 
            }
            else {
                return nums[i];
            }
        }   

        return nums[n-1];
    }
};