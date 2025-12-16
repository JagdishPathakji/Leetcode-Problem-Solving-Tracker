class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        // convert all zeros to -1 (then find contiguous subarray with an equal number of 1 and -1)
        // this would be easy (calculate prefix sum -> wherever the prefixSum = 0, same number of 1 and -1 are obtained)

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0)
            nums[i] = -1;
        }

        int prefixSum = 0;
        int ans = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++) {
            prefixSum += nums[i];

            if(prefixSum == 0) {
                ans = i + 1;
            }

            if(mp.find(prefixSum) != mp.end()) {
                ans = max(ans,i-mp[prefixSum]);
            }
            

            // first && is optional
            if(mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i; // 1
            }
        }

        return ans;
    }
};