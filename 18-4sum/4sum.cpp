class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size()-1; i++) {
            if(i > 0 and nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<nums.size()-2; j++) {
                
                if(j > i + 1 and nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int l = nums.size()-1;

                while(k < l) {

                    long long int sum = 1LL * nums[i] + 1LL * nums[j] + 1LL * nums[k] + 1LL * nums[l];
                    if(sum == target) {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k < l and nums[k] == nums[k+1]) k++;
                        while(k < l and nums[l] == nums[l-1]) l--; 
                        k++;
                        l--;
                    }
                    else if(sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }

        return ans;

    }
};