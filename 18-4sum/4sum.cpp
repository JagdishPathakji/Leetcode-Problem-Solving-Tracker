class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>> s;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size()-2; j++) {

                int k = j + 1;
                int l = nums.size()-1;
                while(k < l) {

                    long long int sum = 1LL * nums[i] + 1LL * nums[j] + 1LL * nums[k] + 1LL * nums[l];
                    if(sum == target) {
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                    }

                    if(sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }

        vector<vector<int>> ans(s.begin(),s.end());
        return ans;

    }
};