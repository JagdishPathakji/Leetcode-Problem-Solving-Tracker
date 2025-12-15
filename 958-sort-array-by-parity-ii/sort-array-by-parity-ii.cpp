class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int i = 0;
        int j = 1;

        while(i < nums.size() && j < nums.size()) {


            while(i < nums.size() && nums[i]%2 == 0) {
                i+=2;
            }


            while(j < nums.size() && nums[j]%2 == 1) {
                j+=2;
            }

            if(j < nums.size() && i < nums.size())
            swap(nums[i],nums[j]);
        }

        return nums;
        
    }
};