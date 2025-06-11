class Solution {
public:

    /*
    void findpermutations(vector<int> &nums, vector<int> &temp, vector<bool> &visited, vector<vector<int>> &ans) {

        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = 1;
                findpermutations(nums,temp,visited,ans);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }
    */

    void find(vector<int> &nums, vector<vector<int>> &ans, int index) {
        

        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++) {
            swap(nums[index],nums[i]);
            find(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        /*
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> visited(n,false);

        findpermutations(nums,temp,visited,ans);

        return ans;
        */

        int n = nums.size();    
        vector<vector<int>> ans;
        int index = 0;
        find(nums,ans,index);

        return ans;
    }
};