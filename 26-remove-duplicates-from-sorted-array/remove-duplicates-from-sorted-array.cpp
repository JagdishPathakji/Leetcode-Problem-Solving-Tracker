class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0;
        int j = 1;

        while(j < nums.size()) {
            while(j < nums.size() and nums[i] == nums[j])
            j++;

            if(j < nums.size()) {
                i++;
                swap(nums[i],nums[j]);
            }
            
            j++;
        }
       
        return i + 1;
    }
};