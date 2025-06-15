class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;

        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(maxi < nums[i])
            maxi = nums[i];
        }

        long long count = 0;
        int maxelementoccurance = 0;

        while(j < nums.size()) {

            if(nums[j] == maxi) {
                maxelementoccurance++;
            }

            while(maxelementoccurance == k) {
                count += (nums.size()-j);
                if(nums[i] == maxi) {
                    maxelementoccurance--;
                }
                i++;
            }

            j++;
        }

        return count;
    }
};