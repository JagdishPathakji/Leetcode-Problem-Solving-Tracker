class Solution {
public:

    void findpermutations(vector<int> &nums, int index, vector<int> &temp, vector<bool> &visited, vector<vector<int>> &ans) {

        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = 1;
                findpermutations(nums,i,temp,visited,ans);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        int index = 0;
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> visited(n,false);

        findpermutations(nums,index,temp,visited,ans);

        return ans;
    }
};