class Solution {
public:

    long long getDescentPeriods(vector<int>& nums) {
        
        int i = 0;
        int j = 1;
        long long count = 0;

        while(j < nums.size()) {

            if(nums[j]+1 == nums[j-1]) {
                count+=(j-i);
                j++;
            }
            else {
                i = j;
                j++;
            }
        }

        return count+nums.size();
    }
};