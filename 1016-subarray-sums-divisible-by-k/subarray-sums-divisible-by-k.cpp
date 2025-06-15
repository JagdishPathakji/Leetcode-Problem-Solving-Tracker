class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int sum = 0;
        unordered_map<int,int> mp;
        int count = 0;

        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if(rem < 0) rem += k;

            if(sum%k == 0) {
                count++;
            }
            if(mp[rem] > 0) {
                count += mp[rem];
            }
            mp[rem]++;
        }

        return count;
    }
};