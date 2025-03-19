class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int pos = 0; // Points to the position where the next non-zero element should be placed

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }

        // Fill remaining positions with zeros
        while (pos < n) {
            nums[pos++] = 0;
        }
    }
};