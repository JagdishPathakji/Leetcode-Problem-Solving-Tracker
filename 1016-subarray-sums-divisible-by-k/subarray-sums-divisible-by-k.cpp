class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int prefixSum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        int count = 0;
        for(int i=0; i<nums.size(); i++) {

            prefixSum += nums[i];
            int rem = prefixSum % k;

            // to handle negative remainders
            // run test case : [-1,2,9] k = 2 for checking why ??
            if(rem < 0) rem += k;

            if(mp.find(rem) != mp.end())
            count+=mp[rem];

            mp[rem]++;
        }

        return count;
    }
};