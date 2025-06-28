class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int ans = 10000000;

        // -4 -1 1 2
        for(int i=0; i<nums.size(); i++) {

            int j = i + 1;
            int k = nums.size()-1;

            while(j < k) {

                if(nums[i] + nums[j] + nums[k] == target) {
                    return target;
                }
                else if(nums[i] + nums[j] + nums[k] > target) {
                    int diff = abs(target - (nums[i]+nums[j]+nums[k]));
                    int currdiff = abs(ans-target);
                    if(diff < currdiff) {
                        ans = nums[i]+nums[j]+nums[k];
                    }
                    k--;
                }
                else {
                    int diff = abs(target - (nums[i]+nums[j]+nums[k]));
                    int currdiff = abs(ans-target);
                    if(diff < currdiff) {
                        ans = nums[i]+nums[j]+nums[k];
                    }
                    j++;
                }
            }
        }

        return ans;
    }
};