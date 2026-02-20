class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int prefixSum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1; // crazy logic😂

        for(int i=0; i<nums.size(); i++) {
            
            prefixSum += nums[i];

            if(mp.find(prefixSum%k) != mp.end()) {
                if(i-mp[prefixSum%k] >= 2)
                return true;
            }

            if(mp.find(prefixSum%k) == mp.end())
            mp[prefixSum%k] = i;
        }

        return false;
    }
};