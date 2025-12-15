class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int prefixSum = 0;
        int total = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++) {

            prefixSum += nums[i];

            if(prefixSum == k) 
            total++;

            int target = prefixSum - k;
            if(mp[target] >= 1)
            total += mp[target];

            mp[prefixSum]++;
        }

        return total;
    }
};