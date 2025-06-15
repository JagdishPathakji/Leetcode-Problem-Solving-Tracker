class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;

        int count = 0;
        long long product = 1;
        while(j < nums.size()) {

            product *= nums[j];

            while(product >= k and i < j) {
                product /= nums[i];
                i++;
            }

            if(product < k) {
                count += (j-i+1);
            }

            j++;
        }

        return count;
    }
};