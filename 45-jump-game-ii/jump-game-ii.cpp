class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size() == 1)
        return 0;

        int step = 0;
        int target = nums.size()-1;
        int i = nums.size()-1;

        while(i >= 0) {
            
            int idx = target;
            while(i >= 0) {
                if((target-i) <= nums[i])
                idx = i;
                i--;
            }

            if(i >= 0 && nums[i] == 0) {
                i--;
                continue;
            }
            
            i = idx - 1;
            step++;
            target = idx;
        }

        return step;
    }
};