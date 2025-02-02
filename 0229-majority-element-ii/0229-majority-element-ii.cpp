class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        if(nums.size() == 1) {
            return nums;
        }

        vector<int> v;
        int count = 1;
        sort(nums.begin(),nums.end());
        int prev = nums[0];


        for(int i=1; i<nums.size(); i++) {
            if(prev == nums[i]) {
                count++;
            }
            else {
                if(count > nums.size()/3) {
                    v.push_back(prev);
                    prev = nums[i];
                    count = 1;
                }
            }
        }
        if(count > nums.size()/3) {
            v.push_back(prev);
        }

        return v;

    }
};