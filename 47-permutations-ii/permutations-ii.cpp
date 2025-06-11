class Solution {
public:

    void find(vector<int> &nums, int index, vector<vector<int>> &ans) {

        if(index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        vector<int> used(21,0);
        for(int i=index; i<nums.size(); i++) {
            if(!used[nums[i]+10]) {
                swap(nums[i],nums[index]);
                find(nums,index+1,ans);
                swap(nums[i],nums[index]);
                used[nums[i]+10] = true;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int index = 0;
        find(nums,index,ans);

        return ans;
    }
};