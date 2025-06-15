class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        
        int maxwindowsize = 0;
        unordered_map<int,int> mp;
        
        while(j < nums.size()) {

            mp[nums[j]]++;

            while(mp[nums[j]] > k and i < j) {
                mp[nums[i]]--;
                i++;
            }

            maxwindowsize = max(maxwindowsize,j-i+1);
            j++;
        }

        return maxwindowsize;
    }
};