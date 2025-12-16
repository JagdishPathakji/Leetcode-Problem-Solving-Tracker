class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        if(k == 0)
        return nums;

        int n = nums.size();
        vector<long long int> prefix(n+1,0);
        vector<long long int> suffix(n+1,0);

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] + nums[i];
        }


        // prefixsum and suffixsum are ready to use.
        vector<int> ans;
        for(int i=0; i<n; i++) {

            if(i-k >= 0 && i+k+1 <= n) {
                long long int sum = 0;
                if(i-k-1 < 0) {
                    sum = prefix[i];
                }
                else {
                    sum = prefix[i]-prefix[i-k-1];
                }
                sum += suffix[i+1]-suffix[i+k+1];
                ans.push_back(sum/(2*k+1));
            }
            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};