class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++)
        if(nums[i] == 0) nums[i] = -1;

        int prefixSum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;

        int maxLen = 0;
        for(int i=0; i<nums.size(); i++) {
            
            prefixSum += nums[i];

            if(mp.find(prefixSum) != mp.end())
            maxLen = max(maxLen,i-mp[prefixSum]);

            if(mp.find(prefixSum) == mp.end())
            mp[prefixSum] = i;
        }

        return maxLen;
    }
};