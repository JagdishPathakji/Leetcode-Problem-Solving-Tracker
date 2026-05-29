class Solution {
public:
    int minElement(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++) {

            int num = nums[i];
            int c = 0;
            while(num > 0) {
                int p = num % 10;
                c = c + p;
                num =  num / 10;
            }
            nums[i] = c;
        }

        sort(nums.begin(),nums.end());
        return nums[0];
    }
};