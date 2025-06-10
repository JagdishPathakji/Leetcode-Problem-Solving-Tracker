class Solution {
public:
    
    void findsubsets(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> temp) {
        
        if(index >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        findsubsets(nums,index+1,ans,temp);
        temp.pop_back();
        findsubsets(nums,index+1,ans,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        int index = 0;
        vector<int> temp;
        findsubsets(nums,index,ans,temp);

        return ans;  
        
    }
};