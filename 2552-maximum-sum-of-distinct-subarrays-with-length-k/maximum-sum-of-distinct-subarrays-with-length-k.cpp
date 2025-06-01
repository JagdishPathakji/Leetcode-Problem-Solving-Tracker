class Solution {
public:

    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long sum = 0;
        int n = nums.size();

        int i = 0;
        int j = 0;

        long long ans = 0;
        int windowlen = 0;

        unordered_map<int,int> mp;
        while(j < n) {
            
            mp[nums[j]]++;
            sum += nums[j];

            while(mp[nums[j]] > 1) {
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }

            if(j-i+1 == k) {
                ans = max(ans,sum);
                
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return ans;
    }
};