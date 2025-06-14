class Solution {
public:

    void find(int index, vector<int> &nums, vector<int> &temp, set<vector<int>> &ans) {

        if(index >= nums.size()) {
            if(temp.size() >= 2) {
                ans.insert(temp);
            }
            return;
        }

        if(temp.size() >= 2) {
            ans.insert(temp);
        }

        if(temp.empty() or temp.back() <= nums[index]) {
            temp.push_back(nums[index]);
            find(index+1,nums,temp,ans);
            temp.pop_back();
        }

        find(index+1,nums,temp,ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int> temp;
        set<vector<int>> ans;
        int index = 0;

        find(index,nums,temp,ans);

        vector<vector<int>> realans(ans.begin(),ans.end());
        return realans;
    }
};