class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int prefixSum = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++) {

            prefixSum += nums[i];
            
            int rem = prefixSum  % k;
            if(rem < 0)
            rem += k;

            if(rem == 0) {
                if(i > 0)
                return true;
            }

            if(mp.find(rem) != mp.end()) {
                if(i-mp[rem] > 1)
                return true;
            }

            if(mp.find(rem) == mp.end()) {
                mp[rem] = i;
            }
        }

        return false;
    }
};