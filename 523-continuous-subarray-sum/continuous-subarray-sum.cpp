class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        if(nums.size() < 2)
        return false;
        
        unordered_map<int,int> mp;
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {

            sum += nums[i];

            if(sum % k == 0 && i > 0)
            return true;

            if(mp.find(sum%k) != mp.end()) {
                if(i-mp[sum%k] > 1)
                return true;
            }
            else {
                mp[sum%k] = i; 
            }
        }

        return false;
    }
};