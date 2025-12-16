class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int count = 0;
        int n = nums.size();
        vector<int> ans(n);

        int i = 0;
        int j = 1;

        while(count < n) {

            if(i < n && nums[count] > 0) {
                ans[i] = nums[count];
                count++;
                i = i + 2;
            }

            if(j < n && nums[count] < 0) {
                ans[j] = nums[count];
                count++;
                j = j + 2;
            }
        }

        return ans;
        
    }
};