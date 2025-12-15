class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int prefixSum = 0;
        unordered_map<int,int> mp;

        int total = 0;
        for(int i=0; i<nums.size(); i++) {

            prefixSum += nums[i];

            if(prefixSum == goal) {
                total++;
            }

            if(mp.find(prefixSum-goal) != mp.end()) {
                total += mp[prefixSum-goal];
            }

            mp[prefixSum]++;
        }

        return total;
    }
};