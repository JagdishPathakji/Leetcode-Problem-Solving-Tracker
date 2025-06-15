class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long count = 0;

        int i = 0;
        int j = 0;
        long long sum = 0;

        while(j < nums.size()) {

            sum += nums[j];

            while(1LL * sum*(j-i+1) >= k and i < j) {
                sum -= nums[i];
                i++;
            }

            if(1LL * sum * (j-i+1) < k) {
                count+=(j-i+1);
            }

            j++;
        }

        return count;
    }
};