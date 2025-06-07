class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int windowsize = k;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxWindowSize = 0;

        while(j < n) {

            if(nums[j] == 0) {
                windowsize--;
            }    
            
            while(windowsize < 0) {
                if(nums[i] == 0) {
                    windowsize++;
                }
                i++;
            }        
            
            maxWindowSize = max(maxWindowSize,j-i+1);
            j++;
        }

        return maxWindowSize;
    }
};