class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            maxi = max(maxi,nums[i]);
        }

        int i = 0;
        int len = 0;
        int ans = 0;
        while(i < nums.size()) {
            if(nums[i] == maxi) {
                len++;
            }
            else {
                ans = max(ans,len);
                len = 0;
            }
            i++;
        }

        ans = max(ans,len);    
        return ans;
    }
};