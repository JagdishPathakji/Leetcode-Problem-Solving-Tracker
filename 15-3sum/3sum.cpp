class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size(); i++) {
            if(i > 0 and nums[i] == nums[i-1]) continue; // skip the i if it is previously taken

            int j = i + 1;
            int k = nums.size()-1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j < k and nums[j] == nums[j+1]) j++;
                    j++;
                    while(j < k and nums[k] == nums[k-1]) k--;
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return ans;
    }
};