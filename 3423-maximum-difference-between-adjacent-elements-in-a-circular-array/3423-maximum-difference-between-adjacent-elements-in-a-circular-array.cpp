class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int n = nums.size();
        int diff = -1000;

        int i = 0;
        int j = 1;
        int loop = n;

        while(loop--) {
            diff = max(abs(nums[j]-nums[i]),diff);
            i = (i+1)%n;
            j = (i+1)%n;
        }

        return diff;
    }
};